#include "mysql/molsql.h"

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

namespace mol {
namespace sql {

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

// connection handles
MYSQL Connection::db_[MYSQL_MAX_CONNECTIONS];

// free slot markers for connection handles
bool Connection::slots_[MYSQL_MAX_CONNECTIONS];

// global mutex
mol::Mutex	Connection::mutex_;

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Connection class
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

Connection::Connection()
: index_(-1)
{
	LOCK(mutex_);
	{
		static int i = init();
	}
}

int Connection::init()
{
	// static class initialization
	for ( int i = 0; i < MYSQL_MAX_CONNECTIONS; i++ )
	{
		slots_[i] = false;
	}	
	return 1;
}

Connection::~Connection()
{
	close();
}

void Connection::close()
{
	LOCK(mutex_);
	if ( index_ == -1 )
		return;

	mysql_close(&db_[index_]);
	slots_[index_] = false;
	index_ = -1;
}

std::string  Connection::encoding()
{
	MY_CHARSET_INFO cs;

	mysql_get_character_set_info( &db_[index_], &cs);

	return cs.name;
}


std::string Connection::escape( const std::string& str )
{
	char* buf = new char[str.size()*2+1];
	mysql_real_escape_string( &db_[index_], buf, str.c_str(), str.size() );
	std::string ret(buf);
	delete[] buf;
	return ret;
}

bool Connection::connect( const std::string& server,const std::string& user, const std::string& pwd, int port )
{
	if ( index_ != -1 )
		close();

	LOCK(mutex_);
	index_ = -1;

	// find a free slot
	for ( int i = 0; i < MYSQL_MAX_CONNECTIONS; i++ )
	{
		if (!slots_[i] )
		{
			index_ = i;
			break;
		}
	}
	if ( index_ == -1 )
		throw X( "too many open connections!" );

	// init db handle and connect
	mysql_init(&db_[index_]);

	MYSQL* ret = mysql_real_connect(&db_[index_], server.c_str(), user.c_str(), pwd.c_str(), NULL, port, 0,0);
	if (!ret)
		throw X( "mysql_real_connect failed!" );

	// mark slot busy
	slots_[index_] = true;
	return ret!=0;
}

bool Connection::select_db( const std::string& db )
{
	if (mysql_select_db( &db_[index_], db.c_str() ) )
		throw X("mysql_select_db failed!");
	return true;
}

MYSQL_RES* Connection::query( const std::string& sql )
{
	if (mysql_real_query(&db_[index_], sql.c_str(), sql.size()) )
		throw X("mysql_real_query failed!");

	return mysql_use_result(&db_[index_]);
}

bool Connection::execute( const std::string& sql )
{
	if (mysql_real_query(&db_[index_], sql.c_str(), sql.size()) )
		throw X("mysql_real_query (execute) failed!");
	return true;
}

std::string Connection::err()
{
	return mysql_error(&db_[index_]);
}


int Connection::ping()
{
	return mysql_ping(&db_[index_]);
}

std::string Connection::character_set()
{
	return mysql_character_set_name(&db_[index_]);
}

int Connection::options( enum mysql_option option, const char *arg )
{
	return mysql_options(&db_[index_],option, arg);
}

Connection::operator MYSQL*()
{
	return &db_[index_];
}


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Binding - base class for Param and Retval
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

Binding::Binding()
{
	init();
}

Binding::~Binding()
{
	if ( buf_ )
		delete[] buf_;
}

void Binding::init()
{
	is_null_        = false;
	is_err_         = false;

	buf_     	    = 0;
	maxlen_  	    = 0;
	u_.longlongval_ = 0;
}

void Binding::bind( MYSQL_BIND* bind )
{
	is_null_        = false;
	is_err_         = false;

	bind->buffer_type = (enum_field_types) type_;
	switch( type_ )
	{
		case MYSQL_TYPE_TINY:
		case MYSQL_TYPE_SHORT:
		case MYSQL_TYPE_LONG:
		{
			bind->buffer = (char*)&u_.intval_;
			break;
		}
		case MYSQL_TYPE_LONGLONG:
		{
			bind->buffer = (char*)&u_.longlongval_;
			break;
		}
		case MYSQL_TYPE_FLOAT:
		case MYSQL_TYPE_DOUBLE:
		{
			bind->buffer = (char*)&u_.doubleval_;
			break;
		}
		case MYSQL_TYPE_TIME:
		case MYSQL_TYPE_DATE:
		case MYSQL_TYPE_DATETIME:
		case MYSQL_TYPE_TIMESTAMP:
		{
			bind->buffer = (char*)&u_.timeval_;
			break;
		}
		case MYSQL_TYPE_VAR_STRING:
		case MYSQL_TYPE_STRING:
		case MYSQL_TYPE_BLOB:
		{
			bind->buffer 		= buf_;
			bind->buffer_length = maxlen_;
			bind->length  		= &u_.strlen_;
			break;
		}
	}
	bind->is_null = &is_null_;
	bind->error   = &is_err_;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Input SQL Parameters for prepared statement binding
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


Param::Param( enum_field_types type, int size )
{
	type_ = type;
	if ( size != 0 )
	{
		maxlen_ = u_.strlen_ = size;
		buf_ = new char[maxlen_+1];
	}
}

Param::Param( const std::string& str, int size, enum_field_types type  )
{
	type_ = type;
	maxlen_ = u_.strlen_ = str.size();
	if ( size != 0 )
		maxlen_ = size;
	buf_ = new char[maxlen_+1];
	strncpy(buf_,str.c_str(),str.size()+1);
}

Param::Param( signed char c, enum_field_types type )
{
	type_      = type;
	maxlen_    = u_.strlen_ = 0;
	u_.intval_ = c;
}

Param::Param( short int i, enum_field_types type )
{
	type_      = type;
	maxlen_    = u_.strlen_ = 0;
	u_.intval_ = i;
}

Param::Param( int i, enum_field_types type )
{
	type_      = type;
	maxlen_    = u_.strlen_ = 0;
	u_.intval_ = i;
}

Param::Param( long long int i, enum_field_types type )
{
	type_   	 	= type;
	maxlen_ 	 	= u_.strlen_ = 0;
	u_.longlongval_ = i;
}

Param::Param( double d, enum_field_types type )
{
	type_         = type;
	maxlen_    	  = u_.strlen_ = 0;
	u_.doubleval_ = d;
}

Param::Param( float f, enum_field_types type )
{
	type_         = type;
	maxlen_    	  = u_.strlen_ = 0;
	u_.doubleval_ = f;
}

Param::Param( MYSQL_TIME& t, enum_field_types type)
{
	type_    	= type;
	maxlen_  	= u_.strlen_ = 0;
	u_.timeval_ = t;
}

void Param::setString( const std::string& str, int size , enum_field_types type )
{
	if ( buf_ )
		delete[] buf_;

	init();
	type_ 	= type;
	maxlen_ = u_.strlen_ = str.size();
	if ( size != 0 )
		maxlen_ = size;
	buf_ 	= new char[maxlen_+1];
	strncpy(buf_,str.c_str(),str.size()+1);
}

void Param::setBlob( const std::string& str, int size , enum_field_types type )
{
	setString( str, size, type );
}

void Param::setTiny( signed char c, enum_field_types type)
{
	init();
	type_      = type;
	maxlen_    = u_.strlen_ = 0;
	u_.intval_ = c;
}

void Param::setShort( short int i, enum_field_types type )
{
	init();
	type_      = type;
	maxlen_    = u_.strlen_ = 0;
	u_.intval_ = i;
}

void Param::setInt(int i, enum_field_types type )
{
	init();
	type_      = type;
	maxlen_    = u_.strlen_ = 0;
	u_.intval_ = i;
}

void Param::setLongLong(long long int i, enum_field_types type )
{
	init();
	type_   	 	= type;
	maxlen_ 	 	= u_.strlen_ = 0;
	u_.longlongval_ = i;
}

void Param::setFloat(float f, enum_field_types type )
{
	init();
	type_         = type;
	maxlen_    	  = u_.strlen_ = 0;
	u_.doubleval_ = f;
}

void Param::setDouble(double d, enum_field_types type )
{
	init();
	type_         = type;
	maxlen_    	  = u_.strlen_ = 0;
	u_.doubleval_ = d;
}

void Param::setTimeVal( MYSQL_TIME& t, enum_field_types type )
{
	init();
	type_      	= type;
	maxlen_    	= u_.strlen_ = 0;
	u_.timeval_ = t;
}

void Param::setNull()
{
	is_null_ = true;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// output bind buffers for prepared statements
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

Retval::Retval( enum_field_types type, int size )
{
	type_ = type;

	switch( type )
	{
		case MYSQL_TYPE_VAR_STRING:
		case MYSQL_TYPE_STRING:
		case MYSQL_TYPE_BLOB:
		{
			maxlen_ = u_.strlen_ = size+1;
			buf_ = new char[maxlen_];
			break;
		}
	}
}

/*
Retval::Retval( int size )
{
	type_ = MYSQL_TYPE_STRING;

	maxlen_ = u_.strlen_ = size+1;
	buf_ = new char[maxlen_];
}
*/

std::string Retval::getString()
{
	switch( type_ )
	{
		case MYSQL_TYPE_TINY:
		case MYSQL_TYPE_SHORT:
		case MYSQL_TYPE_LONG:
		{
			std::ostringstream oss;
			oss << u_.intval_;
			return oss.str();
		}
		case MYSQL_TYPE_FLOAT:
		case MYSQL_TYPE_DOUBLE:
		{
			std::ostringstream oss;
			oss << u_.doubleval_;
			return oss.str();
		}
		case MYSQL_TYPE_LONGLONG:
		{
			std::ostringstream oss;
			oss << u_.longlongval_;
			return oss.str();
		}
		case MYSQL_TYPE_TIME:
		{
			std::ostringstream oss;
			oss << u_.timeval_.hour << ":" << u_.timeval_.minute << ":" << u_.timeval_.second;
			return oss.str();
			break;
		}
		case MYSQL_TYPE_DATE:
		{
			std::ostringstream oss;
			oss << u_.timeval_.year << "-" << u_.timeval_.month << "-" << u_.timeval_.day;
			return oss.str();
			break;
		}
		case MYSQL_TYPE_DATETIME:
		{
			std::ostringstream oss;
			oss << u_.timeval_.year << "-" << u_.timeval_.month << "-" << u_.timeval_.day << " ";
			oss << u_.timeval_.hour << ":" << u_.timeval_.minute;
			return oss.str();
			break;
		}
		case MYSQL_TYPE_TIMESTAMP:
		{
			std::ostringstream oss;
			oss << u_.timeval_.year << "-" << u_.timeval_.month << "-" << u_.timeval_.day << " ";
			oss << u_.timeval_.hour << ":" << u_.timeval_.minute << ":" << u_.timeval_.second;
			return oss.str();
		}
		case MYSQL_TYPE_VAR_STRING:
		case MYSQL_TYPE_STRING:
		case MYSQL_TYPE_BLOB:
		{
			if (!buf_)
				return "";
			if (is_null_)
				return "";
			if (is_err_)
				return "";

			return std::string( buf_, u_.strlen_ );
		}
		case MYSQL_TYPE_NULL:
		{
			return "";
		}
	}
	return "";
}

/*
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Prepared Statement and Binding impl
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


Statement::Statement( Connection& conn )
: stmt_(0), bind_params_(0),bind_retvals_(0), conn_(conn),prepare_meta_result_(0)
{
	stmt_ = mysql_stmt_init(conn);
	if (!stmt_)	
		throw X("mysql_stmt_init failed!");
}

Statement::~Statement()
{
	close();
}

void Statement::close()
{
	if(!stmt_)
		return;

	mysql_free_result(prepare_meta_result_);
	mysql_stmt_free_result(stmt_);
	mysql_stmt_close(stmt_);

	stmt_ = 0;

	if ( bind_params_ )
	{
		delete[] bind_params_;
		bind_params_ = 0;
	}

	if ( bind_retvals_ )
	{
		delete[] bind_retvals_;
		bind_retvals_ = 0;
	}
}

bool Statement::prepare( const std::string& sql )
{
	sql_ = sql;

	if (!stmt_)
		throw X("no statement initialized!");

	if ( mysql_stmt_prepare(stmt_, sql.c_str(), sql.size()) )
		throw X("mysql_stmt_prepare failed!");

	param_count_ = mysql_stmt_param_count(stmt_);
	if ( param_count_ > 0 )
	{
		bind_params_ = new MYSQL_BIND[param_count_];
		memset(&(bind_params_[0]), 0, sizeof(MYSQL_BIND)*param_count_);
	}

	prepare_meta_result_ = mysql_stmt_result_metadata(stmt_); 
	if ( !prepare_meta_result_ )
		throw X("prepare_meta_result failed!");

	column_count_ = mysql_num_fields(prepare_meta_result_); 
	if ( column_count_ > 0 )
	{
		bind_retvals_ = new MYSQL_BIND[column_count_];
		memset(bind_retvals_, 0, sizeof(MYSQL_BIND)*column_count_);
	}
	return true;
}

bool Statement::reset(  )
{
	mysql_stmt_free_result(stmt_);
	mysql_stmt_reset(stmt_);

	if ( mysql_stmt_prepare(stmt_, sql_.c_str(), sql_.size()) )
		throw X("reset: mysql_stmt_prepare failed!");

	return true;
}


int Statement::fields()
{
	return column_count_;
}

int Statement::params()
{
	return param_count_;
}

MYSQL_FIELD* Statement::field( int i )
{
	if(!prepare_meta_result_)
		throw X("ro result yet");

	if ( i < 0 || i >= column_count_ )
		throw X("incalid field!");

	return mysql_fetch_field_direct(prepare_meta_result_, i);
}

std::string Statement::field_name(int i )
{
	MYSQL_FIELD* f = field(i);
	return std::string(f->org_name,f->org_name_length);
}

std::string Statement::field_alias(int i)
{
	MYSQL_FIELD* f = field(i);
	return std::string(f->name,f->name_length);
}

int Statement::field_type(int i )
{
	MYSQL_FIELD* f = field(i);
	return f->type;
}

int Statement::field_length(int i)
{
	MYSQL_FIELD* f = field(i);
	return f->length;
}

int Statement::field_maxlength(int i)
{
	MYSQL_FIELD* f = field(i);
	return f->max_length;
}

bool Statement::bind( )
{
	if ( param_count_ != 0 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);
	return true;
}

bool Statement::bind( Param& param )
{

	if ( param_count_ != 1 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param.bind( &bind_params_[0] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2 )
{
	if ( param_count_ != 2 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2, Param& param3  )
{
	if ( param_count_ != 3 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );
	param3.bind( &bind_params_[2] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2, Param& param3, Param& param4  )
{
	if ( param_count_ != 4 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );
	param3.bind( &bind_params_[2] );
	param4.bind( &bind_params_[3] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2, Param& param3, Param& param4, Param& param5  )
{
	if ( param_count_ != 5 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );
	param3.bind( &bind_params_[2] );
	param4.bind( &bind_params_[3] );
	param5.bind( &bind_params_[4] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2, Param& param3, Param& param4, Param& param5, Param& param6  )
{
	if ( param_count_ != 6 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );
	param3.bind( &bind_params_[2] );
	param4.bind( &bind_params_[3] );
	param5.bind( &bind_params_[4] );
	param6.bind( &bind_params_[5] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2, Param& param3, Param& param4, Param& param5, Param& param6, Param& param7  )
{
	if ( param_count_ != 7 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );
	param3.bind( &bind_params_[2] );
	param4.bind( &bind_params_[3] );
	param5.bind( &bind_params_[4] );
	param6.bind( &bind_params_[5] );
	param7.bind( &bind_params_[6] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::bind( Param& param1, Param& param2, Param& param3, Param& param4, Param& param5, Param& param6, Param& param7, Param& param8  )
{
	if ( param_count_ != 8 )
		throw X("wrong parameter bind count!");

	mysql_stmt_free_result(stmt_);

	param1.bind( &bind_params_[0] );
	param2.bind( &bind_params_[1] );
	param3.bind( &bind_params_[2] );
	param4.bind( &bind_params_[3] );
	param5.bind( &bind_params_[4] );
	param6.bind( &bind_params_[5] );
	param7.bind( &bind_params_[6] );
	param8.bind( &bind_params_[7] );

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw X("mysql_stmt_bind_param failed!");
	return true;
}

bool Statement::execute()
{
	if (mysql_stmt_execute(stmt_))
		throw X("mysql_stmt_execute failed!");

	if (mysql_stmt_store_result(stmt_))
		throw X("mysql_stmt_store_results failed!");

	return true;
}

bool Statement::store(Retval& r1)
{
	if ( column_count_ != 1 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2)
{
	if ( column_count_ != 2 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2, Retval& r3)
{
	if ( column_count_ != 3 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);
	r3.bind(&bind_retvals_[2]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2, Retval& r3, Retval& r4)
{
	if ( column_count_ != 4 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);
	r3.bind(&bind_retvals_[2]);
	r4.bind(&bind_retvals_[3]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2, Retval& r3, Retval& r4, Retval& r5)
{
	if ( column_count_ != 5 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);
	r3.bind(&bind_retvals_[2]);
	r4.bind(&bind_retvals_[3]);
	r5.bind(&bind_retvals_[4]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2, Retval& r3, Retval& r4, Retval& r5, Retval& r6 )
{
	if ( column_count_ != 6 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);
	r3.bind(&bind_retvals_[2]);
	r4.bind(&bind_retvals_[3]);
	r5.bind(&bind_retvals_[4]);
	r6.bind(&bind_retvals_[5]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2, Retval& r3, Retval& r4, Retval& r5, Retval& r6, Retval& r7)
{
	if ( column_count_ != 7 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);
	r3.bind(&bind_retvals_[2]);
	r4.bind(&bind_retvals_[3]);
	r5.bind(&bind_retvals_[4]);
	r6.bind(&bind_retvals_[5]);
	r7.bind(&bind_retvals_[6]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::store(Retval& r1, Retval& r2, Retval& r3, Retval& r4, Retval& r5, Retval& r6, Retval& r7, Retval& r8 )
{
	if ( column_count_ != 8 )
		throw X("wrong retval bind column!");

	r1.bind(&bind_retvals_[0]);
	r2.bind(&bind_retvals_[1]);
	r3.bind(&bind_retvals_[2]);
	r4.bind(&bind_retvals_[3]);
	r5.bind(&bind_retvals_[4]);
	r6.bind(&bind_retvals_[5]);
	r7.bind(&bind_retvals_[6]);
	r8.bind(&bind_retvals_[7]);

	if (mysql_stmt_bind_result(stmt_, bind_retvals_))
		throw X("mysql_stmt_bind_result failed!");

	return true;
}

bool Statement::fetch()
{
	if(!mysql_stmt_fetch(stmt_))
		return 1;
	return 0;
}
*/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

Statement::Statement( mol::sql::Connection& conn )
: stmt_(0), bind_params_(0), conn_(conn), prepare_meta_result_(0),params_(0)
{
	stmt_ = mysql_stmt_init(conn);
	if (!stmt_)	
		throw mol::sql::X("mysql_stmt_init failed!");
}


Statement::~Statement()
{
	close();
}


void Statement::close()
{
	if(!stmt_)
		return;

	mysql_stmt_free_result(stmt_);
	mysql_free_result(prepare_meta_result_);
	mysql_stmt_close(stmt_);
	stmt_ = 0;

	if ( bind_params_ )
	{
		delete[] bind_params_;
		bind_params_ = 0;
	}

	if ( params_ )
	{
		for ( int i = 0; i < param_count_; i++ )
			if ( params_[i] )
				delete params_[i];

		delete[] params_;
		params_ = 0;
	}
}

bool Statement::reset()
{
	mysql_stmt_free_result(stmt_);
	mysql_stmt_reset(stmt_);

	if ( mysql_stmt_prepare(stmt_, sql_.c_str(), sql_.size()) )
		throw mol::sql::X("reset: mysql_stmt_prepare failed!");

	return true;
}


bool Statement::prepare( const std::string& sql )
{
	sql_ = sql;

	if (!stmt_)
		throw mol::sql::X("no statement initialized!");

	mysql_stmt_free_result(stmt_);
	mysql_free_result(prepare_meta_result_);

	const my_bool mb = 1;
	attr( STMT_ATTR_UPDATE_MAX_LENGTH, &mb );    

	if ( mysql_stmt_prepare(stmt_, sql.c_str(), sql.size()) )
		throw mol::sql::X("mysql_stmt_prepare failed!");

	param_count_ = mysql_stmt_param_count(stmt_);
	if ( param_count_ > 0 )
	{
		bind_params_ = new MYSQL_BIND[param_count_];
		memset(&(bind_params_[0]), 0, sizeof(MYSQL_BIND)*param_count_);

		params_ = new mol::sql::Param*[param_count_];
		for ( int i = 0; i < param_count_; i++ )
			params_[i] = 0;
		//memset(params_, 0, sizeof(mol::sql::Param*)*param_count_);

	}

	prepare_meta_result_ = mysql_stmt_result_metadata(stmt_); 
	if ( !prepare_meta_result_ )
		throw mol::sql::X("prepare_meta_result failed!");

	column_count_ = mysql_num_fields(prepare_meta_result_); 
	if ( column_count_ > 0 )
	{
//		bind_retvals_ = new MYSQL_BIND[column_count_];
//		memset(bind_retvals_, 0, sizeof(MYSQL_BIND)*column_count_);
	}
	return true;
}


int Statement::params()
{
	return param_count_;
}

int Statement::fields()
{
	return column_count_;
}


MYSQL_FIELD* Statement::field( int i )
{
	if(!prepare_meta_result_)
		throw mol::sql::X("ro result yet");

	if ( i < 0 || i >= column_count_ )
		throw mol::sql::X("incalid field!");

	return mysql_fetch_field_direct(prepare_meta_result_, i);
}

std::string Statement::field_name(int i )
{
	MYSQL_FIELD* f = field(i);
	return std::string(f->org_name,f->org_name_length);
}

std::string Statement::field_alias(int i)
{
	MYSQL_FIELD* f = field(i);
	return std::string(f->name,f->name_length);
}

int Statement::field_type(int i )
{
	MYSQL_FIELD* f = field(i);
	return f->type;
}

int Statement::field_length(int i)
{
	MYSQL_FIELD* f = field(i);
	return f->length;
}

int Statement::field_maxlength(int i)
{
	MYSQL_FIELD* f = field(i);
	return f->max_length;
}


int Statement::attr( enum enum_stmt_attr_type option, const void *arg)
{
	return mysql_stmt_attr_set( stmt_, option, arg);
}


bool Statement::bind( int i, mol::sql::Param* p )
{
	if ( (i < 0) || (i >= param_count_) )
		throw mol::sql::X("wrong parameter bind count!");

	if ( params_[i] )
		delete params_[i];

	params_[i] = p;
	params_[i]->bind( &bind_params_[i] );

	return true;
}

bool Statement::bind( int i, const std::string& s, int len, enum_field_types type )
{
	int l = len ? len : s.size();
	return bind( i, new mol::sql::Param( s, l, type ) );
}

bool Statement::bind( int i, int v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

bool Statement::bind( int i, signed char v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

bool Statement::bind( int i, short int v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

bool Statement::bind( int i, long long v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

bool Statement::bind( int i, double v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

bool Statement::bind( int i, float v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

bool Statement::bind( int i, MYSQL_TIME& v, enum_field_types type )
{
	return bind( i, new mol::sql::Param( v, type ) );
}

ResultImpl* Statement::execute()
{
	for ( int i = 0; i < param_count_; i++ )
	{
		if ( params_[i] == 0 )
			throw mol::sql::X("missing parameter bindings");
	}

	mysql_stmt_free_result(stmt_);

	if (mysql_stmt_bind_param(stmt_, bind_params_))
		throw mol::sql::X("mysql_stmt_bind_param failed!");

	if (mysql_stmt_execute(stmt_))
		throw mol::sql::X("mysql_stmt_execute failed!");

	if (mysql_stmt_store_result(stmt_))
		throw mol::sql::X("mysql_stmt_store_results failed!");

	ResultImpl* result = new ResultImpl( *this );
	return result;
}



ResultImpl::ResultImpl( Statement& st )
: st_(st), bind_retvals_(0), retvals_(0)
{
	bind_retvals_ = new MYSQL_BIND[st_.fields()];
	memset(bind_retvals_, 0, sizeof(MYSQL_BIND)*st_.fields());

	retvals_ = new Retval*[st_.fields()];
	memset(retvals_, 0, sizeof(Retval*)*st_.fields());		

	for ( int i = 0; i < st_.fields(); i++ )
	{
		retvals_[i] = new Retval( (enum_field_types)st_.field_type(i), st_.field_maxlength(i) );
		retvals_[i]->bind(&bind_retvals_[i]);
	}

	if (mysql_stmt_bind_result(st_.statement(), bind_retvals_))
		throw mol::sql::X("mysql_stmt_bind_result failed!");

}


ResultImpl::~ResultImpl()
{
	close();
}

void ResultImpl::close()
{
	if(!st_.statement())
		return;

	if ( bind_retvals_ )
	{
		delete[] bind_retvals_;
		bind_retvals_ = 0;
	}

	if ( retvals_ )
	{
		for ( int i = 0; i < st_.fields(); i++ )
			if ( retvals_[i] )
				delete retvals_[i];
		delete[] retvals_;
	}
}

bool ResultImpl::fetch()
{
	if ( mysql_stmt_fetch(st_.statement()) )
	{
		mysql_stmt_free_result(st_.statement());
		return 0;
	}
	return 1;
}

Retval* ResultImpl::getResult(int i)
{
	return retvals_[i];
}




Result::Result( )
: result_(0), myres_(0)
{
}

Result::Result( ResultImpl* r )
: result_(r), myres_(0)
{
	myres_ = r->statement().meta();
	if (myres_)
		len_ = mysql_num_fields(myres_);
}

Result::Result( MYSQL_RES* r )
: result_(0), myres_(r)
{
	if (myres_)
		len_ = mysql_num_fields(myres_);
}

Result::Result( const Result& r )
{
	// take ownership
	result_ = r.result_;
	((Result&)r).result_ = 0;
	myres_ = r.myres_;
	((Result&)r).myres_ = 0;
}

Result::~Result()
{
	close();
}

void Result::close()
{
	if ( result_ )
		delete result_;
	else
		if ( myres_ )
				mysql_free_result(myres_);

	result_ = 0;
	myres_  = 0;
}

int Result::fields()
{
	return len_;
}

MYSQL_FIELD* Result::field( int i )
{
	if(!myres_)
		throw X("ro result yet");

	if ( i < 0 || i >= len_ )
		throw X("incalid field!");

	return mysql_fetch_field_direct(myres_, i);
}

std::string Result::field_name(int i )
{
	MYSQL_FIELD* f = field(i);
	return std::string(f->org_name,f->org_name_length);
}

std::string Result::field_alias(int i)
{
	MYSQL_FIELD* f = field(i);
	return std::string(f->name,f->name_length);
}
int Result::field_type(int i )
{
	MYSQL_FIELD* f = field(i);
	return f->type;
}
int Result::field_length(int i)
{
	MYSQL_FIELD* f = field(i);
	return f->length;
}

int Result::field_maxlength(int i)
{
	MYSQL_FIELD* f = field(i);
	return f->max_length;
}

bool Result::fetch()
{
	if (result_)
	{
		return result_->fetch();
	}
	if (myres_)
	{
		row_ = mysql_fetch_row(myres_);
		return row_ != 0;
	}		
	return false;
}

/*	MYSQL_ROW& fetch_row()
{
	if (result_)
		throw mol::sql::X("fetch_row called for non-simple query");
	
	row_ = mysql_fetch_row(myres_);
	return row_;
}

/*	ResultImpl* operator->()
{		
	return result_;
}
*/
mol::sql::Retval* Result::operator()(int i)
{
	if ( result_ )
		return result_->getResult(i);

	return 0;
}

std::string Result::operator[](int i)
{
	if ( result_ )
		return result_->getResult(i)->getString();

	if ( myres_ )
		return row_[i];

	return 0;
}

Result& Result::operator=( MYSQL_RES* r )
{
	close();			
	myres_ = r;
	if (myres_)
		len_ = mysql_num_fields(myres_);		
	return *this;
}

Result& Result::operator=( ResultImpl* r )
{
	close();			
	result_ = r;
	myres_  = r->statement().meta();
	if (myres_)
		len_ = mysql_num_fields(myres_);
	return *this;
}

} // end namespace sql
} // end namespace mol


/*
std::ostream& operator<<( std::ostream& os, mol::sql::Retval& r)
{
	std::string tmp = r.getString();
	os << tmp;
	return os;
}
*/

std::ostream& operator<<( std::ostream& os, mol::sql::Retval* r )
{
	if ( r )
		os << r->getString();
	return os;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// example
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/*
int doConnect()
{
	try 
	{
		// init MySQL connection and choose DB
		mol::sql::Connection conn;
		conn.connect( "192.168.1.99", "mike", "betty1633" );
		conn.select_db("chat");
	
		// execute Query and iterate over result set
		mol::sql::Result result = conn.query( "SELECT msg.id, msg.msg FROM msg" );
		while ( MYSQL_ROW row = result.fetch() )
		{
			std::cout << row[0] << " : ";
			std::cout << row[1] << std::endl;
		}
	
		std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

		// prepared statement (ps) examples
	
		// create ps and prepare placeholder SQL 
		mol::sql::Statement stm(conn);
		stm.prepare("SELECT msg.id,msg.msg FROM msg WHERE msg.id < ? " );
	
		// set SQL Placeholder param and bind it
		mol::sql::Param param( 600 );
		stm.bind( param );
	
		// prepare return value Buffers for the result table cells
		// default type is MYSQL_TYPE_STRING with size 256
		mol::sql::Retval id(MYSQL_TYPE_LONG); 
		mol::sql::Retval msg(2048);			  // ( =MYSQL_TYPE_STRING with bufsize 2048);
	
		// bind return buffers and execute ps
		stm.execute( id, msg );

		// iterate over result rows, populating return val buffers
		while ( stm.fetch() )
		{
			// check for err/null before attempt to output
			if ( id() )
				std::cout << id.getShort()  << " : ";
			if ( msg() )
				std::cout << msg << std::endl;
		}
	}
	// catch SQL exceptions
	catch ( mol::sql::X& x )
	{
		std::cout << "SQL Error:" << std::endl;
		std::cout << x.what() << std::endl;
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	//int ret = doConnect();

	int t1 = mol::thread(&doConnect);
	int t2 = mol::thread(&doConnect);

	mol::Thread::wait(t1);
	mol::Thread::wait(t2);
	return 0;
}
*/
