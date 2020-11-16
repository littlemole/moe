#include "StdAfx.h"
#include "Meta.h"

std::wstring encode( const std::wstring& s )
{
	std::wstring val = mol::xmlentities_encode(s);
	std::wostringstream out;
    size_t p = 0;
    size_t len = s.size();
    while( ( p < len ) )
    {
        switch ( s[p] )
        {
            case _T('\'') :
            {
                out << _T("&apos;");
                break;
            }
			default :
			{
				out << s[p];
			}
		}
        p++;
    }
    return out.str();
}

MetaParam::MetaParam()
	: isPointer(false),isPointerPointer(false)
{}

MetaParam::MetaParam( const std::wstring& t, const std::wstring& n  )
	: name(n), type (t), isPointer(false),isPointerPointer(false), isRetVal(false),isIn(false),isOut(false)
{}

std::wstring MetaParam::out()
{
	std::wostringstream oss;
	oss << _T("  <param type='") << type;
	if ( isPointer )
		oss << _T("*");
	if ( isPointerPointer )
		oss << _T("*");
	if ( isIn || isOut )
	{
		oss << _T("' dir='");
		if ( isIn )
			oss << _T("IN");
		if ( isIn && isOut )
			oss << _T(",");
		if ( isOut )
			oss << _T("OUT");
	}
	oss << _T("' name='") << name << _T("' />");
	oss << std::endl;
	return oss.str();
}

std::wstring MetaParam::out_alias()
{
	std::wostringstream oss;
	oss << _T("<alias name='") << name 
		<< _T("' type='") << type 
		<< _T("' />") << std::endl;
	return oss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////


MetaFunc::MetaFunc()
	: isPointer(false),isDisp(false),isStdCall(false),isPropPut(false),isPropPutRef(false),isPropGet(false)
{}

MetaFunc::MetaFunc( const std::wstring& n, const std::wstring& t  )
	: name(n), type (t), isPointer(false),isDisp(false),isStdCall(false),isPropPut(false),isPropPutRef(false),isPropGet(false)
{

}


std::wstring MetaFunc::out()
{
	std::wostringstream oss;

	if ( isPropGet || isPropPut || isPropPutRef )
	{
		oss << _T(" <property name='") << name << _T("' ");
		oss << _T("type='") ;
		if ( !params.empty() )
			oss << params.front().type;
		oss << _T("' ");

		oss << _T("dispid='") << dispid << _T("' ");
		oss << _T("vtindex='") << vtindex << _T("' ");
		oss << _T("ctype='") << type << _T("' ");
		oss << _T("param='");
		if ( !params.empty() )
			oss << params.front().name;
		oss << _T("' ");
		oss << _T("desc='") << encode(desc) << _T("' ");
		if ( funkind != _T("") )
			oss << _T(" funkind='") << funkind << _T("' ");
		if ( isStdCall )
			oss << _T(" calltype='__stdcall' ");

		oss << _T(">") << std::endl;

		if ( isPropGet )
		{
			oss << _T(" <get />") << std::endl;
		}
		if ( isPropPut )
		{
			oss << _T(" <put />") << std::endl;
		}
		if ( isPropPutRef )
		{
			oss << _T(" <putref />") << std::endl;
		}
		oss << _T("</property>") << std::endl;
	}
	else
	{
		oss << _T(" <method name='") << name << _T("' type='");

		if ( (params.size() > 0) && (params.back().isRetVal) )
			oss << params.back().type;
		else
			oss << _T("void");

		oss << _T("' ");
		oss << _T("dispid='") << dispid << _T("' ");
		oss << _T("vtindex='") << vtindex << _T("' ");
		oss << _T("ctype='") << type << _T("' ");
		if ( funkind != _T("") )
			oss << _T(" funkind='") << funkind << _T("' ");
		if ( isStdCall )
			oss << _T(" calltype='__stdcall' ");

		oss << _T("desc='") << encode(desc) << _T("' >");

		oss << std::endl;
		if(params.size()>0)
		for ( std::list<MetaParam>::iterator it = params.begin(); it != params.end(); it )
		{
			if ( !(*it).isRetVal )
				oss << (*it).out();
			it++;
		}

		oss << _T(" </method>") << std::endl;
	}

	return oss.str();
}


//////////////////////////////////////////////////////////////////////////////////////////

MetaClass::MetaClass()
{}

MetaClass::MetaClass( const std::wstring& t,  GUID& g )
	: type (t), guid(g),isDual(false),isSource(false),isDefault(false)
{

}

MetaClass::MetaClass( const std::wstring& t, const std::wstring& b, GUID& g )
	: type(t), base(b), guid(g),isDual(false)
{

}

std::wstring MetaClass::out()
{
	std::wostringstream oss;

	oss << _T("<interface name='") << type << _T("' ");

	if ( isDual )
		oss << _T("type='Dual' ");

	oss << _T("iid='") << mol::stringFromCLSID(guid) << _T("' ");
	oss << _T("base='") << base << _T("' ");
	oss << _T("members='") << functions.size() << _T("' ");
	oss << _T("desc='") << encode(desc) << _T("' >");
	oss << std::endl;

	for ( std::list<MetaFunc>::iterator it = functions.begin(); it != functions.end(); it++ )
	{
		oss << (*it).out();
	}

	oss << _T("</interface>") << std::endl << std::endl;
	return oss.str();
}

std::wstring MetaClass::out_obj()
{
	std::wostringstream oss;

	oss << _T("<object name='") << type << _T("' ");
	oss << _T("guid='" ) << mol::stringFromCLSID(guid) << _T("' ");
	oss << _T("major='") << major << _T("' ");
	oss << _T("minor='") << minor << _T("' ");
	oss << _T("progId='") << progId << _T("' ");
	oss << _T("desc='") << encode(desc) << _T("' ");
	oss << _T(">") << std::endl;

	for ( std::list<MetaClass>::iterator it = interfaces.begin(); it != interfaces.end(); it++ )
	{
		oss << _T("<implements type='") << (*it).type << _T("' ");
		oss << _T("guid='") << mol::stringFromCLSID((*it).guid) << _T("' ");

		if ( (*it).isDefault )
			oss << _T("default='true' ");
		if ( (*it).isSource )
			oss << _T("source='true' ");

		oss << _T(" />") << std::endl;
	}

	oss << _T("</object>") << std::endl;
	return oss.str();
}

std::wstring MetaClass::iid_def()
{
	std::wostringstream oss;
	oss << type << _T(";") << std::endl;
	return oss.str();
}

std::wstring MetaClass::iid_impls()
{
	std::wostringstream oss;
	oss << type << _T(" = { 0x") << std::endl;

	oss << std::hex << (int)guid.Data1 << _T(", 0x") ;
	oss << (int)guid.Data2 << _T(", 0x") ;
	oss << (int)guid.Data3 << _T(", { 0x") ;
	oss << (int)guid.Data4[0] << _T(", 0x") ;
	oss << (int)guid.Data4[1] << _T(", 0x") ;
	oss << (int)guid.Data4[2] << _T(", 0x") ;
	oss << (int)guid.Data4[3] << _T(", 0x") ;
	oss << (int)guid.Data4[4] << _T(", 0x") ;
	oss << (int)guid.Data4[5] << _T(", 0x") ;
	oss << (int)guid.Data4[6] << _T(", 0x") ;
	oss << (int)guid.Data4[7] << _T(" } }; ") ;

	return oss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////

MetaEnum::MetaEnum()
{}

MetaEnum::MetaEnum( const std::wstring& t )
	: type (t)
{

}

std::wstring MetaEnum::out()
{
	std::wostringstream oss;

	oss << _T("<enum type='") << type 
		<< _T("' desc='") << encode(desc) 
		<< _T("' >") << std::endl;

	for ( std::list<MetaParam>::iterator it = enums.begin(); it != enums.end(); it )
	{
		oss << _T("<element name='") << (*it).type 
			<< _T("' value='") << (*it).name 
			<< _T("' />") << std::endl;
		it++;
	}
	oss << _T("</enum>") << std::endl;
	return oss.str();
}


//////////////////////////////////////////////////////////////////////////////////////////


MetaRecord::MetaRecord()
{}

MetaRecord::MetaRecord( const std::wstring& t )
	: type (t)
{

}

std::wstring MetaRecord::out()
{
	std::wostringstream oss;

	oss << _T("<struct type='") << type << _T("' >") << std::endl;
	for ( std::list<MetaParam>::iterator it = members.begin(); it != members.end(); it++ )
	{
		oss << _T("<member type='") << (*it).type << _T("' name='") << (*it).name << _T("' />") << std::endl;
	}
	oss << _T("</struct>") << std::endl;
	return oss.str();
}

