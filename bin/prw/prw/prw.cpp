// named_pipe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "win/shell.h"
#include "win/file.h"


class UAC_Elevator
{
public:

	static bool read_to_pipe(const std::wstring& pipename, const std::wstring& filename )
	{
		//::MessageBox(0,_T("read_to_pipe"),_T("UAC"),0);

		mol::UACPipe pipe;
		pipe.open(pipename);		

		if ( !pipe)
		{
			ODBGS("open pipe failed!");
			return false;
		}

		mol::filestream fs;
		fs.open(mol::tostring(filename));//,std::ios::in | std::ios::binary);
		fs.setf( std::ios::binary );
		std::string data = fs.readAll();
		fs.close();

		if ( !pipe.write(data) )
		{
			ODBGS("pipe write failed!");
			return false;
		}
		std::string dummy = pipe.read();
		return true;
	}

	static bool write_from_pipe(const std::wstring& pipename, const std::wstring& filename )
	{
		//::MessageBox(0,_T("write_from_pipe"),_T("UAC"),0);

		mol::UACPipe pipe;
		pipe.open(pipename);

		if ( !pipe)
		{
			ODBGS("open pipe failed!");
			return false;
		}

		std::string data = pipe.read();

		ODBGS1( "data read:", (int)data.size() );
		if ( data.size() == 0 )
			return false;

		DWORD flag = TRUNCATE_EXISTING;

		if ( !mol::Path::exists(filename) )
			flag = CREATE_NEW;

		mol::filestream fs;
		fs.open(mol::tostring(filename),GENERIC_WRITE,0,0,flag);
		fs.setf( std::ios::binary );
		fs.write(data.c_str(),data.size());
		fs.close();
		return true;
	}
};


int wmain(int argc, wchar_t* argv[])
{
	if ( argc < 4 )
	{
		std::cout << "invalid args. argc < 4" << std::endl;
		return 0;
	}

	std::wstring cmd      = argv[1];
	std::wstring pipename = argv[2];
	std::wstring filename = argv[3];

	if ( cmd == _T("read") )
	{
		UAC_Elevator::read_to_pipe(pipename,filename);
		return 0;
	}

	if ( cmd == _T("write") )
	{
		UAC_Elevator::write_from_pipe(pipename,filename);
		return 0;
	}

	return 1;
}

