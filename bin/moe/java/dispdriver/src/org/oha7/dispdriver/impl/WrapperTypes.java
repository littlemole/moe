package org.oha7.dispdriver.impl;

import java.util.HashMap;

/**
 * map primitive types to their wrappers
 * @author mike
 *
 */
class WrapperTypes {

    private static final HashMap<Class<?>,Class<?>> WRAPPER_TYPES = getWrapperTypes();

    /**
     * determine whether Class is a
     * @param clazz
     * @return
     */
    public static boolean isPrimitiveType(Class<?> clazz)
    {
        return WRAPPER_TYPES.containsKey(clazz);
    }
    
    /**
     * convert primitive class to wrapper class
     * @param clazz
     * @return
     */
    public static Class<?> wrapperType(Class<?> clazz)
    {
    	if ( WRAPPER_TYPES.containsKey(clazz) ) {
    		return WRAPPER_TYPES.get(clazz);
    	}
        return clazz;
    }    

    private static HashMap<Class<?>,Class<?>> getWrapperTypes()
    {
    	HashMap<Class<?>,Class<?>> ret = new HashMap<Class<?>,Class<?>>();
        ret.put(boolean.class,Boolean.class);
        ret.put(char.class,Character.class);
        ret.put(byte.class,Byte.class);
        ret.put(short.class,Short.class);
        ret.put(int.class,Integer.class);
        ret.put(long.class,Long.class);
        ret.put(float.class,Float.class);
        ret.put(double.class,Double.class);
        ret.put(void.class,Void.class);
        return ret;
    }
}
