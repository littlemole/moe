package org.oha7.dispdriver.impl;

/**
 * call native COM code from Java
 * @author mike
 * 
 * - native stubs -
 *
 */
public class Native {
	
	static final int DISPATCH_METHOD = 1;
	static final int DISPATCH_PROPERTYGET = 2;
	static final int DISPATCH_PROPERTYPUT = 4;
	static final int DISPATCH_PROPERTYPUTREF = 8;
	
	static native long QueryInterface(long ptr, String iid);
	
	
	static native void Addref(long ptr);
	static native void Release(long ptr);	
	
	static native void CoIninitalize();
	static native void CoUnIninitalize();
	
	static native long CreateObject( String progId );
	static native String RetrieveBstr( long ptr );
	
    static native Object Invoke( long ptr, int dispid, @SuppressWarnings("rawtypes") Class[] argTypes, Object[] args, int flags );
	static native long GetObject(String progId);
	
	
	/**
	 * load the native implementation
	 */
    static {
    	try {
        	System.loadLibrary("dispdriver");
//    		System.load("E:\\molib\\ax\\jre\\dispdriver\\x64\\uni_debug\\dispdriver.dll");
    	}
    	catch(Exception e) {
    		e.printStackTrace();    		
    	}
    	
    	Native.CoIninitalize();
    }


}
