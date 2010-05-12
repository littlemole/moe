#include "stdafx.h"
#include "molsql.h"

using namespace mol;

Row::Row()
{

}

void Row::dispose()
{
}

Row::Instance* Row::CreateInstance( IMyResult* ref, int nfields, sql::Result& result )
{
	Instance* r = new Instance;
	r->ref_     = ref;
	r->fields_  = nfields;
	for ( int i = 0; i < nfields; i++ )
	{
		//variant v( mol::utf82wstring( (char*)row[i] ));
		variant v( mol::utf82wstring(result[i]) );
		r->row_.Add(v);
	}
	return r;
}

Row::Instance* Row::CreateInstance( IMyResult* ref, int nfields, sql::Retval** fields )
{
	if (!fields)
		return 0;

	Instance* r = new Instance;
	r->ref_     = ref;
	r->fields_  = nfields;
	for ( int i = 0; i < nfields; i++ )
	{
		sql::Retval* f = fields[i];
		variant v( mol::utf82wstring( f->getString() ));
		r->row_.Add(v);
	}
	return r;
}

HRESULT __stdcall Row::_NewEnum( IEnumVARIANT** newEnum)
{
	return row_._NewEnum(newEnum);
}

HRESULT __stdcall Row::Field( VARIANT i, VARIANT* cell)
{
	return row_.Item(i,cell);
}

HRESULT __stdcall Row::get_Fields( long* cnt)
{
	variant v;
	HRESULT hr = row_.Count(&v);
	if (hr!=S_OK)
		return hr;
	*cnt = v.intVal;
	return S_OK;
}




Result::Result()
	:result_(0),statement_(0)
{
}

void Result::dispose()
{
	if ( result_ )
		delete result_;
	result_ = 0;
}


Result::Instance* Result::CreateInstance( IMySQL* ref, sql::Connection* conn, sql::Result& result )
{
	Instance* r = new Instance;
	r->ref_     = ref;
	r->conn_    = conn;
	r->result_  = &result;
	return r;
}

Result::Instance* Result::CreateInstance( IMyStatement* ref, Statement* st )
{
	if (!st)
		return 0;

	Instance* r   = new Instance;
	r->ref_       = ref;
	r->conn_      = st->conn_;
	r->statement_ = st;
	return r;
}


/*HRESULT __stdcall Result::get_IsValid( VARIANT_BOOL* vb)
{
	if ( !vb)
		return E_INVALIDARG;
	*vb = result_ ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
*/
HRESULT __stdcall Result::Fetch( IMyRow** row)
{
	if ( !row)
		return E_INVALIDARG;

	*row = 0;

	try 
	{
		if ( result_ )
		{
			bool success = result_->fetch();
			if (!success)
				return S_OK;
			
			punk<IMyRow> r = Row::CreateInstance( (IMyResult*)this, result_->fields(),*result_ );
			if ( r )
				return r->QueryInterface( IID_IMyRow, (void**) row );

		}
	}
	catch( sql::X )
	{
		com_throw( conn_->err(), IID_IMyResult, "molSQL.MySQL" );
		return E_FAIL;
	}

	return E_UNEXPECTED;
}

HRESULT __stdcall Result::get_XML( BSTR* doc )
{
	if ( !doc)
		return E_INVALIDARG;

	std::ostringstream oss;

	oss << "<table>";

	if ( result_ )
	{
		oss << "<tr>";
		for ( int i = 0; i < result_->fields(); i++ )
		{
			oss << "<th>";
			MYSQL_FIELD* f = result_->field(i);
			oss << mol::xmlentities_encode( f->name );
			oss << "</th>";
		}
		oss << "</tr>";

		while ( result_->fetch() )
		{
			oss << "<tr>";
		
			for ( int i = 0; i < result_->fields(); i++ )
			{
				oss << "<td>";
				oss << mol::xmlentities_encode( (*result_)[i] );
				oss << "</td>";
			}

			oss << "</tr>";
		}
	}
	oss << "</table>";

	*doc = ::SysAllocString( mol::utf82wstring( oss.str() ).c_str() );
	return S_OK;
}




Statement::Statement()
	:conn_(0),st_(0),params_(0),fields_(0)
{

}

void Statement::dispose()
{
	for ( int i = 0; i < st_->fields(); i++ )
	{
		if ( fields_[i] )
		{
			delete fields_[i];
			fields_[i] = 0;
		}
	}

	for ( int i = 0; i < st_->params(); i++ )
	{
		if ( params_[i] )
		{
			delete params_[i];
			params_[i] = 0;
		}
	}

	delete[] fields_;
	fields_ = 0;

	delete[] params_;
	params_ = 0;

	delete st_;

	st_   = 0;
	conn_ = 0;
}


Statement::Instance* Statement::CreateInstance( IMySQL* ref, sql::Connection* conn, BSTR sql  )
{
	Instance* s = new Instance;
	try 
	{
		s->ref_  = ref;
		s->conn_ = conn;
		s->st_   = new sql::Statement(*conn);

		const my_bool mb = 1;
		s->st_->attr( STMT_ATTR_UPDATE_MAX_LENGTH, &mb );    
			
		s->st_->prepare( mol::BSTR2ansi(sql) );

		if ( s->st_->params() > 0 )
			s->params_ = new sql::Param* [s->st_->params()];

		memset( s->params_, 0, sizeof(sql::Param*) * s->st_->params() );

		if ( s->st_->fields() > 0 )
			s->fields_ = new sql::Retval* [s->st_->fields()];

		memset( s->fields_, 0, sizeof(sql::Retval*) * s->st_->fields() );

/*		for ( int i = 0; i < s->st_->fields(); i++ )
		{
			int type    = s->st_->field_type(i);
			if ( (type == MYSQL_TYPE_STRING) || (type == MYSQL_TYPE_VAR_STRING) || (type == MYSQL_TYPE_BLOB) )
			{
				int maxsize = s->st_->field_maxlength(i);
				if ( maxsize == 0 )
					maxsize = 1024;
				s->fields_[i] = new sql::Retval( (enum_field_types)type,maxsize);
			}
			else
			{
				s->fields_[i] = new sql::Retval(type);
			}
		}
*/		
	}
	catch( mol::sql::X& )
	{
		com_throw( s->conn_->err(), IID_IMyResult, "molSQL.MySQL" );
		delete s;
		return 0;
	}
	return s;
}

HRESULT __stdcall Statement::Bind( long index, VARIANT value )
{
	if ( index < 0 || index >= st_->params() )
	{
		com_throw( "bind index out of bounds", IID_IMyStatement, "molSQL.MySQL" );
		return E_UNEXPECTED;
	}

	if ( params_[index] != 0 )
	{
		delete params_[index];
//		com_throw( "tried to bind to query with zero params", IID_IMyStatement, "molSQL.MySQL" );
//		return E_UNEXPECTED;
	}

	variant val(value);
	val.changeType(VT_BSTR);

	st_->bind(index,new sql::Param( val.toString() ));

	return S_OK;
}

HRESULT __stdcall Statement::Execute( VARIANT_BOOL* vbSuccess )
{
	if ( !vbSuccess )
		return E_INVALIDARG;

	if ( st_->execute() )
		return S_OK;

	com_throw( st_->conn().err(), IID_IMyStatement, "molSQL.MySQL" );

	return E_FAIL;
}

HRESULT __stdcall Statement::Query( IMyResult** result )
{
	if ( !result )
		return E_INVALIDARG;

	if ( st_->fields() == 0 )
	{
		com_throw( "tried to retrieve results from query with no results", IID_IMyStatement, "molSQL.MySQL" );
		return E_UNEXPECTED;
	}


	HRESULT hr = E_FAIL;
	if ( st_->execute() )
	{

		for ( int i = 0; i < st_->fields(); i++ )
		{
			if ( fields_[i] != 0 )
				delete fields_[i];

			int type    = st_->field_type(i);
			if ( (type == MYSQL_TYPE_STRING) || (type == MYSQL_TYPE_VAR_STRING) || (type == MYSQL_TYPE_BLOB) )
			{
				int maxsize = st_->field_maxlength(i);
				if ( maxsize == 0 )
					maxsize = 1024;
				fields_[i] = new sql::Retval( (enum_field_types)type,maxsize);
			}
			else
			{
				fields_[i] = new sql::Retval((enum_field_types)type);
			}
		}
	}

	if ( hr != S_OK )
	{
		com_throw( st_->conn().err(), IID_IMyStatement, "molSQL.MySQL" );
		return hr;
	}



	punk<IMyResult> res = Result::CreateInstance( (IMyStatement*)this, this );
	return res->QueryInterface( IID_IMyResult, (void**) result );

}

HRESULT __stdcall Statement::Reset()
{
	st_->reset();
	return S_OK;
}


SQL::SQL()
{

}

void SQL::dispose()
{
	conn_.close();
}

HRESULT __stdcall SQL::Connect( BSTR host, BSTR user, BSTR pwd, long port, VARIANT_BOOL* vbSuccess)
{
	if ( !vbSuccess)
		return E_INVALIDARG;

	*vbSuccess = VARIANT_FALSE;
	
	try 
	{
		conn_.connect( bstr(host).tostring(), bstr(user).tostring(), bstr(pwd).tostring(), port );			
	}
	catch( sql::X )
	{
		com_throw( conn_.err(), IID_IMySQL, "molSQL.MySQL" );
		return S_OK;
	}

	*vbSuccess = VARIANT_TRUE;
	return S_OK;
}

HRESULT __stdcall SQL::SelectDB( BSTR db, VARIANT_BOOL* vbSuccess)
{
	if ( !vbSuccess)
		return E_INVALIDARG;

	*vbSuccess = VARIANT_FALSE;
	
	try 
	{
		conn_.select_db( bstr(db).tostring() );			
	}
	catch( sql::X )
	{
		com_throw( conn_.err(), IID_IMySQL, "molSQL.MySQL" );
		return S_OK;
	}

	*vbSuccess = VARIANT_TRUE;
	return S_OK;
}

HRESULT __stdcall SQL::Ececute( BSTR sql, VARIANT_BOOL* vbSuccess)
{
	if ( !vbSuccess)
		return E_INVALIDARG;

	*vbSuccess = VARIANT_FALSE;
	
	try 
	{
		conn_.execute( bstr(sql).tostring() );			
	}
	catch( sql::X )
	{
		com_throw( conn_.err(), IID_IMySQL, "molSQL.MySQL" );
		return S_OK;
	}

	*vbSuccess = VARIANT_TRUE;
	return S_OK;
}

HRESULT __stdcall SQL::Query( BSTR sql, IMyResult** result)
{
	if ( !result)
		return E_INVALIDARG;

	*result = 0;
	
	try 
	{
		//MYSQL_RES* r = conn_.query( bstr(sql).tostring() );			
		sql::Result r = conn_.query( bstr(sql).tostring() );			
		punk<IMyResult> p = Result::CreateInstance( (IMySQL*)this, &conn_, r );
		return p->QueryInterface( IID_IMyResult, (void**) result );
	}
	catch( sql::X )
	{
		com_throw( conn_.err(), IID_IMySQL, "molSQL.MySQL" );
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall SQL::Escape( BSTR str, BSTR* result)
{
	if (!result)
		return E_INVALIDARG;

	std::string utf8 = mol::wstring2utf8( str );
	std::string escaped = conn_.escape( utf8 );
	*result = ::SysAllocString( mol::utf82wstring(escaped).c_str() );
	return S_OK;
}

HRESULT __stdcall SQL::Prepare( BSTR sql, IMyStatement** statement)
{
	if (!statement)
		return E_INVALIDARG;

	punk<IMyStatement> st = Statement::CreateInstance( (IMySQL*)this, &conn_, sql );
	if (!st)
		return E_FAIL;
	return st->QueryInterface( IID_IMyStatement, (void**) statement );
}


HRESULT __stdcall SQL::get_Error( BSTR* msg )
{
	if (!msg)
		return E_INVALIDARG;

	std::string err = conn_.err();

	if ( err.empty() )
		*msg = 0;
	else
		*msg = ::SysAllocString( mol::towstring(err).c_str() );

	return S_OK;
}

