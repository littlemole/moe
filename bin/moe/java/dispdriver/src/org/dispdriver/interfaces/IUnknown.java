package org.oha7.dispdriver.interfaces;

public interface IUnknown {

	void AddRef();
	void Release();

	<T> T QueryInterface( Class<T> clazz );
}
