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
	MetaParam( const mol::string& t, const mol::string& n  );

	mol::string name;
	mol::string type;
	bool isPointer;
	bool isPointerPointer;
	bool isRetVal;
	bool isIn;
	bool isOut;

	mol::string out();
	mol::string out_alias();
};

//////////////////////////////////////////////////////////////////////////////////////////

class MetaFunc 
{
public:

	MetaFunc();
	MetaFunc( const mol::string& n, const mol::string& t  );

	mol::string name;
	mol::string type;
	mol::string funkind;
	mol::string desc;

	bool isPointer;
	bool isRetPointer;
	bool isDisp;
	bool isStdCall;
	bool isPropPut;
	bool isPropPutRef;
	bool isPropGet;

	long dispid;

	std::list<MetaParam> params;

	mol::string out();
};

//////////////////////////////////////////////////////////////////////////////////////////

class MetaClass
{
public:

	MetaClass();
	MetaClass( const mol::string& t,  GUID& g );
	MetaClass( const mol::string& t, const mol::string& b, GUID& g );

	mol::string type;
	mol::string base;
	mol::string desc;
	bool isDisp;
	bool isDual;
	bool isSource;
    bool isDefault;

	GUID guid;
	long major;
	long minor;
	mol::string progId;

	std::list<MetaFunc> functions;
	std::list<MetaClass> interfaces;

	mol::string out();
	mol::string out_obj();
	mol::string iid_def();
	mol::string iid_impls();

};

//////////////////////////////////////////////////////////////////////////////////////////

class MetaEnum
{
public:

	MetaEnum();
	MetaEnum( const mol::string& t );

	mol::string type;
	mol::string desc;

	std::list<MetaParam> enums;

	mol::string out();
};


//////////////////////////////////////////////////////////////////////////////////////////

class MetaRecord
{
public:

	MetaRecord();
	MetaRecord( const mol::string& t );

	mol::string type;
	mol::string desc;

	std::list<MetaParam> members;

	mol::string out();
};

#endif

