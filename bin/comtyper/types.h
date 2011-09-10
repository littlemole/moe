#ifndef _MOL_COM_DLL_COMTYPES_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_COMTYPES_DEF_DEFINE_GUARD_

#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
#include "thread/thread.h"
#include <msxml2.h>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "Meta.h"

#define BOOST_BIND_ENABLE_STDCALL 
#include "boost/bind.hpp"

using namespace mol;

class TypeLib2XML
{
public:

	bool loadTypeLib(const mol::string path);
	mol::string getXML();

private:

	mol::string filename;
	mol::TypeLib tl;

	std::list<MetaClass> iMap;
	std::list<MetaClass> coMap;
	std::list<MetaEnum> enumMap;
	std::list<MetaParam> aliasMap;
	std::list<MetaRecord> recordMap;

	void tl_funcdesc(mol::TypeInfo& ti, MetaClass& meta, int fi );
	void tl_dispatch(mol::TypeInfo& ti, int index, MetaClass& meta );
	void tl_interface( mol::TypeInfo&  ti, int index, MetaClass& meta );
	void tl_enum( mol::TypeInfo&  ti, int index, MetaClass& meta );
	void tl_typedef( mol::TypeInfo&  ti, int index, MetaClass& meta );
	void tl_record( mol::TypeInfo&  ti, int index, MetaClass& meta );

};

////////////////////////////////////////////////////////////////////////
/*
class Type2XML : 
	public mol::com_registerobj<Type2XML,CLSID_TypeLibToXml>,
	public mol::Dispatch<ITypeLibToXml>,
	public mol::ConnectionPointContainer<Type2XML>,
	public mol::ConnectionPoint<
					Type2XML,
					_IAsyncDocumentationComplete,
					mol::ole::ConnectionPointAdviseMultiThreadPolicy<_IAsyncDocumentationComplete>
				>,
	public mol::interfaces< Type2XML,
			mol::implements<
				ITypeLibToXml,
				IDispatch > >
{
public:

	Type2XML()
		: isErr_(VARIANT_FALSE),
		  cookie_completeEvent_(0),
		  cookie_statusEvent_(0)
	{

	}

	virtual void dispose()
	{
		if ( cookie_completeEvent_ )
		{
			GIT git;
			git.revokeInterface(cookie_completeEvent_);
			cookie_completeEvent_ = 0;
		}	
		if ( cookie_statusEvent_ )
		{
			GIT git;
			git.revokeInterface(cookie_statusEvent_);
			cookie_statusEvent_ = 0;
		}	
	}


	HRESULT virtual __stdcall Load( BSTR filename,  VARIANT_BOOL* vbSuccess )
	{
		isErr_ = VARIANT_TRUE;

		if ( !vbSuccess )
			return E_INVALIDARG;

		xml_ = 0;
		bool b = converter_.loadTypeLib( bstr(filename).toString() );

		*vbSuccess = b ? VARIANT_TRUE : VARIANT_FALSE;
		isErr_ = *vbSuccess;
		return S_OK;
	}

	HRESULT virtual __stdcall get_XML( BSTR* xmlDoc )
	{
		isErr_ = VARIANT_TRUE;

		if ( !xmlDoc )
			return E_INVALIDARG;

		if ( xml_.bstr_ )
		{
			*xmlDoc = ::SysAllocString( xml_ );
			return S_OK;
		}

		isErr_ = VARIANT_FALSE;
		xml_ = converter_.getXML();
		*xmlDoc = ::SysAllocString( xml_ );
		return S_OK;
	}

	HRESULT virtual __stdcall Transform( VARIANT xsltDoc, BSTR* resultDoc)
	{
		isErr_ = VARIANT_TRUE;

		if ( !resultDoc )
			return E_INVALIDARG;

		bstr xml(this->converter_.getXML());
		HRESULT hr = transformer( xml, 0, xsltDoc );
		*resultDoc = ::SysAllocString(resultDoc_.bstr_);

		return hr;
		/*
		isErr_ = VARIANT_TRUE;

		if ( !resultDoc )
			return E_INVALIDARG;

		*resultDoc = 0;
		if ( xsltDoc.vt == VT_EMPTY )
			return S_OK;

		mol::string xslt("");
		if ( xsltDoc.vt == VT_BSTR )
		{
			mol::string val = bstr(xsltDoc.bstrVal).toString();
			if ( mol::Path::exists(val) )
			{
				mol::filestream fs;
				if ( !fs.open(val) )
					return S_OK;
				xslt = fs.readAll();
				fs.close();
			}
			else
			{
				xslt = val;
			}
		}
		if ( xsltDoc.vt == VT_DISPATCH )
		{
			punk<IXMLDOMDocument> doc(xsltDoc.pdispVal);
			if (!doc)
				return S_OK;

			bstr xml;
			if ( S_OK != doc->get_xml(&xml) )
				return S_OK;

			xslt = xml.toString();
		}		

		punk<IXSLTemplate> xslTemplate;
		if (S_OK != xslTemplate.createObject(CLSID_XSLTemplate) )
			return S_OK;

		punk<IXMLDOMDocument2> xsl;
		if (S_OK != xsl.createObject(CLSID_FreeThreadedDOMDocument) )
			return S_OK;

		VARIANT_BOOL vbSuccess = VARIANT_FALSE;
		if ( S_OK != xsl->loadXML( bstr(xslt), &vbSuccess ) )
			return S_OK;

		if ( vbSuccess == VARIANT_FALSE )
			return S_OK;

		if ( S_OK != xsl->put_async(VARIANT_FALSE) )
			return S_OK;

		if ( S_OK != xslTemplate->putref_stylesheet(xsl) )
			return S_OK;

		punk<IXMLDOMDocument2> xml;
		if (S_OK != xml.createObject(CLSID_DOMDocument) )
			return S_OK;

		vbSuccess = VARIANT_FALSE;
		if ( S_OK != xml->loadXML( bstr(this->converter_.getXML()), &vbSuccess ) )
			return S_OK;

		if ( vbSuccess == VARIANT_FALSE )
			return S_OK;

		punk<IXSLProcessor> processor;
		if ( S_OK != xslTemplate->createProcessor(&processor) || !processor )
			return S_OK;

		if ( S_OK != processor->put_input( variant(xml) ) )
			return S_OK;

		vbSuccess = VARIANT_FALSE;
		if ( S_OK != processor->transform( &vbSuccess ) || vbSuccess == VARIANT_FALSE )
			return S_OK;

		variant v;
		if ( S_OK != processor->get_output(&v) )
			return S_OK;

		if ( v.vt == VT_BSTR )
		{
			*resultDoc = ::SysAllocString( v.bstrVal );
			isErr_ = VARIANT_FALSE;
		}
		return S_OK;
		*//*
	}


	HRESULT virtual __stdcall AsyncDocumentation( BSTR filename, BSTR filter, VARIANT xsltDoc )
	{
		isErr_ = VARIANT_TRUE;

		mol::thread( boost::bind( &Type2XML::async_transformer, this, filename, filter, xsltDoc) );

		return S_OK;
	}


	HRESULT virtual __stdcall put_onComplete( IDispatch* onCompleteHandler )
	{
		isErr_ = VARIANT_TRUE;

		GIT git;
		if ( cookie_completeEvent_ )
		{
			git.revokeInterface(cookie_completeEvent_);
		}

		HRESULT hr = git.registerInterface(onCompleteHandler,&cookie_completeEvent_);
		if ( hr == S_OK )
			isErr_ = VARIANT_FALSE;
		return hr;
	}

	HRESULT virtual __stdcall get_onComplete( IDispatch** onCompleteHandler )
	{
		isErr_ = VARIANT_TRUE;

		if ( !onCompleteHandler )
			return E_INVALIDARG;

		punk<IDispatch>  disp;
		GIT git;
		HRESULT hr = git.getInterface(cookie_completeEvent_,onCompleteHandler);

		if ( hr == S_OK )
			isErr_ = VARIANT_FALSE;
		return hr;
	}


	HRESULT virtual __stdcall put_onStatus( IDispatch* onStatusHandler )
	{
		isErr_ = VARIANT_TRUE;

		GIT git;
		if ( cookie_statusEvent_ )
		{
			git.revokeInterface(cookie_statusEvent_);
		}

		HRESULT hr = git.registerInterface(onStatusHandler,&cookie_statusEvent_);
		if ( hr == S_OK )
			isErr_ = VARIANT_FALSE;
		return hr;
	}

	HRESULT virtual __stdcall get_onStatus( IDispatch** onStatusHandler )
	{
		isErr_ = VARIANT_TRUE;

		if ( !onStatusHandler )
			return E_INVALIDARG;

		punk<IDispatch>  disp;
		GIT git;
		HRESULT hr = git.getInterface(cookie_statusEvent_,onStatusHandler);

		if ( hr == S_OK )
			isErr_ = VARIANT_FALSE;
		return hr;
	}


	HRESULT virtual __stdcall get_Error( VARIANT_BOOL* vbIsError )
	{
		if ( !vbIsError )
			return E_INVALIDARG;

		*vbIsError = isErr_;
		return S_OK;
	}

	HRESULT virtual __stdcall get_Result( BSTR* resultDoc )
	{
		isErr_ = VARIANT_TRUE;
		if ( !resultDoc )
			return E_INVALIDARG;

		isErr_ = VARIANT_FALSE;
		*resultDoc = ::SysAllocString(resultDoc_.bstr_);
		return S_OK;
	}

private:

	
	void FireOnDone()
	{
		this->fire(1);
		if ( cookie_completeEvent_ )
		{
			punk<IDispatch>  disp;
			GIT git;
			git.getInterface(cookie_completeEvent_,&disp);
			disp_invoke(disp,DISPID_VALUE);
		}
	}

	void FireOnStatus( BSTR msg )
	{
		this->fire(2);
		if ( cookie_statusEvent_ )
		{
			punk<IDispatch>  disp;
			GIT git;
			git.getInterface(cookie_statusEvent_,&disp);
			disp_invoke(disp,DISPID_VALUE,variant(msg));
		}
	}

	HRESULT virtual async_transformer( BSTR filename, BSTR filter, VARIANT xsltDoc )
	{
		mol::com_init ci;

		isErr_ = VARIANT_TRUE;

		FireOnStatus( bstr("loading typelib") );

		bool b = converter_.loadTypeLib( bstr(filename).toString() );

		if (!b)
		{
			FireOnDone();
			return S_OK;
		}

		FireOnStatus( bstr("generating xml") );

		xml_ = bstr(converter_.getXML());

		HRESULT hr = transformer( xml_, filter, xsltDoc );

		FireOnDone();
		return hr;
	}

	HRESULT virtual transformer( BSTR xml, BSTR filter, VARIANT xsltDoc )
	{
		isErr_ = VARIANT_TRUE;

		if ( xsltDoc.vt == VT_EMPTY )
			return S_OK;

		FireOnStatus( bstr("loading xsl template") );

		std::string xslt("");
		if ( xsltDoc.vt == VT_BSTR )
		{
			std::string val = bstr(xsltDoc.bstrVal).tostring();
			if ( mol::Path::exists(mol::toString(val)) )
			{
				mol::filestream fs;
				if ( !fs.open(mol::tostring(val)) )
					return S_OK;
				xslt = fs.readAll();
				fs.close();
			}
			else
			{
				xslt = val;
			}
		}
		if ( xsltDoc.vt == VT_DISPATCH )
		{
			punk<IXMLDOMDocument> doc(xsltDoc.pdispVal);
			if (!doc)
				return S_OK;

			bstr src;
			if ( S_OK != doc->get_xml(&src) )
				return S_OK;

			xslt = src.tostring();
		}		

		punk<IXSLTemplate> xslTemplate;
		if (S_OK != xslTemplate.createObject(CLSID_XSLTemplate40) )
			if (S_OK != xslTemplate.createObject(CLSID_XSLTemplate) )
				return S_OK;

		punk<IXMLDOMDocument2> xsl;
		if (S_OK != xsl.createObject(CLSID_FreeThreadedDOMDocument40) )
			if (S_OK != xsl.createObject(CLSID_FreeThreadedDOMDocument) )
				return S_OK;

		VARIANT_BOOL vbSuccess = VARIANT_FALSE;
		if ( S_OK != xsl->loadXML( bstr(xslt), &vbSuccess ) )
			return S_OK;

		if ( vbSuccess == VARIANT_FALSE )
			return S_OK;

		if ( S_OK != xsl->put_async(VARIANT_FALSE) )
			return S_OK;

		if ( S_OK != xslTemplate->putref_stylesheet(xsl) )
			return S_OK;

		FireOnStatus( bstr("processing xslt transformation") );

		punk<IXMLDOMDocument2> doc;
		if (S_OK != doc.createObject(CLSID_DOMDocument) )
			return S_OK;

		vbSuccess = VARIANT_FALSE;
		if ( S_OK != doc->loadXML( xml, &vbSuccess ) )
			return S_OK;

		if ( vbSuccess == VARIANT_FALSE )
			return S_OK;

		punk<IXSLProcessor> processor;
		if ( S_OK != xslTemplate->createProcessor(&processor) || !processor )
			return S_OK;

		if ( filter && bstr(filter).tostring() != "" )
		if ( S_OK != processor->addParameter( bstr("object"), variant(filter), bstr("") ) )
			return S_OK;

		punk<IDispatch> disp(doc);
		variant vxml(disp);
		if ( S_OK != processor->put_input( vxml ) )
			return S_OK;

		vbSuccess = VARIANT_FALSE;
		if ( S_OK != processor->transform( &vbSuccess ) || vbSuccess == VARIANT_FALSE )
			return S_OK;

		variant v;
		if ( S_OK != processor->get_output(&v) )
			return S_OK;

		if ( v.vt == VT_BSTR )
		{
			resultDoc_ = v.bstrVal;
			isErr_ = VARIANT_FALSE;
		}
		return S_OK;
	}

	


	TypeLib2XML	converter_;
	VARIANT_BOOL isErr_;
	DWORD cookie_completeEvent_;
	DWORD cookie_statusEvent_;

	bstr resultDoc_;
	bstr xml_;
};
*/

#endif