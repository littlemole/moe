#pragma once
#include "cleanup.h"
#include "java_id.h"

const int BYREF = 0x8000;

// see com4j.NativeType
enum Conv {
	cvBSTR = 1,
	cvBSTR_byRef = 1|BYREF,
	cvLPCWSTR = 2,
	cvLPCSTR = 3,


	cvINT8 = 100,
	cvINT8_byRef = 100|BYREF,
	cvINT16 = 101,
	cvINT16_byRef = 101|BYREF,
	cvINT32 = 102,
	cvINT32_byRef = 102|BYREF,
	cvBool = 103,
	cvVariantBool = 104,
	cvVariantBool_byRef = 104|BYREF,
	cvFloat = 120,
	cvFloat_byRef = 120|BYREF,
	cvDouble = 121,
	cvDouble_byRef = 121|BYREF,

	cvHRESULT = 200,

	cvComObject = 300,
	cvComObject_byRef = 300|BYREF,
	cvGUID = 301,
	cvVARIANT = 302,
	cvVARIANT_byRef = 302|BYREF,
	cvDISPATCH = 303,
	cvPVOID = 304,
	cvPVOID_byRef = 304|BYREF,

	cvDATE = 400,
	cvCURRENCY = 401,
	cvCURRENCY_byRef = 401|BYREF,

	cvSAFEARRAY = 500,
};


typedef void (*ComMethod)();
typedef ComMethod* VTable;



class Environment {
	// JNI environment
	JNIEnv* const		env;
	// post actions
	PostAction* postActions;
public:
	Environment( JNIEnv* _env ) : env(_env) {
		postActions = NULL;
	}
	~Environment();

	// invoke a method
	jobject invoke(
		void* pComObject,		// pointer to the the COM object
		ComMethod		method,	// pointer to the method to invoke
		jobjectArray	args,	// arguments
		jint*			convs,	// conversions
		int				retIndex,
		bool			retIsInOut,
		jint			retConv
	);

	// adds a new post action
	void add( PostAction* cu );

	// get the char array from jstring and schedule a clean up
	const jchar* toChars( jstring s );

	// get the \0-terminated wide string
	const wchar_t* toLPCWSTR( jstring s );

	// get the \0-terminated string
	LPCSTR toLPCSTR( jstring s );

	BSTR toBSTR( jstring s );
};


// convert a java object to a VARIANT based on the actual type of the Java object.
// the caller should call VariantClear to clean up the data, then delete it.
//
// return NULL if fails to convert
VARIANT* convertToVariant( JNIEnv* env, jobject o );


extern JavaVM* jvm;


struct MyGUID {
	INT64 l1;
	INT64 l2;
public:
	MyGUID( INT64 v1, INT64 v2 ) {
		l1=v1; l2=v2;
	}

	operator const GUID&() const { return *reinterpret_cast<const GUID*>(this); }
};


// throw a Java ComException
void error( JNIEnv* env, const char* fileName, int line, const char* msg ... );
void error( JNIEnv* env, const char* fileName, int line, HRESULT hr, const char* msg ... );


