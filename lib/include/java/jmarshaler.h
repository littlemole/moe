#ifndef MOL_JGLUE_JMARSHALER_DEF_GUARD_DEFINE_
#define MOL_JGLUE_JMARSHALER_DEF_GUARD_DEFINE_

#include "win/regkey.h"

#include <iostream>
#include <string>
#include <jni.h>
#include "ole/variant.h"
#include "java/jglue.h"


class JavaMarshaller
{
public:

	static jobject variant2JavaObject(JavaClassStore& classes, VARIANT& var );
	static mol::variant javaObject2Variant(  JavaClassStore& classes, jobject obj );
	static mol::variant javaClass2Variant( jclass clazz );

	static jobjectArray dispArgs2JavaArray(JavaClassStore& classes, DISPPARAMS *pDisp, UINT dec = 0 );
	static DISPPARAMS* javaArray2DispArgs(JavaClassStore& classes, jobjectArray jar, jint flags, UINT dec = 0 );

private:
	static mol::variant javaArray2Variant( JavaClassStore& classes, jobject obj );
	static VARTYPE JavaMarshaller::getVarType(  JavaClassStore& classes, jobject clazz );

};

#endif


