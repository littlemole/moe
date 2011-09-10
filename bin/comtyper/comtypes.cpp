#include "stdafx.h"
#include "types.h"

#include "ole/dll.h"
#include "util/regex.h"


int main( int nargs, char* args[] )
{
	//::DebugBreak();
	if ( nargs < 3 )
	{
		std::wcout << L"usage: comtyper.exe [inputfile.tlb] [outputfile.tlb]" << std::endl;
		std::wcout.flush();
		return 0;
	}

	mol::string input_file_name = mol::toString(args[1]);
	std::string output_file_name = mol::tostring(args[2]);

	TypeLib2XML typeLib2XML;
	bool retVal = typeLib2XML.loadTypeLib(input_file_name);
	if (retVal == false )
	{
		std::wcout << L"error: could not load " << input_file_name << std::endl;
		std::wcout.flush();
		return 1;
	}

	mol::string xml = typeLib2XML.getXML();
	std::string utf8 = mol::toUTF8(xml);

	mol::filestream fs;
	if (!fs.create( output_file_name,true))
	{
		std::wcout << L"error: could not write to " << mol::towstring(output_file_name) << std::endl;
		std::wcout.flush();
		return 1;
	}
	fs.write( utf8.c_str(), utf8.size() );
	fs.write( "\r\n", 2 );
	fs.close();
	return 0;
};