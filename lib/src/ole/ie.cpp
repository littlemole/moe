#include "ole/stream.h"
#include "ole/ie.h"
#include "ole/urlmoniker.h"
#include "win/res.h"
#include "util/str.h"

#include <initguid.h>
#include <Mshtml.h>
#include <shlwapi.h>
#include <tom.h>

namespace mol  {


DEFINE_GUID(CGID_IWebBrowser, 0xED016940L,0xBD5B, 0x11cf, 0xBA, 0x4E, 0x00,0xC0,0x4f,0xD7,0x08,0x16);

namespace ie {

HRESULT	HtmlWndBase::ie(IWebBrowser2** wb)
{
	if ( !wb )
		return E_INVALIDARG;

	return this->getOleObject()->QueryInterface(IID_IWebBrowser2, (void**) wb );
}

HRESULT	HtmlWndBase::doc(IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	mol::punk<IWebBrowser2>		ie(this->getOleObject());

	if (!ie)
		return E_FAIL;

	return ie->get_Document(disp);
}

HRESULT	HtmlWndBase::doc2(IHTMLDocument2** doc)
{
	if ( !doc )
		return E_INVALIDARG;

	*doc = 0;
	mol::punk<IDispatch>			disp;
	HRESULT hr = this->doc(&disp);
	if ( hr != S_OK || !disp )
		return hr;

	return disp->QueryInterface(IID_IHTMLDocument2, (void**)doc);
}


mol::string HtmlWndBase::charsetImpl()
{
	mol::punk<IHTMLDocument2>	doc;
	if ( S_OK != this->doc2(&doc) )
		return _T("");

	mol::bstr bstr;
	if ( S_OK == doc->get_charset(&bstr) )
		return bstr.toString();

	return _T("");
}

bool HtmlWndBase::aboutBlankImpl( )			
{
	mol::punk<IWebBrowser2>	wb;
	if ( S_OK != ie(&wb) )
		return false;

	mol::variant v("about:blank");
	HRESULT hr = wb->Navigate2( &v, 0, 0, 0, 0);

	return (hr == S_OK);
}

bool HtmlWndBase::setHtmlImpl( const std::string& html, const std::string& url, const std::string& mime)
{
	// create a new stream with that data
	mol::Stream stream(html.c_str(), (int)html.size());
	mol::punk<IDispatch> d;

	if ( S_OK != doc(&d) )
	{
		aboutBlankImpl();
		if ( S_OK != doc(&d) )
			return false;
	}
	// put that stream into the HTML doc
	mol::punk<IPersistMoniker> pmon(d);
	if ( pmon )
	{
		mol::ie::BindCtx b;
		mol::punk<mol::ie::BaseUrl> baseUrl = new mol::ie::BaseUrl( mol::toString(url),mol::toString(mime), stream );
		HRESULT hr = pmon->Load(TRUE, baseUrl, b, STGM_READ ); 
		return true;
	}
	return false;
}

bool HtmlWndBase::setHtmlImpl( const std::wstring& html )
{
	HRESULT hr;

	mol::Stream pStream((const char*)html.c_str(), (int)(html.size()+1)*2 );

	mol::punk<IDispatch> d;

	if ( S_OK != doc(&d) )
	{
		aboutBlankImpl();
		if ( S_OK != doc(&d) )
			return false;
	}

	mol::punk<IHTMLDocument2>			htmlDoc(d);
	mol::punk<IPersistStreamInit>		persist(htmlDoc);

	persist->InitNew();
	hr = persist->Load(pStream);

	return hr == S_OK;
}

bool HtmlWndBase::writeImpl( const mol::string& html )
{
	mol::punk<IDispatch> d;

	if ( S_OK != doc(&d) )
	{
		aboutBlankImpl();
		if ( S_OK != doc(&d) )
			return false;
	}

	mol::punk<IHTMLDocument2>	htmlDoc(d);

	mol::variant empty;
	mol::bstr b(html);
	mol::SafeArray<VT_VARIANT> sf(&(b.bstr_),1);

	htmlDoc->open( 0,empty,empty,empty,0);
	htmlDoc->write( sf );
	htmlDoc->close();

	return true;
}

void HtmlWndBase::getSourceImpl(std::string& src)
{
	STATSTG					stats;            //stats of stream to get size of stream
	LARGE_INTEGER			lint = { 0, 0 };  //hm... we just say zero
	ULONG 					size = 0;         //size to read from stream
	ULONG					len  = 0;         //actual size read from stream
	char*					buf;              //buffer to retrieve document text through stream

	src = "";

	mol::punk<IDispatch> disp;
	if ( S_OK != doc(&disp) )
		return;

	try
	{
		// Query for IPersistStreamInit.
		mol::punk<IPersistStreamInit>	persistStreamInit(disp);
		//prepare a stream to save to
		mol::punk<IStream>				stream;
		if (S_OK == CreateStreamOnHGlobal( 0, true, &stream))
		{
			// Save sozrce-txt to the stream.
			if ( S_OK == persistStreamInit->Save( stream,true ))
			{
				//get size of source
				if ( S_OK == stream->Stat(&stats,STATFLAG_NONAME ))
				{
					size = (ULONG)(stats.cbSize.QuadPart);
					//prepare a text (char) buffer big enough on the heap, but init to ""
					buf = new char[size+1];
					buf[0]=0;
					// reset seek-position to beginning of stream
					if ( S_OK == stream->Seek(lint,  STREAM_SEEK_SET ,0))
					{
						// read from stream to my buf
						if ( S_OK == stream->Read(buf,size,&len))
						{
							// add c-style zero, create a string object
							// and finalle return after cleanup
							buf[len]=0;
							src = std::string(buf,len);
						}
					}//endif seek
					delete[] buf;
				} // endif stats
			} //endif save
		}//endif create stream HGLOBAL
	}//end try
	catch (X )
	{
		src = std::string("");
	}

	std::string cs = mol::tostring(charsetImpl());
	if ( cs == "utf-8" )
	{
		src = mol::tostring(mol::fromUTF8(src));
	}
	else if ( cs == "unicode" )
	{
		wchar_t* w = (wchar_t*)(src.data());
		std::string bom = "\xFF\xFE";

		if ( src.substr(0,2) == bom )
		{
			w = (wchar_t*)(src.data()+2);
		}    		
		std::string tmp = mol::tostring(std::wstring(w,(src.size()-2)/2));		
		src = tmp;
	}
}

//screenshot
BOOL HtmlWndBase::IPictureFromHtmlControlImpl( IPicture** pic )
{
	mol::punk<IWebBrowser2>	wb;//
	if ( S_OK != ie(&wb) )
		return FALSE;

	HWND wnd = this->getHtmlWnd();

	// lets make sure we are on the right side ...
	if ( (!::IsWindow(wnd) ) || (!wb) || (!pic) )
		return 0;

	// get Html Document Dispatch Interface
	mol::punk<IDispatch> disp;
	HRESULT hr = doc(&disp);
	if ( (hr != S_OK) || ( !disp ) )
		return 0;

	// get Document2 pointer from dispatch
	mol::punk<IHTMLDocument2> doc(disp);
	if (!doc)
		return 0;

	// get body element
	mol::punk<IHTMLElement> el;
	hr = doc->get_body(&el);
	if ( (hr != S_OK) || (!el) )
		return 0;

	// get body size
	long width,height;
	width = height = 0;
	hr = el->get_offsetWidth(&width);
	if ( hr != S_OK )
		return 0;

	hr = el->get_offsetHeight(&height);
	if ( hr != S_OK )
		return 0;

	// play with good old GDI to get a Snapshot
	// of IEs rendered HTML

	HDC     hdc    = NULL;
	HDC     memHDC = NULL;
	HBITMAP bmp    = NULL;

	// get device context for our IE window
	hdc = ::GetWindowDC(wnd);
	if ( !hdc )
		return 0;

	// create compatible DC in Memory
	memHDC = ::CreateCompatibleDC(hdc);
	if ( memHDC)
	{
		// create a BMP Handle to connect with memory DC
		bmp = ::CreateCompatibleBitmap(hdc, width, height);
		if ( bmp )
		{
			HBITMAP oldBmp = (HBITMAP)::SelectObject(memHDC, bmp);

			// draw rendered HTML via IViewObject
			RECTL rl = {0,0,0,0};
			rl.right  = width;
			rl.bottom = height;

			mol::punk<IViewObject2> view(disp);
			if ( view )
			{
				if ( S_OK == view->Draw( DVASPECT_DOCPRINT, -1,0,0,0, memHDC,&rl,0,0,0))
				{
					// describe our picture for OLE
					PICTDESC desc;
					desc.cbSizeofstruct = sizeof(desc);
					desc.picType        = PICTYPE_BITMAP ;
					desc.bmp.hbitmap    = bmp;
					desc.bmp.hpal       = (HPALETTE)::GetCurrentObject( memHDC, OBJ_PAL );

					// use OLE to retrieve an IPictureDisp for that bmp
					hr = OleCreatePictureIndirect( &desc, IID_IPicture, TRUE, (void**)pic);

					// cleanUp GDI ressources
					::SelectObject(memHDC,oldBmp);

					// success?
					if ( hr == S_OK )
					{
						//::DeleteObject(bmp); // NO! IPicture now owns it
						::ReleaseDC(wnd,hdc);
						::DeleteDC(memHDC);
						return TRUE;
					}
				} // endif view->draw()
			}// endif view
			::DeleteObject(bmp);
		}// endif bmp
		::DeleteDC(memHDC);
	}// endif memDC

	::ReleaseDC(wnd,hdc);
	return 0;
}

BOOL HtmlWndBase::IPictureDispFromHtmlControlImpl( IPictureDisp** pic )
{
	mol::punk<IWebBrowser2>	wb;
	if ( S_OK != ie(&wb) )
		return FALSE;

	HWND wnd = this->getHtmlWnd();
	// lets make sure we are on the right side ...
	if ( (!::IsWindow(wnd) ) || (!wb) || (!pic) )
		return 0;

	// get Html Document Dispatch Interface
	mol::punk<IDispatch> disp;
	HRESULT hr = doc(&disp);
	if ( (hr != S_OK) || ( !disp ) )
		return 0;

	// get Document2 pointer form dispatch
	mol::punk<IHTMLDocument2> d(disp);
	if (!d)
		return 0;

	// get body element
	mol::punk<IHTMLElement> el;
	hr = d->get_body(&el);
	if ( (hr != S_OK) || (!el) )
		return 0;

	// get body size
	long width,height;
	width = height = 0;
	hr = el->get_offsetWidth(&width);
	if ( hr != S_OK )
		return 0;

	hr = el->get_offsetHeight(&height);
	if ( hr != S_OK )
		return 0;

	// play with good old GDI to get a Snapshot
	// of IEs rendered HTML

	HDC     hdc    = NULL;
	HDC     memHDC = NULL;
	HBITMAP bmp    = NULL;

	// get device context for our IE window
	hdc = ::GetWindowDC(wnd);
	if ( !hdc )
		return 0;

	// create compatible DC in Memory
	memHDC = ::CreateCompatibleDC(hdc);
	if ( memHDC)
	{
		// create a BMP Handle to connect with memory DC
		bmp = ::CreateCompatibleBitmap(hdc, width, height);
		if ( bmp )
		{
			HBITMAP oldBmp = (HBITMAP)::SelectObject(memHDC, bmp);

			// draw rendered HTML via IViewObject
			RECTL rl = {0,0,0,0};
			rl.right  = width;
			rl.bottom = height;

			mol::punk<IViewObject2> view(disp);
			if ( view )
			{
				if ( S_OK == view->Draw( DVASPECT_DOCPRINT, -1,0,0,0, memHDC,&rl,0,0,0))
				{
					// describe our picture for OLE
					PICTDESC desc;
					desc.cbSizeofstruct = sizeof(desc);
					desc.picType        = PICTYPE_BITMAP ;
					desc.bmp.hbitmap    = bmp;
					desc.bmp.hpal       = (HPALETTE)::GetCurrentObject( memHDC, OBJ_PAL );

					// use OLE to retrieve an IPictureDisp for that bmp
					hr = OleCreatePictureIndirect( &desc, IID_IPictureDisp, TRUE, (void**)pic);

					// cleanUp GDI ressources
					::SelectObject(memHDC,oldBmp);

					// success?
					if ( hr == S_OK )
					{
						//::DeleteObject(bmp); // NO IPicture now owns it!
						::ReleaseDC(wnd,hdc);
						::DeleteDC(memHDC);
						return TRUE;
					}
				} // endif view->draw()
			}// endif view
			::DeleteObject(bmp);
		}// endif bmp
		::DeleteDC(memHDC);
	}// endif memDC

	::ReleaseDC(wnd,hdc);
	return 0;
}


int HtmlWndBase::findImpl(const mol::string& txt, int options )
{
	if ( (lastSearchDir_ & FR_DOWN) != ( options & FR_DOWN ) )
	{
		nextSearchPos_=0;		
	}

	lastSearchDir_ = options;

	if ( !(options & FR_DOWN) )
		return findUpImpl(txt,options);

	mol::punk<IHTMLDocument2> html;
	if (S_OK != doc2(&html) )
		return 0;


	bool	ret   = true;
	bool	found = true;
	int		o     = options -1;

	mol::punk<IHTMLElement>				pHtmlElement;
		
	if ( S_OK == html->get_body( (IHTMLElement**)(&pHtmlElement) ) )
		{
			mol::punk<IHTMLBodyElement>			pHtmlBody(pHtmlElement);
			mol::punk<IHTMLTxtRange>			pTxtRange;

			HRESULT r = pHtmlBody->createTextRange( &pTxtRange );
			if ( (r==S_OK )&& pTxtRange() )
			{
				mol::bstr			b(txt);
				mol::variant		vbResult(true);

				mol::bstr bm;
				pTxtRange->getBookmark(&bm);
				pTxtRange->collapse(VARIANT_TRUE);

				for ( int i = 0; i < nextSearchPos_; i++)
				{
					pTxtRange->findText( b,1 ,o,&(vbResult.boolVal));
					if ( vbResult.boolVal == VARIANT_TRUE )
					{
						pTxtRange->collapse(VARIANT_FALSE);
					}
					else
					{
						ret = found = false;
						nextSearchPos_ = 0;
						pTxtRange->collapse(VARIANT_FALSE);
						break;
					}
				}
				if (found==true)
				{
					nextSearchPos_++;
					pTxtRange->findText( b,tomForward,o,&(vbResult.boolVal ));
					if ( vbResult.boolVal != VARIANT_FALSE )
					{
						pTxtRange->scrollIntoView();
						pTxtRange->select();
						pTxtRange->collapse(VARIANT_FALSE);
					}
					else
					{
						ret = false;
						nextSearchPos_=0;
					}
				}//endif found=true
			}//endif textrange
		}//endif get_body
	return ret;
}

int HtmlWndBase::findUpImpl(const mol::string& txt, int options )
{
	mol::punk<IHTMLDocument2>	html;
	if ( S_OK != doc2(&html) )
		return 0;

	bool	ret   = true;
	bool	found = true;
	int		o     = options;

		mol::punk<IHTMLElement>				pHtmlElement;
		if ( S_OK == html->get_body( (IHTMLElement**)(&pHtmlElement) ) )
		{
			mol::punk<IHTMLBodyElement>			pHtmlBody(pHtmlElement);
			mol::punk<IHTMLTxtRange>			pTxtRange;

			HRESULT r = pHtmlBody->createTextRange( &pTxtRange );
			if ( (r==S_OK )&& pTxtRange() )
			{

				mol::bstr			b(txt);
				mol::variant		vbResult(true);
				mol::variant		vbCollapseType(true);

				mol::bstr bm;
				pTxtRange->getBookmark(&bm);

				for ( int i = 0; i < nextSearchPos_; i++)
				{
					pTxtRange->findText( b,-1,o,&(vbResult.boolVal ));
					if ( vbResult.boolVal == VARIANT_TRUE )
					{
						pTxtRange->collapse(VARIANT_TRUE );
					}
					else
					{
						ret = found = false;
						nextSearchPos_ = 0;
						pTxtRange->collapse(VARIANT_TRUE );
						break;
					}
				}
				if (found==true)
				{
					nextSearchPos_++;
					pTxtRange->findText( b,-1,o,&(vbResult.boolVal ));
					if ( vbResult.boolVal != VARIANT_FALSE )
					{
						pTxtRange->scrollIntoView();
						pTxtRange->select();
						pTxtRange->collapse(VARIANT_TRUE );
					}
					else
					{
						ret = false;
						nextSearchPos_=0;
					}
				}//endif found=true
			}//endif textrange
		}//endif get_body
	return ret;
}


} // endnamespace ie
} // endnamespace mol




