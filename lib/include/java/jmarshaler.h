#ifndef MOL_JGLUE_JMARSHALER_DEF_GUARD_DEFINE_
#define MOL_JGLUE_JMARSHALER_DEF_GUARD_DEFINE_

#include "java/jglue.h"
#include "ole/variant.h"

namespace mol {
namespace java {

class JavaMarshaler
{
public:

	static jobject      variant2JavaObject(JavaClassStore& classes, VARIANT& var );
	static mol::variant javaObject2Variant(  JavaClassStore& classes, jobject obj );

	static jobjectArray dispArgs2JavaArray(JavaClassStore& classes, DISPPARAMS *pDisp, UINT dec = 0 );
	static DISPPARAMS*  javaArray2DispArgs(JavaClassStore& classes, jobjectArray jar, jint flags, UINT dec = 0 );

};

} // end namespace java
} // end namespace mol


#endif


