#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <list>

namespace moeTest {
void init_ctx(mol::di::Context&);
}

#define COMPONENT friend void moeTest::init_ctx( mol::di::Context& );

class Logger
{
COMPONENT;
public:

	~Logger()
	{
		std::cout << "~Logger" << std::endl;
	}

	void log(const std::string& txt) const
	{
		std::cout << (greeting) << " " << txt << std::endl;
		//std::cout << " " << txt << std::endl;
	}

private:
	std::string greeting;
};


class Printer
{
public:

	~Printer()
	{
		std::cout << "~Printer" << std::endl;
	}

	void log(const std::string& txt)
	{
		
		for ( std::list<std::string>::iterator it = list.begin(); it != list.end(); it++)
		{
			std::cout << "\t" << (*it) << std::endl;
		}
		
		std::cout << txt << std::endl;
	}

	std::list<std::string> list;
private:
};


class Drive
{
public:

	Drive(const Logger& l)
		: logger(l)
	{
	}

	~Drive()
	{
		std::cout << "~Drive" << std::endl;
	}

	void log(const std::string& txt)
	{
		logger.log(txt);
	}

	const Logger& logger;
};

namespace test {
class Test
{
COMPONENT;
public:	

	Test( Logger* l, Drive* d, Printer* p )
	{
		l->log("Test::Test() called");
		logger = l;
		drive = d;
		printer = p;
	}

	~Test()
	{
		//delete printer;
		std::cout << "~Test" << std::endl;
	}

	void test()
	{
		logger->log("Test::test() called");
		printer->log("Test::test() called");	
		drive->log("Test::test() called");	
	}

private:
	Logger* logger;

	Printer* printer;

	Drive* drive;
};
}

class App
{
public:

	~App()
	{
		std::cout << "~App" << std::endl;
	}

	void run()
	{
		test->test();

		for( std::map<std::string,std::string>::iterator it = map_.begin(); it != map_.end(); it++) 
		{
			std::cout << (*it).first << " -> " << (*it).second << std::endl;
		}
	}

	std::map<std::string,std::string> map_;
	test::Test* test;
};

