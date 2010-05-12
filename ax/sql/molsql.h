#ifndef _MOL_COM_DLL_COMTYPES_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_COMTYPES_DEF_DEFINE_GUARD_

#include "ole/ole.h"
#include "ole/ole.h"
#include "ole/obj.h"
#include "ole/cp.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/aut.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
#include <list>
#include <map>
#include <set>
#include <vector>

#include "sql_h.h"
#include "mysql/molsql.h"

using namespace mol;

////////////////////////////////////////////////////////////////////////
// MySQL COM connector
////////////////////////////////////////////////////////////////////////

class Row : 
	public Dispatch<IMyRow>,
	public SupportsErrorInfo<&IID_IMyRow>,
	public interfaces< Row, 
			implements< 
				IDispatch, 
				IMyRow,
				ISupportErrorInfo
			> >
{
public:

	Row();

	virtual void dispose();

	typedef com_obj<Row> Instance;
	static  Instance* CreateInstance( IMyResult* ref, int nfields, sql::Result& );
	static  Instance* CreateInstance( IMyResult* ref, int nfields, sql::Retval** fields );

	HRESULT virtual __stdcall _NewEnum( IEnumVARIANT** newEnum);
	HRESULT virtual __stdcall Field( VARIANT i, VARIANT* cell);
	HRESULT virtual __stdcall get_Fields( long* cnt);

	mol::COMCollection row_;
	int fields_;

	punk<IMyResult> ref_;
};

class Statement;

class Result : 
	public Dispatch<IMyResult>,
	public SupportsErrorInfo<&IID_IMyResult>,
	public interfaces< Result, 
			implements< 
				IDispatch, 
				IMyResult,
				ISupportErrorInfo
			> >
{
public:

	Result();

	virtual void dispose();

	typedef com_obj<Result> Instance;
	static  Instance* CreateInstance( IMySQL* ref, sql::Connection* conn, sql::Result& result );
	static  Instance* CreateInstance( IMyStatement* ref, Statement* st );

	HRESULT virtual __stdcall Fetch( IMyRow** row);
	HRESULT virtual __stdcall get_XML( BSTR* doc );

	sql::Connection*	conn_;
	sql::Result*		result_;
	Statement*			statement_;

	punk<IUnknown>		ref_;
};

class Statement : 
	public mol::Dispatch<IMyStatement>,
	public SupportsErrorInfo<&IID_IMyStatement>,
	public mol::interfaces< Statement,
			mol::implements<
				IMyStatement,
				IDispatch,
				ISupportErrorInfo
				> >
{
public:

	Statement();

	virtual void dispose();

	typedef com_obj<Statement> Instance;
	static  Instance* CreateInstance( IMySQL* ref, sql::Connection* conn, BSTR sql  );

	HRESULT virtual __stdcall Bind( long index, VARIANT value );
	HRESULT virtual __stdcall Execute( VARIANT_BOOL* vbSuccess );
	HRESULT virtual __stdcall Query( IMyResult** result );
	HRESULT virtual __stdcall Reset();

	sql::Connection*	conn_;
	sql::Statement*		st_;

	sql::Param**		params_;
	sql::Retval**		fields_;
	punk<IMySQL>		ref_;
};


class SQL : 
	public mol::com_creatable<SQL,CLSID_MySQL>,
	public mol::Dispatch<IMySQL>,
	public SupportsErrorInfo<&IID_IMySQL>,
	public mol::interfaces< SQL,
			mol::implements<
				IMySQL,
				IDispatch,
				ISupportErrorInfo
				> >
{
public:

	SQL();

	virtual void dispose();

	HRESULT virtual __stdcall Connect( BSTR host, BSTR user, BSTR pwd, long port, VARIANT_BOOL* vbSuccess);
	HRESULT virtual __stdcall SelectDB( BSTR db, VARIANT_BOOL* vbSuccess);
	HRESULT virtual __stdcall Ececute( BSTR sql, VARIANT_BOOL* vbSuccess);
	HRESULT virtual __stdcall Query( BSTR sql, IMyResult** result);
	HRESULT virtual __stdcall Escape( BSTR str, BSTR* result);
	HRESULT virtual __stdcall Prepare( BSTR sql, IMyStatement** statement);
	HRESULT virtual __stdcall get_Error( BSTR* msg );

	sql::Connection conn_;
};

#endif