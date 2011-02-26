package org.oha7.dispdriver.interfaces;

import org.oha7.dispdriver.impl.RawComPtr;

/**
 * interface implemented by ComProxies in addition to the java version of the COm interface
 * the ComProxy invocation handler castes the target obj to this interface and so extracts
 * the raw interface ptr
 * @author mike
 *
 */
public interface RawPtr {

	RawComPtr value();
}
