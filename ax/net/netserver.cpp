// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netserver.h"
#include "netType.h"
#include "netEvent.h"
#include "netThat.h"
#include "netNamespace.h"
#include "dot.h"
#include "util.h"

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////



NetServer::NetServer()
{
	HRESULT hr = clr_.createObject(CLSID_Net);
}

void NetServer::dispose()
{
	clr_.release();
//	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0); // not a good idea :-(
}


HRESULT __stdcall NetServer::Exit()
{
	clr_.release();
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
	return S_OK;
}

HRESULT __stdcall  NetServer::Import(BSTR typeName, IDispatch** a)
{	
	HRESULT hr = S_OK;

	mol::variant v;
	hr = clr_->LoadAssembly(typeName,&v);

	if (a)
	{
		*a=0;
	}

	if ( (hr != S_OK) || (!a) )
	{
		return hr;
	}

	return Namespace::CreateInstance(mol::tostring(typeName),this,a);
}

HRESULT __stdcall NetServer::get_Runtime(IDispatch** result)
{
	return Namespace::CreateInstance("",this,result);
}

HRESULT __stdcall NetServer::Prototype( BSTR name, VARIANT obj, IDispatch** s)
{
	if(!name)
		return E_INVALIDARG;

	if(!s)
		return E_INVALIDARG;

	mol::punk<IDispatch> disp;

	if(obj.vt == VT_DISPATCH)
	{
		disp = obj.pdispVal;
		if(!disp)
			return E_FAIL;
	}
	else 
	{
		if ( obj.vt & VT_BYREF )
		{
			if ( obj.vt == ( VT_DISPATCH|VT_BYREF) ) 
			{
				disp = *obj.ppdispVal;
			}
			else if ( obj.vt == (VT_VARIANT|VT_BYREF) ) 
			{
				if ( obj.pvarVal->vt == VT_DISPATCH )
				{
					disp = obj.pvarVal->pdispVal;
				}
				else 
				{
					return E_FAIL;
				}
			}
			else 
			{
				return E_FAIL;
			}
		}
		else 
		{
			return E_FAIL;
		}
	}

	mol::punk<IDispatchEx> dispEx(disp);
	if(!dispEx)
		return E_FAIL;

	DISPID dispid = 0;
	std::vector<BSTR> names;
	std::vector<VARIANT> values;

	HRESULT hr = dispEx->GetNextDispID(fdexEnumAll, DISPID_STARTENUM, &dispid);
	while (hr == NOERROR)
	{
		BSTR bstrName;
		hr = dispEx->GetMemberName(dispid, &bstrName);
		names.push_back(bstrName);

		DISPPARAMS params = {0};
		EXCEPINFO ex;
		::ZeroMemory(&ex,sizeof(EXCEPINFO));

		mol::variant result;
		hr = dispEx->InvokeEx(dispid,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&params,&result,&ex,NULL);
		if(hr != S_OK )
			return hr;

		VARIANT v;
		::VariantInit(&v);
		unwrapNETObject(result,&v);
		values.push_back(v);

		hr = dispEx->GetNextDispID(fdexEnumAll, dispid, &dispid);
	}

	if ( names.size() != values.size() )
	{
		return E_INVALIDARG;
	}


	mol::SafeArray<VT_VARIANT> saNames(mol::ArrayBound((long)names.size()));

	mol::SFAccess<VARIANT> sfbNames(saNames);
	for ( long i = 0; i < sfbNames.size(); i++)
	{
		sfbNames[i].vt = VT_BSTR;
		sfbNames[i].bstrVal = names[i];
	}

	mol::SafeArray<VT_VARIANT> saValues(mol::ArrayBound((long)values.size()));

	mol::SFAccess<VARIANT> sfbValues(saValues);
	for ( long i = 0; i < sfbValues.size(); i++)
	{
		if ( values[i].vt == VT_DISPATCH )
		{
			mol::punk<IDispatchEx> dispEx(values[i].pdispVal);
			if( dispEx)
			{
				mol::punk<INetType> nt(dispEx);
				if(!nt)
				{
					mol::punk<IDispatch> ret;
					std::wostringstream woss;
					woss << name << "$" << names[i];
					hr = Prototype(mol::bstr(woss.str()),values[i],&ret);
					if ( hr == S_OK && ret )
					{
						::VariantClear(&values[i]);
						mol::variant v(ret);
						hr = unwrapNETObject(v,&values[i]);
					}
				}
			}
		}

		sfbValues[i] = values[i];
	}

	mol::variant r;
	hr = clr_->Prototype(name, saNames, saValues, &r);
	if(hr != S_OK )
		return hr;

	if ( (r.vt == VT_DISPATCH || r.vt == VT_UNKNOWN) && r.punkVal )
	{
		mol::punk<INetType> type;
		wrapNETType(clr_,r,&type);
		return type.queryInterface(s);
	}
	return S_OK;
}

HRESULT __stdcall NetServer::copyTo( IDispatch* src, IDispatch* dest)
{
	mol::punk<INetType> type;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.Net"),&type);
	if(hr!=S_OK)
		return hr;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	DispParamsBuf params(2);
	params.set(0,dest);
	params.set(1,src);

	OLECHAR* name = (OLECHAR*)L"copyTo";
	DISPID dispid;
	hr = type->GetIDsOfNames(IID_NULL,&name,1,LOCALE_SYSTEM_DEFAULT,&dispid);
	if ( hr != S_OK)
		return hr;

	mol::variant result;
	hr = type->Invoke(dispid,IID_NULL,LOCALE_SYSTEM_DEFAULT,0,&params,&result,&ex,&e);
	return hr;

}

HRESULT __stdcall NetServer::get_CLR( IUnknown** unk)
{
	if(!unk)
		return E_INVALIDARG;

	return clr_.queryInterface(unk);
}

typedef std::vector<VARIANT> jsArray;


jsArray enumJSArray(IDispatch* disp)
{
	jsArray resultArray;

	mol::punk<IDispatchEx> dispEx(disp);
	if(!dispEx)
		return resultArray;


	DISPPARAMS empty;
	::ZeroMemory(&empty,sizeof(DISPPARAMS));

	mol::variant result;
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	DISPID dispid = 0;

	LPOLESTR str = (LPOLESTR) L"length";
	HRESULT hr = dispEx->GetIDsOfNames(IID_NULL,&str,1,LOCALE_SYSTEM_DEFAULT,&dispid);
	if (hr != S_OK )
		return resultArray;

	hr = dispEx->Invoke( dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET,&empty,&result,&ex,&e);
	if (hr != S_OK )
		return resultArray;

	result.changeType(VT_I4);
	for ( LONG i = 0; i < result.lVal; i++ )
	{
		std::wostringstream woss;
		woss << i;
		std::wstring w(woss.str());
		LPOLESTR ole = (wchar_t*) w.c_str();

		HRESULT hr = dispEx->GetIDsOfNames(IID_NULL,&ole,1,LOCALE_SYSTEM_DEFAULT,&dispid);
		if (hr != S_OK )
			continue;

		mol::variant r;
		::VariantInit(&r);
		hr = dispEx->Invoke( dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET,&empty,&r,&ex,&e);
		if (hr != S_OK )
			continue;

		VARIANT tmp;
		::VariantInit(&tmp);
		unwrapNETObject(r,&tmp);
		resultArray.push_back(tmp);
	}

	return resultArray;
}

HRESULT getMemberAsVariant( LPOLESTR name, IDispatch* def, VARIANT* result)
{
	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	if(!def)
		return E_INVALIDARG;

	DISPID dispid = 0;
	HRESULT hr = def->GetIDsOfNames(IID_NULL,&name,1,LOCALE_SYSTEM_DEFAULT,&dispid);
	if ( hr == S_OK )
	{
		mol::variant v;
		hr = def->Invoke(dispid,IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&emptyParams,&v,&ex,&e);
		if ( hr == S_OK )
		{
			unwrapNETObject(v,result);
		}
	}

	return S_OK;
}


HRESULT NetServer::getAttributes(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> attrDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.AttributeDef"), &attrDefType);
	if(hr != S_OK)
		return hr;

	mol::variant vattrDefType;
	hr = attrDefType->UnWrap(&vattrDefType);
	if(hr != S_OK)
		return hr;


	jsArray jsa = enumJSArray(def);
	if(jsa.size()==0)
		return S_OK;

	mol::ArrayBound abResult((long)jsa.size());
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);
		for ( long i = 0; i < jsa.size(); i++)
		{
			sfaResult[i].vt = VT_EMPTY;

			jsArray jsAttribute = enumJSArray(jsa[i].pdispVal);
			if ( jsAttribute.size() == 0 )
				continue;

			VARIANT t = jsAttribute[0];
			long nArgs = (long)jsAttribute.size()-1;

			mol::ArrayBound abAttrDefArgs(nArgs);
			mol::SafeArray<VT_VARIANT> sfAttrDefArgs(abAttrDefArgs);
			{
				mol::SFAccess<VARIANT> sfaAttrDefArgs(sfAttrDefArgs);
				for ( long j = 0; j < nArgs; j++)
				{
					sfaAttrDefArgs[j] = jsAttribute[j+1];
				}
			}

			mol::ArrayBound abParamsDefArgs(2);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0] = t;
				sfaParams[1].vt = VT_ARRAY|VT_VARIANT;
				::SafeArrayCopy( sfAttrDefArgs, &(sfaParams[1].parray) );
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vattrDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}

std::vector<DISPID> enumJsDispids( IDispatch* obj )
{
	std::vector<DISPID> result;
	if(!obj)
		return result;

	mol::punk<IDispatchEx> dispEx(obj);
	if(!dispEx)
		return result;

	DISPID dispid = 0;

	HRESULT hr = dispEx->GetNextDispID(fdexEnumAll, DISPID_STARTENUM, &dispid);
	while (hr == NOERROR)
	{
		result.push_back(dispid);
		hr = dispEx->GetNextDispID(fdexEnumAll, dispid, &dispid);
	}
	return result;
}

HRESULT NetServer::getProperties(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> propDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.PropertyDef"), &propDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant vpropDefType;
	hr = propDefType->UnWrap(&vpropDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant properties;
	hr = getMemberAsVariant( (LPOLESTR) L"properties", def, &properties);
	if(hr!=S_OK || properties.vt == VT_EMPTY)
		return hr;

	mol::punk<IDispatchEx> dispEx(properties.pdispVal);

	std::vector<DISPID> dispids = enumJsDispids(properties.pdispVal);

	if ( dispids.empty() )
		return S_OK;

	mol::ArrayBound abResult((long)dispids.size());
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);

		for( int i = 0; i < (int)dispids.size(); i++)
		{
			sfaResult[i].vt = VT_EMPTY;

			BSTR name;
			hr = dispEx->GetMemberName(dispids[i],&name);

			mol::variant prop;
			hr = dispEx->Invoke(dispids[i],IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&emptyParams,&prop,&ex,&e);

			jsArray jsa = enumJSArray(prop.pdispVal);
			if(jsa.size() == 0 )
				continue;
			
			VARIANT t = jsa[0];

			mol::SafeArray<VT_VARIANT> sfAttrDef;
			if(jsa.size() > 1 )
			{
				mol::variant attributes;
				hr = getAttributes( jsa[1].pdispVal, sfAttrDef);
			}

			mol::ArrayBound abParamsDefArgs(3);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0].vt = VT_BSTR;
				sfaParams[0].bstrVal = name;
				sfaParams[1] = t;
				if ( (SAFEARRAY*)sfAttrDef == 0 )
				{
					sfaParams[2].vt = VT_EMPTY;
				}
				else
				{
					sfaParams[2].vt = VT_ARRAY|VT_VARIANT;
					::SafeArrayCopy( sfAttrDef, &(sfaParams[2].parray) );
				}
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vpropDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}

HRESULT NetServer::getMethods(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> methodDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.MethodHandle"), &methodDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant vmethodDefType;
	hr = methodDefType->UnWrap(&vmethodDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant methods;
	hr = getMemberAsVariant( (LPOLESTR) L"methods", def, &methods);
	if(hr!=S_OK || methods.vt == VT_EMPTY)
		return hr;

	mol::punk<IDispatchEx> dispEx(methods.pdispVal);

	std::vector<DISPID> dispids = enumJsDispids(methods.pdispVal);

	if ( dispids.empty() )
		return S_OK;

	mol::ArrayBound abResult((long)dispids.size());
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);

		for( int i = 0; i < (int)dispids.size(); i++)
		{
			sfaResult[i].vt = VT_EMPTY;

			BSTR name;
			hr = dispEx->GetMemberName(dispids[i],&name);

			mol::variant method;
			hr = dispEx->Invoke(dispids[i],IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&emptyParams,&method,&ex,&e);

			jsArray jsa = enumJSArray(method.pdispVal);
			VARIANT t;
			t.vt = VT_EMPTY;

			mol::SafeArray<VT_VARIANT> sfArgs;
			if(jsa.size() > 0 )
			{			
				t = jsa[0];

				if(jsa.size() > 1 )
				{
					jsArray jsArgs = enumJSArray(jsa[1].pdispVal);

					if ( jsArgs.size() > 0 )
					{
						mol::ArrayBound ab((long)jsArgs.size());
						sfArgs.Create(ab);
						mol::SFAccess<VARIANT> sfaArgs(sfArgs);
						for ( long j = 0; j < jsArgs.size(); j++ )
						{
							sfaArgs[j] = jsArgs[j];
						}
					}
				}
			}

			mol::ArrayBound abParamsDefArgs(3);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0].vt = VT_BSTR;
				sfaParams[0].bstrVal = name;
				sfaParams[1] = t;
				if ( (SAFEARRAY*)sfArgs == 0 )
				{
					sfaParams[2].vt = VT_EMPTY;
				}
				else
				{
					sfaParams[2].vt = VT_ARRAY|VT_VARIANT;
					::SafeArrayCopy( sfArgs, &(sfaParams[2].parray) );
				}
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vmethodDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}

HRESULT NetServer::getConstructors(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> ctorDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.ConstructorDef"), &ctorDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant vmethodDefType;
	hr = ctorDefType->UnWrap(&vmethodDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant ctors;
	hr = getMemberAsVariant( (LPOLESTR) L"constructors", def, &ctors);
	if(hr!=S_OK || ctors.vt == VT_EMPTY)
		return hr;

	mol::punk<IDispatchEx> dispEx(ctors.pdispVal);

	std::vector<DISPID> dispids = enumJsDispids(ctors.pdispVal);

	if ( dispids.empty() )
		return S_OK;

	mol::ArrayBound abResult((long)dispids.size());
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);

		for( int i = 0; i < (int)dispids.size(); i++)
		{
			sfaResult[i].vt = VT_EMPTY;

			BSTR name;
			hr = dispEx->GetMemberName(dispids[i],&name);

			mol::variant ctor;
			hr = dispEx->Invoke(dispids[i],IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&emptyParams,&ctor,&ex,&e);

			jsArray jsa = enumJSArray(ctor.pdispVal);
			VARIANT t;
			t.vt = VT_EMPTY;

			mol::SafeArray<VT_VARIANT> sfArgs;
			if(jsa.size() > 0 )
			{			
				mol::ArrayBound ab((long)jsa.size());
				sfArgs.Create(ab);
				mol::SFAccess<VARIANT> sfaArgs(sfArgs);
				for ( long j = 0; j < jsa.size(); j++ )
				{
					sfaArgs[j] = jsa[j];
				}
			}

			mol::ArrayBound abParamsDefArgs(3);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0].vt = VT_BSTR;
				sfaParams[0].bstrVal = name;
				sfaParams[1] = t;
				if ( (SAFEARRAY*)sfArgs == 0 )
				{
					sfaParams[2].vt = VT_EMPTY;
				}
				else
				{
					sfaParams[2].vt = VT_ARRAY|VT_VARIANT;
					::SafeArrayCopy( sfArgs, &(sfaParams[2].parray) );
				}
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vmethodDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}

HRESULT NetServer::getInterfaces(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	mol::variant interfaces;
	HRESULT hr = getMemberAsVariant( (LPOLESTR) L"implements", def, &interfaces);
	if(hr!=S_OK || interfaces.vt == VT_EMPTY)
		return hr;

	jsArray arrayInterfaces = enumJSArray(interfaces.pdispVal);

	if(arrayInterfaces.size()==0)
		return S_OK;

	mol::ArrayBound abInterfaces((long)arrayInterfaces.size());
	result.Create(abInterfaces);
	{
		mol::SFAccess<VARIANT> sfa(result);
		for ( long i = 0; i < arrayInterfaces.size(); i++)
		{
			sfa[i] = arrayInterfaces[i];
		}
	}
	return S_OK;
}

HRESULT __stdcall NetServer::Declare( BSTR name, IDispatch* def, IDispatch* handler, IDispatch** unk)
{
	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::variant baseType;
	HRESULT hr = getMemberAsVariant( (LPOLESTR) L"inherits", def, &baseType);
	if ( hr != S_OK || baseType.vt == VT_EMPTY)
	{
		mol::punk<INetType> t;
		hr = Type( mol::bstr("System.Object"), &t);
		if ( hr == S_OK && t )
		{
			hr = t->UnWrap(&baseType);
		}
	}
	

	mol::SafeArray<VT_VARIANT> sfInterfaces;
	hr = getInterfaces( def, sfInterfaces );

	mol::variant attributes;
	hr = getMemberAsVariant( (LPOLESTR) L"attributes", def, &attributes);
	mol::SafeArray<VT_VARIANT> sfAttrDef;

	if ( hr == S_OK && attributes.vt != VT_EMPTY )
		hr = getAttributes( attributes.pdispVal,  sfAttrDef);

	mol::SafeArray<VT_VARIANT> sfCtorDef;
	hr = getConstructors( def, sfCtorDef );

	mol::SafeArray<VT_VARIANT> sfPropsDef;
	hr = getProperties( def, sfPropsDef );

	mol::SafeArray<VT_VARIANT> sfMethodDef;
	hr = getMethods( def, sfMethodDef );

	mol::variant result;
	hr = clr_->DefineClass( name, baseType,sfInterfaces,sfAttrDef,sfCtorDef,sfPropsDef,sfMethodDef,&result);
	if ( hr != S_OK )
		return hr;

	if ( (result.vt == VT_DISPATCH || result.vt == VT_UNKNOWN) && result.punkVal )
	{
		mol::variant vempty;
		mol::variant tmp;
		mol::ArrayBound ab(1);
		mol::SafeArray<VT_VARIANT> args(ab);
		{
			mol::SFAccess<VARIANT> sfa(args);
			sfa[0].vt = VT_DISPATCH;

			mol::punk<IDispatch> thatCall;
			hr = ThatCall::CreateInstance(clr_,handler,&thatCall);
			hr = thatCall->QueryInterface(IID_IDispatch, (void**) &sfa[0].pdispVal );
		}

		hr = clr_->InvokeMethod( result, baseType, mol::bstr("ScriptHandler"),args,DISPATCH_PROPERTYPUT,&tmp);

		mol::punk<INetType> type;
		wrapNETType(clr_,result,&type);
		return type.queryInterface(unk);
	}
	return E_INVALIDARG;
}

HRESULT __stdcall NetServer::Array( IDispatch* arraytype, IDispatch* values, IDispatch** s)
{
	if(!arraytype || !values || !s )
		return E_INVALIDARG;

	mol::punk<INetType> type;
	HRESULT hr = Type( mol::bstr("System.Array"),&type);
	if(hr!=S_OK)
		return hr;

	mol::variant vtype;
	hr = type->UnWrap(&vtype);

	mol::variant tmp(arraytype);
	VARIANT vat;
	hr = unwrapNETObject(tmp,&vat);
	if ( hr != S_OK )
		return hr;

	jsArray jsa = enumJSArray(values);

	mol::ArrayBound ab(2);
	mol::SafeArray<VT_VARIANT> sf(ab);
	{
		mol::SFAccess<VARIANT> sfa(sf);
		sfa[0] = vat;
		sfa[1] = mol::variant((long)jsa.size());
	}

	mol::vEmpty vempty;
	mol::variant v;
	hr = clr_->InvokeMethod(vtype,vempty,mol::bstr("CreateInstance"),sf,DISPATCH_METHOD,&v);

	for ( long i = 0; i < (long)jsa.size(); i++)
	{
		mol::SafeArray<VT_VARIANT> args(ab);
		{
			mol::SFAccess<VARIANT> sfa(args);
			sfa[0] = jsa[i];
			sfa[1] = mol::variant(i);

			mol::variant r;
			hr = clr_->InvokeMethod(vempty,v,mol::bstr("SetValue"),args,DISPATCH_METHOD,&r);
		}
	}
	mol::variant r;
	hr = wrapNETObject(clr_,v,&r);
	return r.pdispVal->QueryInterface( IID_IDispatch, (void**)s );
}


HRESULT __stdcall NetServer::String( BSTR txt, IDispatch** s)
{
	mol::punk<INetType> type;
	HRESULT hr = Type( mol::bstr("System.String"),&type);
	if(hr!=S_OK)
		return hr;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	VARIANTARG varg;
	varg.vt = VT_BSTR;
	varg.bstrVal = txt;

	DISPPARAMS params;
	::ZeroMemory(&params,sizeof(DISPPARAMS));
	params.cArgs = 1;
	params.rgvarg = &varg;

	mol::variant result;
	hr = type->Invoke(0,IID_NULL,LOCALE_SYSTEM_DEFAULT,0,&params,&result,&ex,&e);
	if ( hr == S_OK && s && (result.vt == VT_DISPATCH || result.vt == VT_UNKNOWN) && result.punkVal )
	{
		hr = result.punkVal->QueryInterface(IID_IDispatch,(void**)s);
		return hr;
	}
	return E_FAIL;
}


HRESULT __stdcall NetServer::Type( BSTR typeName, INetType** clazz)
{
	if ( !typeName )
	{
		mol::com_throw("invalid typeName",CLSID_DotNet,".NET error");
		return E_INVALIDARG;
	}

	if ( !clazz )
	{
		return E_INVALIDARG;
	}

	*clazz = 0;

	mol::variant empty;
	mol::variant v;
	HRESULT hr = clr_->LoadClass( empty, typeName, &v );
	if ( hr != S_OK )
		return hr;

	return wrapNETType(clr_,v,clazz);
}

HRESULT __stdcall NetServer::Connect(IDispatch* ptr, BSTR eventName, VARIANT target)
{
	mol::variant v;
	HRESULT hr = unwrapNETObject(target,&v);
	if ( hr != S_OK )
		return hr;

	mol::punk<IDispatch> disp;
	EventHandler::CreateInstance(clr_,ptr,&disp);

	mol::variant vptr(disp);	
	hr = clr_->Event( v,  eventName, vptr);
	return hr;

}

///////////////////////////////////////////////////////////


HRESULT __stdcall NetServer::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	return mol::Dispatch<INet>::GetIDsOfNames( riid, rgszNames, cNames, lcid, rgDispId );
}

HRESULT  __stdcall NetServer::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 

	return mol::Dispatch<INet>::Invoke(dispIdMember, riid, lcid, w, pDisp, pReturn, ex, i );
}

	
HRESULT __stdcall NetServer::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall NetServer::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

