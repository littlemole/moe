package com4j;

@IID("{00020420-0000-0000-C000-000000000046}")
public interface IDispatch  {

	int getPtr();
	com4j.Variant variant();
	com4j.Com4jObject wrapper();
}
