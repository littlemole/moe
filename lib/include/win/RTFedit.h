#ifndef MOL_RICHEDITCTRL_DEF_
#define MOL_RICHEDITCTRL_DEF_

#include "win/Ctrl.h"
#include <Richedit.h>
#include <Richole.h>
#include <Commdlg.h>
#include <ole/obj.h>
#include <ole/punk.h>

////////////////////////////////////////////////////////////////////////////
// Richeditcrtl
////////////////////////////////////////////////////////////////////////////


template <> 
class mol::uuid_info<IRichEditOleCallback>
{
 public:
   static REFIID uuidof;
   typedef IRichEditOleCallback uuid_type;
};


namespace mol  {


class richedit_init
{
public:
  richedit_init()
  {
    ::LoadLibrary(_T("Riched20.dll"));
  }
};

namespace win  {

class RichEditStreamCallBack
{
public:
    static DWORD CALLBACK inStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb );
    static DWORD CALLBACK outStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb );

    std::string		ioBuf_;
    EDITSTREAM		editstream_;
    long			written_;
};

extern const wchar_t richedit_class[];



class IRichEditOleCallbackImpl : 
	public IRichEditOleCallback ,
	public mol::interfaces< 
			IRichEditOleCallbackImpl,
			mol::implements<IRichEditOleCallback> 
	>
{
	public: 

		IRichEditOleCallbackImpl();

		virtual HRESULT __stdcall GetNewStorage(LPSTORAGE* lplpstg);

		virtual HRESULT __stdcall GetInPlaceContext(LPOLEINPLACEFRAME* lplpFrame, LPOLEINPLACEUIWINDOW* lplpDoc, LPOLEINPLACEFRAMEINFO lpFrameInfo)
		{
			return E_NOTIMPL;
		}

		virtual HRESULT __stdcall ShowContainerUI(BOOL fShow)
		{
			return S_OK;
		}

		virtual HRESULT __stdcall QueryInsertObject(LPCLSID lpclsid, LPSTORAGE lpstg, LONG cp)
		{
			return S_OK;
		}

		virtual HRESULT __stdcall DeleteObject(LPOLEOBJECT lpoleobj)
		{
			return S_OK;
		}

		virtual HRESULT __stdcall QueryAcceptData(LPDATAOBJECT lpdataobj, CLIPFORMAT FAR * lpcfFormat, DWORD reco,BOOL fReally, HGLOBAL hMetaPict)
		{
			return S_OK;
		}

		virtual HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode)
		{
			return S_OK;
		}

		virtual HRESULT __stdcall GetClipboardData(CHARRANGE FAR * lpchrg, DWORD reco,LPDATAOBJECT FAR * lplpdataobj)
		{
			return E_NOTIMPL;
		}

		virtual HRESULT __stdcall GetDragDropEffect(BOOL fDrag, DWORD grfKeyState,LPDWORD pdwEffect)
		{
			return S_OK;
		}

		virtual HRESULT __stdcall GetContextMenu( WORD seltype, LPOLEOBJECT lpoleobj, CHARRANGE* lpchrg, HMENU* lphmenu)
		{
			return E_NOTIMPL;
		}


	private:
		mol::punk<ILockBytes> bytes_;
		mol::punk<IStorage> store_;
		int cnt_;
};

} // end namespace win

class RichEditCtrl : public mol::win::CtrlClass<mol::win::richedit_class>
{
public:
    RichEditCtrl()
    {
		nextSearchPos_=0;
    }

    // styles
    virtual int style()   { return WS_CHILD|WS_VISIBLE|ES_MULTILINE; }

    LRESULT streamIn(  const std::string c, int type = SF_TEXT);
    LRESULT streamOut( std::string&, int type = SF_TEXT);
    LRESULT notify(int id );

    bool search ( const std::string& s , int options = FR_DOWN);
    bool search(int options );

    const std::string& getSearchText() { return searchText_; };

	BOOL PrintRTF();

private:

	mol::win::RichEditStreamCallBack	cb_;

    std::string				searchText_;
    int						nextSearchPos_;
    int						lastSearchDir_;
};


} // endnamespace mol

#endif


