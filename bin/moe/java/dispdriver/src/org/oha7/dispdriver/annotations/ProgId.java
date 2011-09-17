package org.oha7.dispdriver.annotations;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * specify the ProgId for a Object implementing a IDispatch based Interface derived from IUnknown
 * @author mike
 *
 */
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.TYPE)
public @interface ProgId {
	String value();
}