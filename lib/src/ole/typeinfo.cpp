#include "ole/typeinfo.h"

namespace mol {


TypeInfo::TypeInfo()
{
	type_attr_ = 0;
	type_kind_ = (TYPEKIND)0;
}

TypeInfo::TypeInfo(const TypeInfo& t)
{
	type_attr_ = t.type_attr_;
	type_kind_ = t.type_kind_; 
	//t.type_info.queryInterface( IID_ITypeInfo, (void**)&type_info);
	t.type_info.queryInterface( &type_info);
}

TypeInfo::~TypeInfo(void)
{
	if ( type_attr_ )
		type_info->ReleaseTypeAttr(type_attr_);
}

ITypeInfo** TypeInfo::operator&()
{
	return &type_info;
}

mol::bstr* TypeInfo::funcNames(FUNCDESC* fd, UINT& cnames)
{
	mol::bstr* names;
	names = new  mol::bstr[fd->cParams+1];

	if ( S_OK == type_info->GetNames( fd->memid, (BSTR*)names, fd->cParams+1, &cnames ) )
	{
		return names;
	}
	cnames = 0;
	return 0;
}

TypeInfo TypeInfo::RefType(HREFTYPE rt)
{
	TypeInfo ti;
	if ( S_OK == type_info->GetRefTypeInfo(rt,&ti) )
	{
	}
	return ti;
}

HREFTYPE TypeInfo::getRefType(int i)
{
	HREFTYPE rt;
	if ( S_OK == type_info->GetRefTypeOfImplType(i, &rt ) )
	{
		return rt;
	}
	return 0;
}

HREFTYPE TypeInfo::getDualRefType()
{
	HREFTYPE rt;
	if ( S_OK == type_info->GetRefTypeOfImplType(-1, &rt ) )
	{
		return rt;
	}
	return 0;

}

std::wstring TypeInfo::reftype_name(HREFTYPE& rt)
{
	return TypeInfo::reftype_name(rt,MEMBERID_NIL);
}

std::wstring TypeInfo::reftype_name(HREFTYPE& rt, int i)
{
	mol::punk<ITypeInfo> t;
	if ( S_OK == type_info->GetRefTypeInfo(rt,&t) )
	{
		mol::bstr fname;
		t->GetDocumentation( i, &fname, NULL, 0, NULL );
		return fname.towstring();
	}
	return _T("");
}


std::wstring TypeInfo::variable_type(VARDESC* vd)
{ 
	return get_type(&(vd->elemdescVar.tdesc));
}


std::wstring TypeInfo::alias_type(TYPEATTR* ta)
{
	return get_type(&(ta->tdescAlias));
}

std::wstring TypeInfo::get_type(TYPEDESC* td)
{
	bool isPointer        = false;
	bool isPointerPointer = false;

	VARTYPE vt = type(td);
	if ( vt == VT_PTR )
	{
		isPointer = true;
		vt = pointer_type(td);
		if ( vt == VT_PTR )
		{
			isPointerPointer = true;
			vt = pointer_pointer_type(td);
			if ( vt == VT_USERDEFINED )
			{
				return user_pointer_pointer_type(td);
			}
		}
		else
		{
			if ( vt == VT_USERDEFINED )
			{
				return user_pointer_type(td);
			}
		}
	}
	else
	{
		if ( vt == VT_USERDEFINED )
		{
			return user_type(td);
		}
	}
	std::string ret = mol::ole::varnames[vt];
	if ( isPointer )
		ret += "*";
	if ( isPointerPointer )
		ret += "*";
	return towstring(ret);
}

VARTYPE TypeInfo::type(TYPEDESC* td)
{
	return td->vt;
}

VARTYPE TypeInfo::pointer_type(TYPEDESC* td)
{
	return td->lptdesc->vt;
}

VARTYPE TypeInfo::pointer_pointer_type(TYPEDESC* td)
{
	return td->lptdesc->lptdesc->vt;
}


std::wstring TypeInfo::user_type(TYPEDESC* td)
{
	return reftype_name(td->hreftype);
}

std::wstring TypeInfo::user_pointer_type(TYPEDESC* td)
{
	return reftype_name(td->lptdesc->hreftype) + _T("*");
}

std::wstring TypeInfo::user_pointer_pointer_type(TYPEDESC* td)
{
	return reftype_name(td->lptdesc->lptdesc->hreftype) + _T("**");
}


std::wstring TypeInfo::name()
{
	return name(MEMBERID_NIL);
}

std::wstring TypeInfo::name(int id)
{
	mol::bstr tname;
	type_info->GetDocumentation( id, &tname, NULL, 0, NULL );
	return tname.towstring();
}

FUNCDESC* TypeInfo::getFuncDesc(int i)
{
	FUNCDESC* fd;
	if ( S_OK == type_info->GetFuncDesc(i,&fd) )
		return fd;

	return 0;
}

VARDESC* TypeInfo::getVarDesc(int i)
{
	VARDESC* vd;
	if ( S_OK == type_info->GetVarDesc(i,&vd) )
		return vd;

	return 0;
}

void TypeInfo::releaseFuncDesc( FUNCDESC* fd )
{
	if ( fd )
		type_info->ReleaseFuncDesc(fd);
}

void TypeInfo::releaseVarDesc( VARDESC* vd )
{
	if ( vd )
		type_info->ReleaseVarDesc(vd);
}

TYPEATTR* TypeInfo::getAttr()
{
	if (type_attr_)
		return type_attr_;

	if ( S_OK == type_info->GetTypeAttr(&type_attr_) )
	{
		return type_attr_;
	}
	return 0;
}

std::wstring TypeInfo::param_type(FUNCDESC* fd ,int i)
{
	
	return get_type(&(fd->lprgelemdescParam[i].tdesc));
}

std::wstring TypeInfo::return_type(FUNCDESC* fd )
{
	return get_type(&(fd->elemdescFunc.tdesc));
}

////////////////////////////////////////////////////////////////

std::wstring FuncDesc::param_type(int i)
{
	return get_type(&(fd_->lprgelemdescParam[i].tdesc));
}

std::wstring FuncDesc::param_name(int i)
{
	std::wstring ret = funcNames_[i+1].towstring();
	if ( ret == _T("") )
		ret = _T("val");
	return ret;
}

std::wstring FuncDesc::return_type()
{
	return get_type(&(fd_->elemdescFunc.tdesc));
}

std::wstring FuncDesc::name()
{
	return funcNames_[0].towstring();
}

namespace ole {

const char* callconv[] =
{
   "__fastcall",
   "",
   "__pascal",
   "__pascal",
   "__stdcall",
   "FAR* __fastcall",
   "__syscall",
   "__notimpl",
   "__notimpl",
   "__notimpl"
};

//////////////////////////////////////////////////////////////////////////////////////////

const char* funkind[]  = {
	"virtual",
	"virtual", //"FUNC_PUREVIRTUAL",
	"", //"FUNC_NONVIRTUAL",
	"", //"FUNC_STATIC",
	"", //"FUNC_DISPATCH",
};

//////////////////////////////////////////////////////////////////////////////////////////

const char*  invkind[] = {
	"ERROR INV KIND",
	"INVOKE_FUNC = DISPATCH_METHOD",
	"INVOKE_PROPERTYGET = DISPATCH_PROPERTYGET",
	"INVOKE_PROPERTYPUT = DISPATCH_PROPERTYPUT",
	"INVOKE_PROPERTYPUTREF = DISPATCH_PROPERTYPUTREF"
};

//////////////////////////////////////////////////////////////////////////////////////////

const char* varnames[] = {
"VT_EMPTY",
"VT_NULL",
"short", //"VT_I2",
"long", //"VT_I4",
"float", //"VT_R4",
"double", //"VT_R8",
"CY", //"VT_CY",
"DATE", //"VT_DATE",
"BSTR", //"VT_BSTR",
"IDispatch*", //"VT_DISPATCH",
"VT_ERROR",
"VARIANT_BOOL", //"VT_BOOL",
"VARIANT", //"VT_VARIANT",
"IUnknown*", //"VT_UNKNOWN",
"VT_DECIMAL",
"!!!! ERRR",
"char", //"VT_I1",
"unsigned char", //"""VT_UI1",
"unsigned short",
"unsigned long",
"longlong",
"unsinged longlong",
"int",
"unsigned int",
"void",
"HRESULT",
"VT_PTR",
"SAFEARRAY",
"VT_CARRAY",
"VT_USERDEFINED",
"char",
"wchar_t",
"VT_RECORD",
"int*",
"unsigned int *",
"FILETIME",
"VT_BLOB",
"IStream",
"IStorage",
"VT_STREAMED_OBJECT",
"VT_STORED_OBJECT",
"VT_BLOB_OBJECT",
"VT_CF",
"GUID",
"VT_VERSIONED_STREAM",
"VT_BSTR_BLOB",
"VT_VECTOR",
"VT_ARRAY",
"VT_BYREF",
"VT_RESERVED",
"VT_ILLEGAL",
"VT_ILLEGALMASKED",
"VT_TYPEMASK"

};

} // end namespace ole

} // end namespace mol