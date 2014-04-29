#ifndef _DEF_HTMLCOM_DEFINE_
#define _DEF_HTMLCOM_DEFINE_

#include "util/uni.h"
#include "util/str.h"
#include "ole/punk.h"
#include "ole/variant.h"
#include "ole/host.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "ole/HtmlEvents_h.h"
#include "ole/stream.h"

#include "ole/urlmoniker.h"
#include "win/res.h"
#include "util/str.h"

#include <initguid.h>
#include <Mshtml.h>
#include <shlwapi.h>
#include <tom.h>
#include <Exdisp.h>

namespace mol  {

	extern const CLSID CGID_IWebBrowser;

	namespace ie   {

		//{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}

		class webbrowser_events : 
			public mol::Dispatch< IWebBrowserEvents >,
			public mol::interfaces< webbrowser_events, 
						mol::implements< 
								IDispatch, 
								DWebBrowserEvents2> >
		{
		public:

			HRESULT virtual __stdcall StatusTextChange(BSTR Text) 
			{ return S_OK; }

			HRESULT virtual __stdcall ProgressChange(long Progress, long ProgressMax) 
			{ return S_OK; }

			HRESULT virtual __stdcall CommandStateChange(long Command,  VARIANT_BOOL Enable) 
			{ return S_OK; }

			HRESULT virtual __stdcall DownloadBegin() 
			{ return S_OK; }

			HRESULT virtual __stdcall DownloadComplete() 
			{ return S_OK; }

			HRESULT virtual __stdcall TitleChange(BSTR Text) 
			{ return S_OK; }

			HRESULT virtual __stdcall PropertyChange(BSTR szProperty) 
			{ return S_OK; }

			HRESULT virtual __stdcall BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel) 
			{ return S_OK; }

			HRESULT virtual __stdcall NewWindow2( IDispatch** ppDisp, VARIANT_BOOL* Cancel) 
			{ return S_OK; }

			HRESULT virtual __stdcall NavigateComplete2( IDispatch* pDisp,  VARIANT* URL) 
			{ return S_OK; }

			HRESULT virtual __stdcall DocumentComplete( IDispatch* pDisp,  VARIANT* URL) 
			{ return S_OK; }

			HRESULT virtual __stdcall OnQuit() 
			{ return S_OK; }

			HRESULT virtual __stdcall OnVisible( VARIANT_BOOL Visible) 
			{ return S_OK; }

			HRESULT virtual __stdcall OnToolBar( VARIANT_BOOL ToolBar) 
			{ return S_OK; }

			HRESULT virtual __stdcall OnMenuBar( VARIANT_BOOL MenuBar) 
			{ return S_OK; }

			HRESULT virtual __stdcall OnStatusBar( VARIANT_BOOL StatusBar) 
			{ return S_OK; }

			HRESULT virtual __stdcall OnFullScreen( VARIANT_BOOL FullScreen) 
			{ return S_OK; }

			HRESULT virtual __stdcall OnTheaterMode( VARIANT_BOOL TheaterMode) 
			{ return S_OK; }

			HRESULT virtual __stdcall WindowSetResizable( VARIANT_BOOL Resizable) 
			{ return S_OK; }

			HRESULT virtual __stdcall WindowSetLeft( long Left) 
			{ return S_OK; }

			HRESULT virtual __stdcall WindowSetTop( long Top) 
			{ return S_OK; }

			HRESULT virtual __stdcall WindowSetWidth( long Width) 
			{ return S_OK; }

			HRESULT virtual __stdcall WindowSetHeight( long Height) 
			{ return S_OK; }

			HRESULT virtual __stdcall WindowClosing( VARIANT_BOOL IsChildWindow, VARIANT_BOOL* Cancel) 
			{ return S_OK; }

			HRESULT virtual __stdcall ClientToHostWindow( long* CX, long* CY) 
			{ return S_OK; }

			HRESULT virtual __stdcall SetSecureLockIcon(long SecureLockIcon) 
			{ return S_OK; }

			HRESULT virtual __stdcall FileDownload( VARIANT_BOOL* Cancel) 
			{ return S_OK; }

			HRESULT virtual __stdcall NavigateError(IDispatch* pDisp,  VARIANT* URL,  VARIANT* Frame, VARIANT* StatusCode, VARIANT_BOOL* Cancel) 
			{ return S_OK; }

			HRESULT virtual __stdcall PrintTemplateInstantiation( IDispatch* pDisp) 
			{ return S_OK; }

			HRESULT virtual __stdcall PrintTemplateTeardown(IDispatch* pDisp) 
			{ return S_OK; }

			HRESULT virtual __stdcall UpdatePageStatus(IDispatch* pDisp, VARIANT* nPage, VARIANT* fDone) 
			{ return S_OK; }

			HRESULT virtual __stdcall PrivacyImpactedStateChange(VARIANT_BOOL bImpacted) 
			{ return S_OK; }


		};

		class ie_event_sink : public webbrowser_events
		{
		public:

			HRESULT Advise(IUnknown* object )
			{
				return mol::advise<DWebBrowserEvents2>(object,this,cookie_);
			}
			HRESULT UnAdvise(IUnknown* object )
			{
				return mol::unadvise<DWebBrowserEvents2>(object,cookie_);
			}

		private:
			DWORD           cookie_;
		};


	class HtmlWndBase 
	{
	public:
		HtmlWndBase()
			: nextSearchPos_(0)
		{}

		~HtmlWndBase()
		{}

		// accessors
		HRESULT	ie(IWebBrowser2** wb);
		HRESULT	doc(IDispatch** disp);
		HRESULT	doc2(IHTMLDocument2** doc);

		// impl
		std::wstring charsetImpl();
		bool aboutBlankImpl();			
		bool setHtmlImpl( const std::string& html, const std::string& url, const std::string& mime);
		bool setHtmlImpl( const std::wstring& html );
		bool writeImpl(const std::wstring& html);
		void getSourceImpl(std::string& src);

		//screenshot impl
		BOOL IPictureFromHtmlControlImpl( IPicture** pic );
		BOOL IPictureDispFromHtmlControlImpl( IPictureDisp** pic );

		// find in page impl
		int findImpl(const std::wstring& txt, int options);
		int findUpImpl(const std::wstring& txt, int options);

	protected:

		// communication with derived class
		virtual IOleObject* getOleObject() = 0;
		virtual HWND getHtmlWnd() = 0;

		// data members
		std::wstring		        searchText_;
		int					        nextSearchPos_;
		int					        lastSearchDir_;  

		// dummy security manager
		class SecurityMgr :
			public IInternetSecurityManager,
			public mol::interfaces< SecurityMgr, mol::implements< IInternetSecurityManager> >
		{
		public:

			typedef mol::com_instance<SecurityMgr> Instance;
			static Instance* CreateInstance()
			{
				Instance* i = new Instance;
				return i;
			}

			virtual void dispose() {}

			HRESULT virtual __stdcall   SetSecuritySite( IInternetSecurityMgrSite *pSite)
			{
				return INET_E_DEFAULT_ACTION;
			}        
			HRESULT virtual __stdcall   GetSecuritySite( IInternetSecurityMgrSite **ppSite)
			{
				return INET_E_DEFAULT_ACTION;
			}        
			HRESULT virtual __stdcall   MapUrlToZone( LPCWSTR pwszUrl, DWORD *pdwZone, DWORD dwFlags)
			{
				return INET_E_DEFAULT_ACTION;
			}        
			HRESULT virtual __stdcall   GetSecurityId( LPCWSTR pwszUrl, BYTE *pbSecurityId, DWORD *pcbSecurityId, DWORD_PTR dwReserved)
			{
				return INET_E_DEFAULT_ACTION;
			}  
			HRESULT virtual __stdcall   ProcessUrlAction( LPCWSTR pwszUrl, DWORD dwAction, BYTE *pPolicy, DWORD cbPolicy, BYTE *pContext, DWORD cbContext, DWORD dwFlags, DWORD dwReserved)
			{
				*pPolicy = URLPOLICY_ALLOW;
				return S_OK;
			}        
			HRESULT virtual __stdcall   QueryCustomPolicy( LPCWSTR pwszUrl, REFGUID guidKey, BYTE **ppPolicy, DWORD *pcbPolicy, BYTE *pContext, DWORD cbContext, DWORD dwReserved)
			{
				return INET_E_DEFAULT_ACTION;
			}  

			HRESULT virtual __stdcall   SetZoneMapping( DWORD dwZone, LPCWSTR lpszPattern, DWORD dwFlags)
			{
				return INET_E_DEFAULT_ACTION;
			}  

			HRESULT virtual __stdcall   GetZoneMappings( DWORD dwZone, IEnumString **ppenumString,DWORD dwFlags)
			{
				return INET_E_DEFAULT_ACTION;
			}  

		};
	};


	} // endnamespace mol::win::ie

	//////////////////////////////////////////////////////////////////////
	// HTML Wnd
	//////////////////////////////////////////////////////////////////////


	template<class C, class W>
	class HtmlWnd : 
			public mol::AxWnd<C,W,&CLSID_WebBrowser>, 
			public mol::ie::HtmlWndBase
	{
	public:
		HtmlWnd()
		{}

		~HtmlWnd()
		{}

		// styles
		virtual int style()                 { return WS_CHILD | WS_CLIPSIBLINGS|WS_VISIBLE; }
		virtual DWORD UIflags()             { return DOCHOSTUIFLAG_NO3DBORDER|DOCHOSTUIFLAG_FLAT_SCROLLBAR; } //DOCHOSTUIFLAG_DIALOG
		virtual HRESULT hideContextMenu()   { return S_OK; }


		//events
		void  advise  ( mol::ie::ie_event_sink& eventSink )
		{
			eventSink.Advise(oleObject);
		}

		void  unAdvise( mol::ie::ie_event_sink& eventSink  )
		{
			eventSink.UnAdvise(oleObject);
		}

		// COM overrides

		HRESULT virtual __stdcall  IDocHostUIHandler_GetHostInfo( DOCHOSTUIINFO *pInfo)
		{
			pInfo->cbSize        = sizeof(DOCHOSTUIINFO);
			pInfo->dwFlags       = this->UIflags();
			pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

			return S_OK;
		}

		HRESULT virtual __stdcall  IOleClientSite_ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
		{
			return this->hideContextMenu();
		}

		HRESULT virtual __stdcall  IServiceProvider_QueryService( REFGUID guidService, REFIID riid, void** ppvObject)
		{
			if ( !ppvObject )
				return E_INVALIDARG;

			if ( ::IsEqualGUID( guidService, SID_SInternetSecurityManager ) )
				if ( ::IsEqualIID( riid, IID_IInternetSecurityManager ) )
				{
					SecurityMgr::Instance* s = SecurityMgr::CreateInstance();
					return s->QueryInterface( IID_IInternetSecurityManager, ppvObject );
				}
				return E_NOINTERFACE;
		}


		// HTML methods
		std::wstring charset()
		{
			return this->charsetImpl();
		}

		bool setHtml( const std::string& html )
		{
			std::wstring tmp = mol::ansi2wstring(html);		
			setHtml(tmp);
			return true;
		}

		bool setHtml( const std::string& html, const std::string& url, const std::string& mime)
		{
			return this->setHtmlImpl( html, url, mime );
		}

		bool setHtmlImpl( const std::wstring& html )
		{
			return this->setHtmlImpl( html );
		}

		bool write(const std::wstring& html)
		{
			return this->writeImpl( html );
		}

		void getSource(std::string& src)
		{
			return this->getSourceImpl( html );
		}

		void getSource(std::wstring& src)
		{
			std::string ret;
			getSource(ret);
			src = mol::ansi2wstring(ret);
		}

		BOOL IPictureFromHtmlControl( IPicture** pic )
		{
			return this->IPictureFromHtmlControlImpl( pic );
		}

		BOOL IPictureDispFromHtmlControl( IPictureDisp** pic )
		{
			return this->IPictureDispFromHtmlControlImpl( pic );
		}

		// save
		HRESULT save(const std::wstring& file)
		{
			std::wstring ws = mol::towstring(file);

			mol::punk<IHTMLDocument2> html;
			HRESULT hr = doc2(&html);
			if ( hr == S_OK && html() )
			{
				mol::punk<IPersistFile>			pf(html);
				return pf->Save(ws.c_str(),FALSE);
			}
			return S_FALSE;
		}

		// browser methods
		bool aboutBlank( )			
		{
			return this->aboutBlankImpl();
		}

		bool setLocation(std::wstring url)
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return false;

			mol::variant v(url);
			HRESULT hr = wb->Navigate2(&v, 0, 0, 0, 0);

			return hr == S_OK;
		}

		std::wstring  getLocation()
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return _T("");
			mol::bstr bstr;

			wb->get_LocationURL( &bstr );
			return bstr.toString();
		}

		void stop()
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return;
			wb->Stop();
		}

		void back()
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return;
			wb->GoBack();
		}

		void forward()
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return;
			wb->GoForward();
		}

		void reload()
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return;
			mol::variant v(REFRESH_COMPLETELY);
			wb->Refresh2(&v);
			//ie->Refresh();
		}

		void home()
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return;
			wb->GoHome();
		}

		void showSource()
		{
			oleTargetExec(2);
		}

		void options()
		{
			oleTargetExec(3);
		}


		void silent(bool b)
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return ;
			VARIANT_BOOL vb = b ? VARIANT_TRUE : VARIANT_FALSE;
			wb->put_Silent(vb);
		}

		void execWb( OLECMDID n )
		{
			mol::punk<IWebBrowser2>	wb;
			if ( S_OK != ie(&wb) )
				return;
			wb->ExecWB(n,OLECMDEXECOPT_PROMPTUSER,0,0);
		}

		void oleTargetExec( DWORD n )
		{
			mol::punk<IDispatch>		dispDoc;
			mol::variant vararg;

			if ( S_OK != doc(&dispDoc) )
				return;

			mol::punk<IOleCommandTarget> oleCmdTarget(dispDoc );
			oleCmdTarget->Exec( &mol::CGID_IWebBrowser,n, OLECMDEXECOPT_PROMPTUSER, NULL, &vararg);
		}

		void oleStdTargetExec( OLECMDID n )
		{
			mol::punk<IDispatch>		dispDoc;
			mol::variant vararg;

			if ( S_OK != doc(&dispDoc) )
				return;

			mol::punk<IOleCommandTarget> oleCmdTarget(dispDoc );
			oleCmdTarget->Exec( 0,n, OLECMDEXECOPT_PROMPTUSER, NULL, &vararg);
		}

		void findDlg()
		{
			oleTargetExec(1);
		}


		int find(const std::wstring& txt, int options)
		{
			return this->findImpl( txt,options );
		}

		int findUp(const std::wstring& txt, int options)
		{
			return this->findUpImpl( txt,options  );
		}

protected:

		// communication with base class
		virtual IOleObject* getOleObject() 
		{
			return oleObject;
		}

		virtual HWND getHtmlWnd() 
		{
			return (HWND) *this;
		}

	};



/*
	template<class C, class W>
	class HtmlWnd : public mol::AxWnd<C,W,&CLSID_WebBrowser>
	{
	public:
		HtmlWnd()
			: nextSearchPos_(0)
		{}

		~HtmlWnd()
		{}

		// styles
		virtual int style()                 { return WS_CHILD | WS_CLIPSIBLINGS|WS_VISIBLE; }
		virtual DWORD UIflags()             { return DOCHOSTUIFLAG_NO3DBORDER|DOCHOSTUIFLAG_FLAT_SCROLLBAR; } //DOCHOSTUIFLAG_DIALOG
		virtual HRESULT hideContextMenu()   { return S_OK; }

		// HTML methods
		std::wstring charset()
		{
			mol::punk<IWebBrowser2>		ie(oleObject);
			mol::punk<IDispatch>		disp;
			if ( (S_OK == ie->get_Document( &disp )) && disp())
			{
				mol::bstr bstr;
				mol::punk<IHTMLDocument2>	doc;
				if ( S_OK == disp.queryInterface(IID_IHTMLDocument2,(void**)&(doc)) )
				{
					if ( S_OK == doc->get_charset(&bstr) )
						return bstr.toString();
				}
			}
			return "";
		}

		HRESULT	doc(IDispatch** disp)
		{
			if ( !disp )
				return E_INVALIDARG;

			mol::punk<IWebBrowser2>		ie(oleObject);

			return ie->get_Document(disp);
		}

		bool setHtml( const std::string& html )
		{
			std::wstring tmp = mol::ansi2wstring(html);		
			setHtml(tmp);
			return true;
		}

		bool setHtml( const std::string& html, const std::string& url, const std::string& mime)
		{
			// create a new stream with that data
			mol::Stream stream(html.c_str(),html.size());
			mol::punk<IDispatch> d;
			if ( S_OK != doc(&d) )
			{
				aboutBlank();
				if ( S_OK != doc(&d) )
					return false;
			}
			// put that stream into the HTML doc
			mol::punk<IPersistMoniker> pmon(d);
			if ( pmon )
			{
				mol::ie::BindCtx b;
				mol::punk<mol::ie::BaseUrl> baseUrl = new mol::ie::BaseUrl( url,mime, stream );
				HRESULT hr = pmon->Load(TRUE, baseUrl, b, STGM_READ ); 
				return true;
			}
			return false;
		}

		bool setHtml( const std::wstring& html )
		{
			HRESULT hr;

			mol::Stream pStream((const char*)html.c_str(),(html.size()+1)*2 );

			mol::punk<IDispatch>			disp;
			mol::punk<IWebBrowser2>		ie(oleObject);

			if ( (S_OK != ie->get_Document( &disp )) ||  (!disp()) )
			{
				aboutBlank();
				if ( (S_OK != ie->get_Document( &disp )) ||  (!disp()) )
					return false;
			}

			mol::punk<IHTMLDocument2>			htmlDoc(disp);
			mol::punk<IPersistStreamInit>		persist(htmlDoc);

			persist->InitNew();
			hr = persist->Load(pStream);

			return hr == S_OK;
		}

		bool write( const std::wstring& html )
		{
			mol::punk<IWebBrowser2>	ie(oleObject);

			mol::punk<IDispatch>	dispDoc;
			if ( (S_OK != ie->get_Document( &dispDoc )) ||  (!dispDoc()) )
			{
				aboutBlank();
				if ( (S_OK != ie->get_Document( &dispDoc )) ||  (!dispDoc()) )
					return false;
			}

			mol::punk<IHTMLDocument2>	htmlDoc(dispDoc);

			if ( !dispDoc )
				return false;

			mol::variant empty;
			mol::bstr b(html);
			mol::SafeArray<VT_VARIANT> sf(&(b.bstr_),1);

			htmlDoc->open( 0,empty,empty,empty,0);
			htmlDoc->write( sf );
			htmlDoc->close();

			return true;
		}


		void getSource(std::string& src)
		{
			mol::punk<IWebBrowser2>		ie(oleObject);
			mol::punk<IDispatch>		disp;

			STATSTG					stats;            //stats of stream to get size of stream
			LARGE_INTEGER			lint = { 0, 0 };  //hm... we just say zero
			ULONG 					size = 0;         //size to read from stream
			ULONG					len  = 0;         //actual size read from stream
			char*					buf;              //buffer to retrieve document text through stream

			src = "";

			// Retrieve the IDispatch of the document object.
			if ( (S_OK == ie->get_Document( &disp )) && disp())
			{
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
				catch (X x)
				{
					src = std::string("");
				}
			}//endif getdocument
			std::string cs = charset();
			if ( cs == "utf-8" )
			{
				src = mol::utf82ansi(src);
			}
			else if ( cs == "unicode" )
			{
				wchar_t* w = (wchar_t*)(src.data());
				std::string bom = "\xFF\xFE";

				if ( src.substr(0,2) == bom )
				{
					w = (wchar_t*)(src.data()+2);
				}    		
				std::string tmp = mol::wstring2ansi(std::wstring(w,(src.size()-2)/2));		
				src = tmp;
			}
		}


		void getSource(std::wstring& src)
		{
			std::string ret;
			getSource(ret);
			src = mol::ansi2wstring(ret);
		}

			//screenshot
		BOOL IPictureFromHtmlControl( IPicture** pic )
		{
			mol::punk<IWebBrowser2>	ie(oleObject);

			// lets make sure we are on the right side ...
			if ( (!::IsWindow(*this) ) || (!ie) || (!pic) )
				return 0;

			// get Html Document Dispatch Interface
			mol::punk<IDispatch> disp;
			HRESULT hr = ie->get_Document(&disp);
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
			hdc = ::GetWindowDC(hWnd_);
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
								::ReleaseDC(hWnd_,hdc);
								::DeleteDC(memHDC);
								return TRUE;
							}
						} // endif view->draw()
					}// endif view
					::DeleteObject(bmp);
				}// endif bmp
				::DeleteDC(memHDC);
			}// endif memDC

			::ReleaseDC(hWnd_,hdc);
			return 0;
		}

		BOOL IPictureDispFromHtmlControl( IPictureDisp** pic )
		{
			mol::punk<IWebBrowser2>	ie(oleObject);

			// lets make sure we are on the right side ...
			if ( (!::IsWindow(*this) ) || (!ie) || (!pic) )
				return 0;

			// get Html Document Dispatch Interface
			mol::punk<IDispatch> disp;
			HRESULT hr = ie->get_Document(&disp);
			if ( (hr != S_OK) || ( !disp ) )
				return 0;

			// get Document2 pointer form dispatch
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
			hdc = ::GetWindowDC(hWnd_);
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
								::ReleaseDC(hWnd_,hdc);
								::DeleteDC(memHDC);
								return TRUE;
							}
						} // endif view->draw()
					}// endif view
					::DeleteObject(bmp);
				}// endif bmp
				::DeleteDC(memHDC);
			}// endif memDC

			::ReleaseDC(hWnd_,hdc);
			return 0;
		}

		//events
		void  advise  ( mol::ie::ie_event_sink& eventSink )
		{
			eventSink.Advise(oleObject);
		}

		void  unAdvise( mol::ie::ie_event_sink& eventSink  )
		{
			eventSink.UnAdvise(oleObject);
		}

		// save
		HRESULT save(const std::wstring& file)
		{
			std::wstring ws = mol::ansi2wstring(file);

			mol::punk<IWebBrowser2>		ie(oleObject);
			mol::punk<IDispatch>		disp;
			HRESULT hr ;
			hr = ie->get_Document(&disp);
			if ( hr == S_OK && disp() )
			{
				mol::punk<IHTMLDocument2>		pHtmlDoc(disp);
				mol::punk<IPersistFile>			pf(pHtmlDoc);
				return pf->Save(ws.c_str(),FALSE);
			}
			return S_FALSE;
		}

		// browser methods
		bool aboutBlank( )			
		{
			mol::punk<IWebBrowser2>	ie(oleObject);

			mol::variant v("about:blank");
			HRESULT hr = ie->Navigate2( &v, 0, 0, 0, 0);

			return (hr == S_OK);
		}

		bool setLocation(std::wstring url)
		{
			mol::punk<IWebBrowser2>	ie(oleObject);

			mol::variant v(url);
			HRESULT hr = ie->Navigate2(&v, 0, 0, 0, 0);

			return hr == S_OK;
		}

		std::wstring  getLocation()
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			mol::bstr bstr;

			ie->get_LocationURL( &bstr );
			return bstr.toString();
		}

		void stop()
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			ie->Stop();
		}

		void back()
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			ie->GoBack();
		}

		void forward()
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			ie->GoForward();
		}

		void reload()
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			mol::variant v(REFRESH_COMPLETELY);
			ie->Refresh2(&v);
			//ie->Refresh();
		}

		void home()
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			ie->GoHome();
		}

		void showSource()
		{
			oleTargetExec(2);
		}

		void options()
		{
			oleTargetExec(3);
		}


		void silent(bool b)
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			VARIANT_BOOL vb = b ? VARIANT_TRUE : VARIANT_FALSE;
			ie->put_Silent(vb);
		}

		void execWb( OLECMDID n )
		{
			mol::punk<IWebBrowser2>	ie(oleObject);
			ie->ExecWB(n,OLECMDEXECOPT_PROMPTUSER,0,0);
		}

		void oleTargetExec( DWORD n )
		{
			mol::punk<IWebBrowser2>		ie(oleObject);
			mol::punk<IDispatch>		dispDoc;
			mol::variant vararg;

			if ( (S_OK == ie->get_Document( &dispDoc )) && ( *(&dispDoc)) )
			{
				mol::punk<IOleCommandTarget> oleCmdTarget(dispDoc );
				oleCmdTarget->Exec( &mol::CGID_IWebBrowser,n, OLECMDEXECOPT_PROMPTUSER, NULL, &vararg);
			}
		}

		void oleStdTargetExec( OLECMDID n )
		{
			mol::punk<IWebBrowser2>		ie(oleObject);
			mol::punk<IDispatch>		dispDoc;
			mol::variant vararg;

			if ( (S_OK == ie->get_Document( &dispDoc )) && ( *(&dispDoc)) )
			{
				mol::punk<IOleCommandTarget> oleCmdTarget(dispDoc );
				oleCmdTarget->Exec( 0,n, OLECMDEXECOPT_PROMPTUSER, NULL, &vararg);
			}
		}
		void findDlg()
		{
			oleTargetExec(1);
		}

		int find(const std::wstring& txt, int options )
		{
			if ( (lastSearchDir_ & FR_DOWN) != ( options & FR_DOWN ) )
			{
				nextSearchPos_=0;		
			}

			lastSearchDir_ = options;

			if ( !(options & FR_DOWN) )
				return findUp(txt,options);

			mol::punk<IWebBrowser2>			ie(oleObject);
			mol::punk<IDispatch>			pDisp;
			mol::punk<IDispatch>			pDispBody;

			bool	ret   = true;
			bool	found = true;
			int		o     = options -1;

			// Retrieve the document object.
			if ( (S_OK == ie->get_Document( &pDisp )) && pDisp() )
			{
				mol::punk<IHTMLDocument2>			pHtmlDoc(pDisp);
				mol::punk<IHTMLElement>				pHtmlElement;
				if ( S_OK == pHtmlDoc->get_body( (IHTMLElement**)(&pHtmlElement) ) )
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
			}//endif get_doc
			return ret;
		}




		int findUp(const std::wstring& txt, int options )
		{
			mol::punk<IWebBrowser2>			ie(oleObject);
			mol::punk<IDispatch>			pDisp;
			mol::punk<IDispatch>			pDispBody;

			bool	ret   = true;
			bool	found = true;
			int		o     = options;

			// Retrieve the document object.
			if ( (S_OK == ie->get_Document( &pDisp )) && pDisp() )
			{
				mol::punk<IHTMLDocument2>			pHtmlDoc(pDisp);
				mol::punk<IHTMLElement>				pHtmlElement;
				if ( S_OK == pHtmlDoc->get_body( (IHTMLElement**)(&pHtmlElement) ) )
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
			}//endif get_doc
			return ret;
		}

		HRESULT virtual __stdcall  IDocHostUIHandler_GetHostInfo( DOCHOSTUIINFO *pInfo)
		{
			pInfo->cbSize        = sizeof(DOCHOSTUIINFO);
			pInfo->dwFlags       = this->UIflags();
			pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

			return S_OK;
		}

		HRESULT virtual __stdcall  IOleClientSite_ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
		{
			return this->hideContextMenu();
		}

		HRESULT virtual __stdcall  IServiceProvider_QueryService( REFGUID guidService, REFIID riid, void** ppvObject)
		{
			if ( !ppvObject )
				return E_INVALIDARG;

			if ( ::IsEqualGUID( guidService, SID_SInternetSecurityManager ) )
				if ( ::IsEqualIID( riid, IID_IInternetSecurityManager ) )
				{
					SecurityMgr::Instance* s = SecurityMgr::CreateInstance();
					return s->QueryInterface( IID_IInternetSecurityManager, ppvObject );
				}
				return E_NOINTERFACE;
		}

		virtual IOleObject* getOleObject() 
		{
			return oleObject;
		}

		virtual HWND getHtmlWnd() 
		{
			return (HWND) *this;
		}

	protected:
		std::wstring			        searchText_;
		int					        nextSearchPos_;
		int					        lastSearchDir_;  

		class SecurityMgr :
			public IInternetSecurityManager,
			public mol::interfaces< SecurityMgr, mol::implements< IInternetSecurityManager> >
		{
		public:

			typedef mol::com_instance<SecurityMgr> Instance;
			static Instance* CreateInstance()
			{
				Instance* i = new Instance;
				return i;
			}

			virtual void dispose() {}

			HRESULT virtual __stdcall   SetSecuritySite( IInternetSecurityMgrSite *pSite)
			{
				return INET_E_DEFAULT_ACTION;
			}        
			HRESULT virtual __stdcall   GetSecuritySite( IInternetSecurityMgrSite **ppSite)
			{
				return INET_E_DEFAULT_ACTION;
			}        
			HRESULT virtual __stdcall   MapUrlToZone( LPCWSTR pwszUrl, DWORD *pdwZone, DWORD dwFlags)
			{
				return INET_E_DEFAULT_ACTION;
			}        
			HRESULT virtual __stdcall   GetSecurityId( LPCWSTR pwszUrl, BYTE *pbSecurityId, DWORD *pcbSecurityId, DWORD_PTR dwReserved)
			{
				return INET_E_DEFAULT_ACTION;
			}  
			HRESULT virtual __stdcall   ProcessUrlAction( LPCWSTR pwszUrl, DWORD dwAction, BYTE *pPolicy, DWORD cbPolicy, BYTE *pContext, DWORD cbContext, DWORD dwFlags, DWORD dwReserved)
			{
				*pPolicy = URLPOLICY_ALLOW;
				return S_OK;
			}        
			HRESULT virtual __stdcall   QueryCustomPolicy( LPCWSTR pwszUrl, REFGUID guidKey, BYTE **ppPolicy, DWORD *pcbPolicy, BYTE *pContext, DWORD cbContext, DWORD dwReserved)
			{
				return INET_E_DEFAULT_ACTION;
			}  

			HRESULT virtual __stdcall   SetZoneMapping( DWORD dwZone, LPCWSTR lpszPattern, DWORD dwFlags)
			{
				return INET_E_DEFAULT_ACTION;
			}  

			HRESULT virtual __stdcall   GetZoneMappings( DWORD dwZone, IEnumString **ppenumString,DWORD dwFlags)
			{
				return INET_E_DEFAULT_ACTION;
			}  

		};
	};
*/
	///////////////////////////////////////////////////////////




} // endnamespace mol

#endif


