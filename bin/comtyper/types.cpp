// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "types.h"

using namespace mol::ole;

bool TypeLib2XML::loadTypeLib(const std::wstring path)
{
	iMap.clear();
	coMap.clear();
	enumMap.clear();
	aliasMap.clear();
	recordMap.clear();

	if (!tl.load(path))
	{
		std::cout << "load typelib " << mol::tostring(path) << " failed" << std::endl;
		return false;
	}
	filename = path;
	for ( int i = 0; i < tl.typeInfoCount(); i++ )
	{
		MetaClass meta(tl.getName(i), tl.getGUID(i) );

		mol::TypeInfo ti;
		if ( S_OK == tl.item(i, &ti ) )
		{			
			switch ( ti.getAttr()->typekind )
			{
				case TKIND_ENUM:
				{
					tl_enum(ti,i,meta);
					break;
				}
				case TKIND_RECORD:
				{
					tl_record(ti,i,meta);
					break;
				}
				case TKIND_MODULE:
				{
					break;
				}
				case TKIND_INTERFACE:
				{
					tl_interface(ti,i,meta);
					iMap.push_back(meta);
					break;
				}
				case TKIND_DISPATCH:
				{
					tl_dispatch(ti,i, meta);
					iMap.push_back(meta);
					break;
				}
				case TKIND_COCLASS:
				{
					for ( int i = 0; i < ti.getAttr()->cImplTypes; i++ )
					{									
						HREFTYPE hrt = ti.getRefType(i);
						std::wstring n = ti.reftype_name(hrt);
						
						MetaClass mc(n,ti.getAttr()->guid);
				
						INT flags = 0;
						ti.type_info->GetImplTypeFlags(i,&flags);

						if ( flags & IMPLTYPEFLAG_FRESTRICTED )
							break;
						if ( flags & IMPLTYPEFLAG_FSOURCE )
							mc.isSource = true;
						if ( flags & IMPLTYPEFLAG_FDEFAULT )
							mc.isDefault = true;

						meta.interfaces.push_back(mc);
					}

					meta.major = tl.major();
					meta.minor = tl.minor();

					meta.progId = tl.getName() + _T(".") + meta.type;
					bstr doc;
					tl->GetDocumentation(MEMBERID_NIL,0,&doc,0,0);
					meta.desc = doc.towstring();

					coMap.push_back(meta);
				
					break;
				}
				case TKIND_ALIAS:
				{
					tl_typedef(ti,i, meta);
					break;
				}
				case TKIND_UNION:
				{
					break;
				}
			}
		}
	}
	return true;
}

std::wstring TypeLib2XML::getXML()
{
	std::wostringstream oss;

	// typelib element
	oss << _T("<typelib name='") << tl.getName() << _T("' ") << std::endl;
	oss << _T("desc='") << tl.getDescription() << _T("' ") << std::endl;
	oss << _T("typeinfocount='") << tl.typeInfoCount()  << _T("' ") << std::endl;
	oss << _T("guid='") << mol::stringFromCLSID(tl.getGUID())  << _T("' ") << std::endl;
	oss << _T("major='") << tl.major() << _T("' ") << std::endl;
	oss << _T("minor='") << tl.minor() << _T("' ") << std::endl;
	oss << _T("file='") << filename << _T("'>") << std::endl;

	oss << std::endl;

	// interfaces
	for ( std::list<MetaClass>::iterator it = iMap.begin(); it != iMap.end(); it++ )
	{
		oss << (*it).out() << std::endl;
	}
	oss << std::endl;

	// objects
	for ( std::list<MetaClass>::iterator it = coMap.begin(); it != coMap.end(); it++ )
	{
		oss << (*it).out_obj();			
	}
	oss << std::endl;

	// enums
	for ( std::list<MetaEnum>::iterator it = enumMap.begin(); it != enumMap.end(); it++ )
	{
		oss << (*it).out() << std::endl;
	}
	oss << std::endl;

	// aliases (typedefs)
	for ( std::list<MetaParam>::iterator it = aliasMap.begin(); it != aliasMap.end(); it++ )
	{
		oss << (*it).out_alias() << std::endl;
	}
	oss << std::endl;

	// records (user structs)
	for ( std::list<MetaRecord>::iterator it = recordMap.begin(); it != recordMap.end(); it++ )
	{
		oss << (*it).out() << std::endl;
	}
	oss << std::endl;

	oss << _T("</typelib>") << std::endl;

	return oss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////

void TypeLib2XML::tl_funcdesc(mol::TypeInfo& ti, MetaClass& meta, int fi )
{
	FUNCDESC* fd = ti.getFuncDesc(fi);
	if (!fd )
		return;

	std::wstring name = ti.name(fd->memid);
	if ( name == _T("CodeBehind") )
	{
		int i = 0;
	}
	bool isPointer = false;
	bool isPointerPointer = false;

	MetaFunc metafunc(name,ti.return_type(fd));

	metafunc.funkind = towstring(mol::ole::funkind[fd->funckind]);
	if ( fd->callconv == CC_STDCALL )
		metafunc.isStdCall = true;

	int k = fd->invkind;
	switch ( k )
	{
		case INVOKE_PROPERTYGET : 
		{
			metafunc.isPropGet = true;
			break;
		}
		case INVOKE_PROPERTYPUT : 
		{
			metafunc.isPropPut = true;
			break;
		}
		case INVOKE_PROPERTYPUTREF : 
		{
			metafunc.isPropPutRef = true;
			break;
		}
	}

	UINT cnames = 0;
	mol::bstr* names = ti.funcNames(fd,cnames);

	for ( unsigned int j = 1; j < cnames; j++ )
	{
		MetaParam metaparam( ti.param_type(fd,j-1), names[j].towstring() );

		if ( fd->lprgelemdescParam[j-1].paramdesc.wParamFlags & PARAMFLAG_FRETVAL )
		{
			metaparam.isRetVal = true;
		}
		if ( fd->lprgelemdescParam[j-1].paramdesc.wParamFlags & PARAMFLAG_FIN )
		{
			metaparam.isIn = true;
		}
		if ( fd->lprgelemdescParam[j-1].paramdesc.wParamFlags & PARAMFLAG_FOUT )
		{
			metaparam.isOut = true;
		}
		metafunc.params.push_back(metaparam);
	}

	for ( unsigned int j = cnames-1; j < (unsigned int)fd->cParams; j++ )
	{
		std::wostringstream oss;
		oss << _T("param") << j;
		MetaParam metaparam( ti.param_type(fd,j), oss.str() );

		if ( fd->lprgelemdescParam[j].paramdesc.wParamFlags & PARAMFLAG_FRETVAL )
		{
			metaparam.isRetVal = true;
		}
		if ( fd->lprgelemdescParam[j].paramdesc.wParamFlags & PARAMFLAG_FIN )
		{
			metaparam.isIn = true;
		}
		if ( fd->lprgelemdescParam[j].paramdesc.wParamFlags & PARAMFLAG_FOUT )
		{
			metaparam.isOut = true;
		}
		metafunc.params.push_back(metaparam);
	}
	delete[] names;

	metafunc.dispid = fd->memid;
	metafunc.vtindex = fd->oVft;
	bstr doc;
	ti.type_info->GetDocumentation(fd->memid,0,&doc,0,0);
	metafunc.desc = doc.towstring();

	std::list<MetaFunc>::iterator it = meta.functions.begin();
	for ( it; it != meta.functions.end(); it++)
	{
		if ( (*it).name == metafunc.name )
		{
			if ( metafunc.isPropGet )
				(*it).isPropGet = true;
			if ( metafunc.isPropPut )
				(*it).isPropPut = true;
			if ( metafunc.isPropPutRef )
				(*it).isPropPutRef = true;
			break;
		}
	}
	if ( it == meta.functions.end() )
		meta.functions.push_back(metafunc);
	ti.releaseFuncDesc(fd);
}

//////////////////////////////////////////////////////////////////////////////////////////

void TypeLib2XML::tl_dispatch(mol::TypeInfo& ti, int index, MetaClass& meta )
{
	TYPEKIND tk = ti.getAttr()->typekind;

	HREFTYPE rt = ti.getDualRefType();

	// dual
	if ( rt )
	{
		meta.isDual = true;
		meta.isDisp = true;
		mol::TypeInfo t = ti.RefType(rt);
		tl_interface(t,index,meta);
	}

	// impl types
	for ( int i = 0; i < ti.getAttr()->cImplTypes; i++ ) 
	{
		HREFTYPE rt = ti.getRefType(i);
		if ( rt )
		{
			meta.base = ti.reftype_name(rt);
		}
	}

	// Dispatcheria	
	if ( !meta.isDual )
	{
		if ( (ti.getAttr()->wTypeFlags) & TYPEFLAG_FDUAL )
		{
			meta.isDual = true;
			for ( int i = 7; i < ti.getAttr()->cFuncs; i++ )
			{
				tl_funcdesc( ti, meta, i );
			}

		}
		else
		for ( int i = 0; i < ti.getAttr()->cFuncs; i++ )
		{
			tl_funcdesc( ti, meta, i );
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void TypeLib2XML::tl_interface( mol::TypeInfo&  ti, int index, MetaClass& meta )
{
	for ( int i = 0; i < ti.getAttr()->cFuncs; i++ )
	{
		tl_funcdesc(ti, meta, i );
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void TypeLib2XML::tl_enum( mol::TypeInfo&  ti, int index, MetaClass& meta )
{
	MetaEnum metaenum(meta.type);
	for ( int i = 0; i < ti.getAttr()->cVars; i++ )
	{
		VARDESC* vd = ti.getVarDesc(i);
		std::wostringstream oss;
		oss << (vd->lpvarValue->lVal);

		MetaParam metaparam(ti.name(vd->memid),oss.str());
		metaenum.enums.push_back(metaparam);

		ti.releaseVarDesc(vd);

	}
	enumMap.push_back(metaenum);
}


//////////////////////////////////////////////////////////////////////////////////////////

void TypeLib2XML::tl_typedef( mol::TypeInfo&  ti, int index, MetaClass& meta )
{
	MetaParam metaparam( meta.type, ti.alias_type(ti.getAttr()) );
	aliasMap.push_back(metaparam);
}

//////////////////////////////////////////////////////////////////////////////////////////

void TypeLib2XML::tl_record( mol::TypeInfo&  ti, int index, MetaClass& meta )
{
	MetaRecord metarecord(meta.type);
	for ( int i = 0; i < ti.getAttr()->cVars; i++ )
	{
		VARDESC* vd = ti.getVarDesc(i);
		MetaParam metaparam(ti.variable_type(vd),ti.name(vd->memid));	
		metarecord.members.push_back(metaparam);

		ti.releaseVarDesc(vd);
		recordMap.push_back(metarecord);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

/*
int main(int argc, char* argv[])
{
	mol::ole::com_init ci;

	if ( argc < 2 )
		return 0;

	std::wstring tl_name = argv[1];//"C:\\Programme\\Microsoft Office\\OFFICE11\\excel.exe"; //argv[1];

	TypeLib2XML tl2x;
	if ( tl2x.loadTypeLib(tl_name) )
	{
		std::cout << tl2x.getXML();
		return 0;
	}
	std::cout << "could not load typelib " << tl_name << std::endl;
	return 1;
}
*/

