#ifndef MOL_LIB_MYSQL_C_API_INCLUDE_GUARD_DEFINE_
#define MOL_LIB_MYSQL_C_API_INCLUDE_GUARD_DEFINE_


#include "thread/thread.h"
#include "thread/sync.h"
#include <iostream>
#include <sstream>
#include <string>
#include <signal.h>

#ifdef WIN32
#include <my_global.h>
#endif
#include <mysql.h>

#define MYSQL_MAX_CONNECTIONS_DEF 20

#ifndef MYSQL_MAX_CONNECTIONS
#define MYSQL_MAX_CONNECTIONS MYSQL_MAX_CONNECTIONS_DEF
#endif

namespace mol {
namespace sql {

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


class X : public std::exception 
{
public :
	X() {}
	X(const char* const& what)
		:what_(what)
	{}

    virtual const char* what() const throw()
	{
		return what_;
	}
private:
	const char* what_;
};

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

class Connection
{
public:

	Connection();
	~Connection();

	std::string escape( const std::string& str );
	std::string encoding();

	void close();
	bool connect( const std::string& server,
				  const std::string& user, 
				  const std::string& pwd, 
				  int port = 3306 );

	bool select_db( const std::string& db );
	MYSQL_RES* query( const std::string& sql );
	bool execute( const std::string& sql );

	std::string err();

	int ping();
	std::string character_set();
	int options( enum mysql_option option, const char *arg);

	operator MYSQL*();

private:

	static int init();

	int	index_;
	static MYSQL db_[];
	static bool  slots_[];

	static mol::Mutex	mutex_;
};

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
/*
class Result
{
public:

	Result( MYSQL_RES* res )
		: res_(res), len_(0)
	{
		if (res_)
			len_ = mysql_num_fields(res_);
	}

	~Result()
	{
		if (res_)
			mysql_free_result(res_);
	}

	int fields()
	{
		return len_;
	}

	MYSQL_FIELD* field( int i )
	{
		if ( i < 0 || i > len_ )
			throw X("incalid field!");

		return mysql_fetch_field_direct(res_, i);
	}

	MYSQL_ROW& fetch()
	{
		if (res_)
			row_ = mysql_fetch_row(res_);
		return row_;
	}

	operator bool()
	{
		return res_ != 0;
	}

private:
	MYSQL_RES* res_;
	MYSQL_ROW  row_;
	int		   len_;
};
*/
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

class Binding
{
friend class Statement;
public:

	Binding();
	~Binding();

	bool null()
	{
		if (is_null_)
			return true;
		return false;
	}

	bool err()
	{
		if (is_err_)
			return true;
		return false;
	}

	void bind( MYSQL_BIND* bind );

protected:

	void init();
	

	enum_field_types	type_;
	char*				buf_;
	long unsigned int	maxlen_;
	my_bool				is_null_;
	my_bool				is_err_;

	union 
	{
		int					intval_;
		double				doubleval_;
		long long int		longlongval_;
		MYSQL_TIME			timeval_;
		long unsigned int	strlen_;
	} u_;
};

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

class Param : public Binding
{
public:
	Param( enum_field_types type, int size = 0 );
	Param( const std::string& str, int size = 0, enum_field_types type = MYSQL_TYPE_STRING );
	Param( signed char c, enum_field_types type = MYSQL_TYPE_TINY );
	Param( short int i, enum_field_types type = MYSQL_TYPE_SHORT );
	Param( int i, enum_field_types type = MYSQL_TYPE_LONG );
	Param( long long int i, enum_field_types type = MYSQL_TYPE_LONGLONG );
	Param( double d, enum_field_types type = MYSQL_TYPE_DOUBLE );
	Param( float f, enum_field_types type = MYSQL_TYPE_FLOAT );
	Param( MYSQL_TIME& t, enum_field_types type = MYSQL_TYPE_TIMESTAMP   );

	void setString( const std::string& str, int size = 0, enum_field_types type = MYSQL_TYPE_STRING);
	void setBlob( const std::string& str, int size = 0, enum_field_types type = MYSQL_TYPE_BLOB);
	void setTiny( signed char c, enum_field_types type = MYSQL_TYPE_TINY);
	void setShort( short int i, enum_field_types type = MYSQL_TYPE_SHORT);
	void setInt(int i, enum_field_types type = MYSQL_TYPE_LONG);
	void setLongLong(long long int i, enum_field_types type = MYSQL_TYPE_LONGLONG);
	void setFloat(float f, enum_field_types type = MYSQL_TYPE_FLOAT);
	void setDouble(double d, enum_field_types type = MYSQL_TYPE_DOUBLE);
	void setTimeVal( MYSQL_TIME& t, enum_field_types type = MYSQL_TYPE_TIMESTAMP);

	void setNull();
};

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

class Retval : public Binding
{
public:

	Retval( enum_field_types type, int size = 256 );
	//Retval( int size = 256 );

	bool operator()()
	{
		return (!err()) && (!null());
	}

	std::string getString();

	int getInt()
	{
		return u_.intval_;
	}

	signed char getTiny()
	{
		return (signed char)(u_.intval_);
	}

	short int getShort()
	{
		return (short int)(u_.intval_);
	}

	float getFloat()
	{
		return (float)(u_.doubleval_);
	}

	double getDouble()
	{
		return u_.doubleval_;
	}

	MYSQL_TIME& getTime()
	{
		return u_.timeval_;
	}

	long long int getLongLong()
	{
		return u_.longlongval_;
	}
};

///////////////////////////////////////////////////////////////

class Statement;

class ResultImpl
{
public:

	ResultImpl( Statement& st );
	~ResultImpl();
	void close();

	bool fetch();

	Retval* getResult(int i);

	mol::sql::Statement&	statement() { return st_; }
	
private:
	mol::sql::Statement&	st_;
	MYSQL_BIND*				bind_retvals_;
	mol::sql::Retval**		retvals_;
};


class Result
{
public:
	Result( );
	Result( ResultImpl* r );
	Result( MYSQL_RES* r );
	Result( const Result& r );

	Result& operator=( MYSQL_RES* r );
	Result& operator=( ResultImpl* r );

	~Result();
	void close();

	bool fetch();

	int fields();
	MYSQL_FIELD* field( int i );
	std::string field_name(int i );
	std::string field_alias(int i);
	int field_type(int i );
	int field_length(int i);
	int field_maxlength(int i);

	mol::sql::Retval* operator()(int i);
	std::string operator[](int i);

private:

	Result& operator=( const Result& r )
	{}

	ResultImpl* result_;

	MYSQL_RES*  myres_;
	MYSQL_ROW   row_;
	int		    len_;
};


class Statement
{
public:
	Statement( mol::sql::Connection& conn );
	~Statement();

	void close();
	bool reset();

	bool prepare( const std::string& sql );
	bool bind( int i, mol::sql::Param* param );
	ResultImpl* execute();

	int params();
	int fields();

	MYSQL_FIELD* field( int i );
	std::string field_name(int i );
	std::string field_alias(int i);
	int field_type(int i );
	int field_length(int i);
	int field_maxlength(int i);

	int attr( enum enum_stmt_attr_type option, const void *arg);

	bool bind( int i, const std::string& s, int len = 0, enum_field_types type = MYSQL_TYPE_STRING );
	bool bind( int i, int v, enum_field_types type = MYSQL_TYPE_LONG);
	bool bind( int i, signed char v, enum_field_types type = MYSQL_TYPE_TINY);
	bool bind( int i, short int v, enum_field_types type = MYSQL_TYPE_SHORT);
	bool bind( int i, long long v,enum_field_types type = MYSQL_TYPE_LONGLONG);
	bool bind( int i, double v, enum_field_types type = MYSQL_TYPE_DOUBLE);
	bool bind( int i, float v, enum_field_types type = MYSQL_TYPE_FLOAT);
	bool bind( int i, MYSQL_TIME& t, enum_field_types type = MYSQL_TYPE_TIMESTAMP);

	operator bool()
	{
		return stmt_ != 0;
	}

	mol::sql::Connection& conn() { return conn_; }
	MYSQL_STMT* statement() 	 { return stmt_; }
	MYSQL_RES* meta() 		     { return prepare_meta_result_; }

private:
	mol::sql::Connection&	conn_;
	MYSQL_STMT*				stmt_;
	MYSQL_BIND*				bind_params_;
	mol::sql::Param**		params_;

	MYSQL_RES* 				prepare_meta_result_;
	int 					param_count_;
	int 					column_count_;
	std::string				sql_;
};


///////////////////////////////////////////////////////////////

} // end namespace sql
} // end namespace mol

///////////////////////////////////////////////////////////////

std::ostream& operator<<( std::ostream& os, mol::sql::Retval* r );

///////////////////////////////////////////////////////////////


#endif



