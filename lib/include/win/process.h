#ifndef _MOL_LIB_PROCESS_DEF_GUARD_DEFINE_
#define _MOL_LIB_PROCESS_DEF_GUARD_DEFINE_

#include "conf.h"
#include "util/util.h"
#include "util/str.h"
#include <iostream>
#include <string>
#include <list>
#include "util/X.h"
#include "thread/threadqueue.h"
#include "win/file.h"
namespace mol {

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////


class SACL : public SECURITY_ATTRIBUTES 
{
public:

	SACL(LPVOID sd = NULL, bool inherit = false);
};

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

class Pipe
{
public:

	Pipe();
	virtual ~Pipe();

	bool create(bool inheritHandles);
	void close();

	void noStdInInherit();
	void noStdOutInherit();

	HANDLE& stdIn(); 
	HANDLE& stdOut();

	void closeStdIn();
	void closeStdOut();

protected:
	HANDLE hStdIn_;
	HANDLE hStdOut_;
};

class PipedProcess;

class PipedProcessWriterAction
{
public:
	PipedProcessWriterAction();

	PipedProcessWriterAction(PipedProcess* pp, const std::string& line);

	void operator()();

private:
	PipedProcess* pp_;
	std::string	  line_;
};


class PipedProcess
{
friend class PipedProcessWriterAction;
public: 
	PipedProcess();
	virtual ~PipedProcess();

	enum READYSTATE { ERR = 0, INITIALIZED = 1, RUNNING = 2, DONE = 3 };

	bool create( const std::wstring& cmdline);
	void close();

	void terminate();

	bool eof();	
	bool err_eof();

	void writeLine(const std::string& line);
	void closeWrite();

	std::string readLine();
	std::string readErrLine();

	READYSTATE readyState();

	void async(bool b);

	virtual void onDone() {};

private:

	void pipe();

	void readFromChildProcessStdOut();
	void readFromChildProcessStdErr();

	void writeLineToProcessStdIn(const std::string& line);

	std::list<std::string> listStdIn_;
	std::list<std::string> listStdErr_;

	READYSTATE	readyState_;

	bool	async_;
	bool    writeEOF_;
	bool    readEOF_;
	bool    errEOF_;

	int     readerThread_;
	int     errorThread_;
	int     asyncThread_;

	mol::Pipe	readPipe_;
	mol::Pipe	writePipe_;
	mol::Pipe	errorPipe_;

	mol::CriticalSection mReadyState_;
	mol::CriticalSection  mReadStdInList_;
	mol::CriticalSection  mReadStdErrList_;

	mol::ThreadQueue<PipedProcessWriterAction,FALSE> writerQueue_;
	mol::Event  eSuspendThreadQueue_;

	PROCESS_INFORMATION piProcInfo_;
	wchar_t* commandline_;

};

} // end namespace mol

#endif