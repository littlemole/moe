#ifndef MOL_DEFINE_META_NAMES_TYPEDEF_DEF_GUARD_
#define MOL_DEFINE_META_NAMES_TYPEDEF_DEF_GUARD_

#include "ole/typeinfo.h"
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////

class MetaParam 
{
public:

	MetaParam();
	MetaParam( const std::wstring& t, const std::wstring& n  );

	std::wstring name;
	std::wstring type;
	bool isPointer;
	bool isPointerPointer;
	bool isRetVal;
	bool isIn;
	bool isOut;

	std::wstring out();
	std::wstring out_alias();
};

//////////////////////////////////////////////////////////////////////////////////////////

class MetaFunc 
{
public:

	MetaFunc();
	MetaFunc( const std::wstring& n, const std::wstring& t  );

	std::wstring name;
	std::wstring type;
	std::wstring funkind;
	std::wstring desc;

	bool isPointer;
	bool isRetPointer;
	bool isDisp;
	bool isStdCall;
	bool isPropPut;
	bool isPropPutRef;
	bool isPropGet;

	long dispid;
	long vtindex;

	std::list<MetaParam> params;

	std::wstring out();
};

//////////////////////////////////////////////////////////////////////////////////////////

class MetaClass
{
public:

	MetaClass();
	MetaClass( const std::wstring& t,  const GUID& g );
	MetaClass( const std::wstring& t, const std::wstring& b, const GUID& g );

	std::wstring type;
	std::wstring base;
	std::wstring desc;
	bool isDisp;
	bool isDual;
	bool isSource;
    bool isDefault;

	GUID guid;
	long major;
	long minor;
	std::wstring progId;

	std::list<MetaFunc> functions;
	std::list<MetaClass> interfaces;

	std::wstring out();
	std::wstring out_obj();
	std::wstring iid_def();
	std::wstring iid_impls();

};

//////////////////////////////////////////////////////////////////////////////////////////

class MetaEnum
{
public:

	MetaEnum();
	MetaEnum( const std::wstring& t );

	std::wstring type;
	std::wstring desc;

	std::list<MetaParam> enums;

	std::wstring out();
};


//////////////////////////////////////////////////////////////////////////////////////////

class MetaRecord
{
public:

	MetaRecord();
	MetaRecord( const std::wstring& t );

	std::wstring type;
	std::wstring desc;

	std::list<MetaParam> members;

	std::wstring out();
};

#endif

