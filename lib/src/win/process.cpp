#include "win/process.h"

namespace mol {
	 

SACL::SACL(LPVOID sd, bool inherit )
{
	nLength = sizeof(SECURITY_ATTRIBUTES);
	lpSecurityDescriptor = sd;
	bInheritHandle = inherit ? TRUE : FALSE;
}


Pipe::Pipe()
	: hStdIn_(INVALID_HANDLE_VALUE), hStdOut_(INVALID_HANDLE_VALUE)
{}

Pipe::~Pipe()
{
	close();
}

bool Pipe::create(bool inheritHandles)
{
	SACL sacl(0,inheritHandles);
	return ::CreatePipe(&hStdIn_, &hStdOut_, &sacl, 0) != 0;
}

void Pipe::noStdInInherit()
{
	::SetHandleInformation( hStdIn_, HANDLE_FLAG_INHERIT, 0);
}

void Pipe::noStdOutInherit()
{
	::SetHandleInformation( hStdOut_, HANDLE_FLAG_INHERIT, 0);
}

void Pipe::close()
{
	closeStdIn();
	closeStdOut();
}

void Pipe::closeStdIn()
{
	if ( hStdIn_ !=  INVALID_HANDLE_VALUE)
	{
		::CloseHandle(hStdIn_);
		hStdIn_ = INVALID_HANDLE_VALUE;
	}
}

void Pipe::closeStdOut()
{
	if ( hStdOut_ != INVALID_HANDLE_VALUE)
	{
		::CloseHandle(hStdOut_);
		hStdOut_ = INVALID_HANDLE_VALUE;
	}
}

HANDLE& Pipe::stdIn()  
{ 
	return hStdIn_;  
}

HANDLE& Pipe::stdOut() 
{ 
	return hStdOut_; 
}


/////////////////////////////////////////////////////////////////////////////

PipedProcessWriterAction::PipedProcessWriterAction()
:pp_(0)
{}

PipedProcessWriterAction::PipedProcessWriterAction(PipedProcess* pp, const std::string& line)
: pp_(pp), line_(line)
{}

void PipedProcessWriterAction::operator()()
{
	if ( pp_ )
		pp_->writeLineToProcessStdIn(line_);
}

/////////////////////////////////////////////////////////////////////////////


PipedProcess::PipedProcess()
	: commandline_(0),async_(false),eSuspendThreadQueue_(false)
{
	::ZeroMemory( &piProcInfo_, sizeof(PROCESS_INFORMATION) );

	piProcInfo_.hProcess = INVALID_HANDLE_VALUE;
	piProcInfo_.hThread  = INVALID_HANDLE_VALUE;

	writeEOF_ = false;
	readEOF_  = false;
	errEOF_   = false;

	readyState_ = INITIALIZED;
}

PipedProcess::~PipedProcess()
{
	close();
	writerQueue_.cancel();

	ODBGS("~PipedProcess");
}

void PipedProcess::close()
{
	ODBGS("PipedProcess::close()");
	{
		LOCK(mReadyState_)
		if ( readyState_ == RUNNING )
			return;
	}

	eSuspendThreadQueue_.reset();

	delete[] commandline_;
	commandline_ = 0;

	listStdErr_.clear();
	listStdIn_ .clear();

	if ( piProcInfo_.hProcess != INVALID_HANDLE_VALUE)
	{
		::CloseHandle(piProcInfo_.hProcess);
		piProcInfo_.hProcess = INVALID_HANDLE_VALUE;
	}
	if ( piProcInfo_.hThread != INVALID_HANDLE_VALUE)
	{
		::CloseHandle(piProcInfo_.hThread);
		piProcInfo_.hThread = INVALID_HANDLE_VALUE;
	}
	errorPipe_.close();
	readPipe_.close();
	writePipe_.close();

	writeEOF_ = false;
	readEOF_  = false;
	errEOF_   = false;

	LOCK(mReadyState_)
		readyState_ = INITIALIZED;
}

PipedProcess::READYSTATE PipedProcess::readyState()
{
	LOCK(mReadyState_);
	return readyState_;
}

void PipedProcess::async(bool b)
{
	async_ = b;
}

bool PipedProcess::eof()		
{ 
	return listStdIn_.size()  > 0 ? 0 : readEOF_; 
}

bool PipedProcess::err_eof()  
{ 
	return listStdErr_.size() > 0 ? 0 : errEOF_;  
}

bool PipedProcess::create( const std::wstring& cmdline )
{
	ODBGS("PipedProcess::create()");

	// reset

	close();
	{
		LOCK(mReadyState_)
		if ( readyState_ != INITIALIZED )
			return false;

		readyState_ = RUNNING;
	}

	// create pipes

	readPipe_.create(true);
	writePipe_.create(true);
	errorPipe_.create(true);

	readPipe_.noStdInInherit();
	writePipe_.noStdOutInherit();
	errorPipe_.noStdInInherit();

	// create process
	STARTUPINFO siStartInfo;

	::ZeroMemory( &piProcInfo_, sizeof(PROCESS_INFORMATION) );
	::ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );

	siStartInfo.cb = sizeof(STARTUPINFO); 
	siStartInfo.hStdError  = errorPipe_.stdOut();  
	siStartInfo.hStdOutput = readPipe_.stdOut(); 
	siStartInfo.hStdInput  = writePipe_.stdIn(); 
	siStartInfo.dwFlags	   = STARTF_USESTDHANDLES| STARTF_USESHOWWINDOW;
	siStartInfo.wShowWindow = SW_HIDE;

	commandline_ = new wchar_t[cmdline.size()+1];
	std::copy(cmdline.c_str(), cmdline.c_str() + cmdline.size()+1, commandline_ );

	if ( !::CreateProcess( 
							  NULL,					// AppPath, 
							  commandline_,			// command line 
							  NULL,					// process security attributes 
							  NULL,					// primary thread security attributes 
							  TRUE,					// handles are inherited 
							  //DETACHED_PROCESS| 
							  CREATE_NO_WINDOW,		// creation flags 
							  NULL,					// use parent's environment 
							  NULL,					// use parent's current directory 
							  &siStartInfo,			// STARTUPINFO pointer 
							  &piProcInfo_    )		// receives PROCESS_INFORMATION 
		)
	{
		close();
		return false;
	}

	// we won't write/read to/from those
	readPipe_.closeStdOut();
	errorPipe_.closeStdOut();
	writePipe_.closeStdIn();

	if ( !async_ )
	{
		closeWrite();
		pipe();
	}
	else
	{
		asyncThread_ = mol::thread( std::bind( &PipedProcess::pipe, this) );
	}
	return true;
}

void PipedProcess::pipe()
{
	ODBGS("PipedProcess::pipe()");

	if ( async_ )
		::CoInitialize(0);

	eSuspendThreadQueue_.signal();

	readerThread_ = mol::thread( std::bind( &PipedProcess::readFromChildProcessStdOut,this) );
	errorThread_  = mol::thread( std::bind( &PipedProcess::readFromChildProcessStdErr,this) );

	mol::Thread::wait(readerThread_);
	mol::Thread::wait(errorThread_);

	ODBGS("PipedProcess::pipe - threads joined()");

	writeEOF_ = true;		
	{
		LOCK(mReadyState_)
		readyState_ = DONE;
	}		
	this->onDone();

	if ( async_ )
		::CoUninitialize();
}

void PipedProcess::terminate()
{
	if ( piProcInfo_.hProcess == INVALID_HANDLE_VALUE)
		return;

	ODBGS("PipedProcess::terminate()");

	closeWrite();
	readPipe_.close();
	errorPipe_.close();

	::Sleep(10);

	if ( readyState() != DONE )
	{
		ODBGS("called ::TerminateProcess()");
		::TerminateProcess(piProcInfo_.hProcess,-1);
	}


	while ( readyState() != PipedProcess::DONE )
	{
		ODBGS("terminating ...");
		::Sleep(10);
	}
	ODBGS("PipedProcess::terminate() - terminated");
}

void PipedProcess::closeWrite()
{
	ODBGS("PipedProcess::closeWrite()");
	writeEOF_ = true;		

	//sleep or beware the dreadded deadlock
	::Sleep(5);
	if ( async_ && writerQueue_.size() == 0)
	{
			writePipe_.closeStdOut();
			ODBGS("PipedProcess::writeLineToProcessStdIn - done");		
	}
}

void PipedProcess::writeLine(const std::string& line)
{
	writerQueue_.push(new PipedProcessWriterAction(this,line+"\r\n") );
}


std::string PipedProcess::readLine()
{
	std::string ret = "";
	if ( !async_ )
	{
		if ( listStdIn_.size() == 0 )
		{
			readEOF_ = true;
			return ret;
		}

		ret = listStdIn_.front();
		listStdIn_.pop_front();
	}
	else
	{
		while ( true ) 
		{
			{
				LOCK(mReadStdInList_);

				if (listStdIn_.size() != 0)
					break;

				if ( readEOF_ )
					return ret;
			}
			//::Sleep(10);
		}

		LOCK(mReadStdInList_);
		ret = listStdIn_.front();
		listStdIn_.pop_front();
	}
	return ret;
}


std::string PipedProcess::readErrLine()
{
	std::string ret = "";
	if ( !async_ )
	{
		if ( listStdErr_.size() == 0 )
		{
			errEOF_ = true;
			return ret;
		}

		ret = listStdErr_.front();
		listStdErr_.pop_front();
	}
	else
	{
		while ( true ) 
		{
			{
				LOCK(mReadStdErrList_);

				if ( listStdErr_.size() != 0 )
					break;

				if ( errEOF_ )
					return ret;
			}
			//::Sleep(10);
		}

		LOCK(mReadStdErrList_);
		ret = listStdErr_.front();
		listStdErr_.pop_front();
	}
	return ret;
}

/////////////////////////////////////////////////////////////////////////////

void PipedProcess::writeLineToProcessStdIn(const std::string& line)
{
	eSuspendThreadQueue_.wait();

	DWORD len = 0;

	if ( line.size() > 0 )
	{
		::WriteFile(writePipe_.stdOut(), (void*)line.c_str(), (int)line.size(), &len, NULL );
	}

	ODBGS1(" PipedProcess::writeLineToProcessStdIn - written line",len);

	if ( !async_ )
	{
		if ( writerQueue_.size() == 1 )
		{
			writePipe_.closeStdOut();
			writeEOF_ = true;
			ODBGS("PipedProcess::writeLineToProcessStdIn - done");
		}
	}
	else
	{
		if ( (writerQueue_.size() == 1) && (writeEOF_) )
		{
			writePipe_.closeStdOut();
			ODBGS("PipedProcess::writeLineToProcessStdIn - done");
		}
	}
}

/////////////////////////////////////////////////////////////////////////////

void PipedProcess::readFromChildProcessStdOut()
{
	//::Sleep(10);
	mol::filestream fs(readPipe_.stdIn());

	while( !fs.eof() )
	{
		std::string s = fs.getLine();
		ODBGS("PipedProcess::readFromChildProcessStdOut - read line");
		if ( s.size() > 0 && s[s.size()-1] == '\r' )
			s.erase(s.size()-1,1);
		LOCK(mReadStdInList_);
		listStdIn_.push_back(s);
	}
	readEOF_ = true;
	ODBGS("PipedProcess::readFromChildProcessStdOut - done");
	readPipe_.closeStdIn();
}

void PipedProcess::readFromChildProcessStdErr()
{
	//::Sleep(10);
	mol::filestream fs(errorPipe_.stdIn());

	while( !fs.eof() )
	{
		std::string s = fs.getLine();
		ODBGS("PipedProcess::readFromChildProcessStdErr - read line");
		LOCK(mReadStdErrList_);
		listStdErr_.push_back(s);
	}
	errEOF_ = true;
	ODBGS("PipedProcess::readFromChildProcessStdErr - done");
	errorPipe_.closeStdIn();
}


} // end namespace mol
