#ifndef MOL_DEFINE_TYPEINF_DEF_GUARD_
#define MOL_DEFINE_TYPEINF_DEF_GUARD_

#include "ole/ole.h"
#include "ole/ole.h"
#include "ole/obj.h"
#include "ole/bstr.h"
#include "ole/typelib.h"
#include <list>

namespace mol {

namespace ole {
//////////////////////////////////////////////////////////////////////////////////////////

extern const char* callconv[];

//////////////////////////////////////////////////////////////////////////////////////////

extern const char* funkind[];

//////////////////////////////////////////////////////////////////////////////////////////

extern const char*  invkind[];

//////////////////////////////////////////////////////////////////////////////////////////

extern const char* varnames[];

//////////////////////////////////////////////////////////////////////////////////////////

class FuncDesc;

} // end namespace ole

//////////////////////////////////////////////////////////////////////////////////////////

class TypeInfo
{
public:

	TypeInfo();
	TypeInfo(const TypeInfo& t);
	virtual ~TypeInfo(void);

	ITypeInfo** operator&();

	TypeInfo RefType(HREFTYPE rt);
	HREFTYPE getRefType(int i);
	HREFTYPE getDualRefType();

	mol::bstr* funcNames(FUNCDESC* fd, UINT& cnames);


	mol::string reftype_name(HREFTYPE& rt);
	mol::string reftype_name(HREFTYPE& rt, int i);

	mol::string variable_type(VARDESC* vd);
	mol::string alias_type(TYPEATTR* ta);

	mol::string name();
	mol::string name(int id);

	FUNCDESC* getFuncDesc(int i);
	VARDESC* getVarDesc(int i);

	void releaseFuncDesc( FUNCDESC* fd );
	void releaseVarDesc( VARDESC* vd );

	TYPEATTR* getAttr();
	mol::string get_type(TYPEDESC* td);

	mol::string param_type(FUNCDESC* fd ,int i);
	mol::string return_type(FUNCDESC* fd );

	mol::punk<ITypeInfo>		type_info;

protected:

	VARTYPE type(TYPEDESC* td);
	VARTYPE pointer_type(TYPEDESC* td);
	VARTYPE pointer_pointer_type(TYPEDESC* td);
	mol::string user_type(TYPEDESC* td);
	mol::string user_pointer_type(TYPEDESC* td);
	mol::string user_pointer_pointer_type(TYPEDESC* td);

	TYPEATTR* type_attr_;
	TYPEKIND  type_kind_;

};

//////////////////////////////////////////////////////////////////////////////////////////


class FuncDesc
{
friend class TypeInfo;
public:
	FuncDesc(TypeInfo& ti, int i)
		: id_(i), ti_(ti)
	{
		fd_ = ti_.getFuncDesc(id_);
		funcNames_ = new  mol::bstr[fd_->cParams+1];

		if ( S_OK != ti_.type_info->GetNames( fd_->memid, (BSTR*)funcNames_, fd_->cParams+1, &cFuncNames_ ) )
		{
			cFuncNames_ = 0;
		}
	}

	~FuncDesc()
	{
		delete[] funcNames_;
		ti_.releaseFuncDesc(fd_);
	}

	int nParams() 
	{ 
		return fd_->cParams;
	}

	mol::string c_signature()
	{
		mol::ostringstream oss;

		oss << return_type() << _T(" ");
		oss << name() << _T("( ");

		for ( int i = 0; i < nParams(); i++ )
		{
			oss << param_type(i) << _T(" ");
			oss << param_name(i);
			if ( i < nParams()-1 )
				oss << _T(", ");
		}

		oss << _T(" );");

		return oss.str();
	}

	mol::string script_signature()
	{
		mol::ostringstream oss;
	
		if ( fd_->invkind != INVOKE_FUNC)
		{
			oss << name();
		}
		else
		{	
			if ( return_type() != _T("void") )
				oss << _T("val ");
			oss << name();

			oss << _T("(");
			for ( int i = 0; i < nParams(); i++ )
			{
				mol::string s = param_name(i);
				if ( s == _T("") )
					oss << _T(" ") << param_type(i);
				else
					oss << _T(" ") << s;
				if ( i < nParams()-1 )
					oss << _T(", ");
				else
					oss << _T(" ");
			}
		}
		if ( fd_->invkind == INVOKE_FUNC)
			oss << _T(")");

		return oss.str();
	}

	mol::string name();
	mol::string param_type(int i);
	mol::string param_name(int i);
	mol::string return_type();

	FUNCDESC* fd_;

private:
	int id_;
	TypeInfo& ti_;
	mol::bstr* funcNames_;
	unsigned int cFuncNames_;

	mol::string get_type(TYPEDESC* td)
	{
		return ti_.get_type(td);
	}

};

} // end namespace mol

#endif

