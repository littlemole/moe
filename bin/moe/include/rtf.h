#ifndef MOE_RTF_DEF_GUARD_
#define MOE_RTF_DEF_GUARD_

#include "shared.h"
#include "win/RTFedit.h"


using namespace mol;

//////////////////////////////////////////////////////////////////////////////////
// RTF editor
//////////////////////////////////////////////////////////////////////////////////

class RTFEditor 
	: public MoeChild<
				RTFEditor,
				mol::MdiChild,
				MOE_DOCTYPE_RTF,
				IDM_MOE_RTF
			>
{
public:

	RTFEditor();
	virtual ~RTFEditor();

	static Instance* CreateInstance( const mol::string& p );

	void OnMDIActivate(WPARAM unused, HWND activated);
	void OnCreate();
	void OnPaint();

	LRESULT OnClose();
	LRESULT OnDestroy();
	LRESULT OnNcDestroy();
	LRESULT OnSize(UINT msg, WPARAM wParam, LPARAM lParam);

	void OnSave();
	void OnSaveAs();

	void OnCut();
	void OnCopy();
	void OnPaste();

	void OnUndo();
	void OnRedo();
	void OnReload();

	void OnFont();
	void OnPrint();

	void OnSelectionChange(SELCHANGE * selc);
	void OnLink(ENLINK *);
	void OnFilter(MSGFILTER* filter);

	void OnSelectAll();
	void OnInsertColorDialog();
	void OnSearch( FINDREPLACE* find );
	/////////////////////////////////////////////////////////////////////

   virtual HRESULT __stdcall get_Object( IDispatch **d);

	punk<IUnknown> oleObject;
	punk<IRichEditOle> richEditOle;

private:

	class RichEditOleCallback : public mol::win::IRichEditOleCallbackImpl
	{
		public:  outer_this(RTFEditor,reolecb_); 

		virtual HRESULT __stdcall QueryAcceptData(LPDATAOBJECT lpdataobj, CLIPFORMAT FAR * lpcfFormat, DWORD reco,BOOL fReally, HGLOBAL hMetaPict);
		virtual HRESULT __stdcall GetInPlaceContext(LPOLEINPLACEFRAME* lplpFrame, LPOLEINPLACEUIWINDOW* lplpDoc, LPOLEINPLACEFRAMEINFO lpFrameInfo);
		virtual HRESULT __stdcall ShowContainerUI(BOOL fShow);
	};

	mol::stack_obj<RichEditOleCallback> reolecb_;

	mol::string filename_;


	class RTF : public mol::RichEditCtrl
	{
		public:
			virtual int style()   { return WS_CHILD|WS_VISIBLE|ES_MULTILINE|WS_VSCROLL|WS_HSCROLL|ES_NOHIDESEL; }

	} rtf_;

	class RTFDocument : 
		public mol::Dispatch<IMoeRichText>,
		public mol::ProvideClassInfo<RTFDocument>,
		public mol::interfaces<RTFDocument,mol::implements<IDispatch,IMoeRichText,IProvideClassInfo> >
	{
		public: outer_this(RTFEditor,rtfDocument_); 

			HRESULT virtual __stdcall get_Text( IDispatch** d);
			HRESULT virtual __stdcall get_Length( long* d);
			HRESULT virtual __stdcall Range( long start, long end,  IDispatch** d);
			HRESULT virtual __stdcall get_Selection( IDispatch** d);

			static REFGUID getCoClassID()
			{
				return IID_IMoeRichText;
			}

		private:
	};

	mol::stack_obj<RTFDocument> rtfDocument_;

	bool load(const mol::string& path);

	FINDTEXT findText_;

	bool shuttingDown_;	

};

#endif