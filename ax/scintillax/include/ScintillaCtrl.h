#ifndef MOL_DEF_SCINTILLAX_VIEW_DEF_GUARDING_
#define MOL_DEF_SCINTILLAX_VIEW_DEF_GUARDING_

#pragma once
#include "util/uni.h"
#include "win/enc.h"
#include "scieditor.h"
#include "win/MsgMap.h"
#include "ole/Ctrl.h"
#include "ole/Bstr.h"
#include "ole/Persist.h"
#include "ScintillAx_h.h"
#include "ShellCtrl/ShellCtrl_h.h"
#include "include/resource.h"
#include "include/xmlui.h"


class SciAxProperties;

///////////////////////////////////////////////////////////////////////////////////
// Scintilla as AX Control impl
///////////////////////////////////////////////////////////////////////////////////

// font helper class
class FontDesc
{
public:
	FontDesc();
	FontDesc(const std::string& font, int size);
	FontDesc(HFONT hfont);
	const char* name();
	const char* size();
	const char* weight();
	const char* style();
    const char* decoration();

	LOGFONTA* desc()
	{
		return &m_logfont;
	}
private:
	LOGFONTA	m_logfont;
};

///////////////////////////////////////////////////////////////////////////////
// embedded scintilla editor window
///////////////////////////////////////////////////////////////////////////////

class EditWnd
	: public mol::Control< ScintillaEditor, 
						   WS_CHILD|WS_CLIPSIBLINGS|
                           WS_CLIPCHILDREN,
                           WS_EX_STATICEDGE>
{};


///////////////////////////////////////////////////////////////////////////////
// the scintilla active X control
///////////////////////////////////////////////////////////////////////////////

class ScintillAx: 
	public mol::ax_ctrl<ScintillAx,CLSID_ScintillAx,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,0>,
	public mol::Dispatch<IScintillAx>,
	public mol::ctrl_events<ScintillAx,_IScintillAxEvents>,
	public mol::ProvideClassInfo<ScintillAx>,
	public mol::interfaces< ScintillAx,
			mol::implements<
					IDispatch,
					IScintillAx,
					IOleObject,
					IDataObject,
					mol::interface_ex<IPersist,IPersistStreamInit>,
					mol::interface_ex<IPersistStream,IPersistStreamInit>,
					IPersistStreamInit,
					IPersistStorage,
					IPersistPropertyBag,
					IRunnableObject,
					IViewObject,
					IViewObject2,
					mol::interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
					mol::interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
					IOleControl,
					IConnectionPointContainer,
					IProvideClassInfo,
					ISpecifyPropertyPages>
				>
{
public:

    ScintillAx(void);
    ~ScintillAx();

	virtual void dispose();


	//properties:

		HRESULT virtual __stdcall get_Text( IScintillAxText** txt );
		HRESULT virtual __stdcall get_Properties( IScintillAxProperties** props );
		HRESULT virtual __stdcall get_Position( IScintillAxPosition** pos );
		HRESULT virtual __stdcall get_Selection( IScintillAxSelection** sel );
		HRESULT virtual __stdcall get_Line( IScintillAxLine** line );
		HRESULT virtual __stdcall get_Annotation( IScintillAxAnnotation** anno );
		HRESULT virtual __stdcall get_Markers( IScintillAxMarkers** markers );

	//methods:

		// Load / Save

		HRESULT virtual __stdcall Load( BSTR file );
		HRESULT virtual __stdcall LoadEncoding( BSTR file, long enc );
		HRESULT virtual __stdcall LoadAsync( BSTR file, long enc );
		HRESULT virtual __stdcall Save();
		HRESULT virtual __stdcall SaveAs( BSTR filename );

		// undo / redo
		HRESULT virtual __stdcall Undo();
		HRESULT virtual __stdcall Redo();
		HRESULT virtual __stdcall SavePoint();

		// Options
		HRESULT virtual __stdcall SetFocus();
		HRESULT virtual __stdcall ZoomIn( );
		HRESULT virtual __stdcall ZoomOut( );
		HRESULT virtual __stdcall InsertColorDialog(  );
		HRESULT virtual __stdcall ShowProperties();

		// print
		HRESULT virtual __stdcall Print();
		HRESULT virtual __stdcall GetPages( CAUUID *pPages);
  
		// persistence
	    HRESULT virtual __stdcall InitNew();

		HRESULT virtual __stdcall Load( LPSTREAM pStm);
		HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

		HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
		HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);

		HRESULT virtual __stdcall Apply(IScintillAxStyleSet * style);

		// window messages

		LRESULT virtual OnCreate(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnUpdateUI (  UINT, WPARAM, LPARAM );
		LRESULT virtual OnDblClick(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnMarginClick(  UINT, WPARAM, LPARAM );
        LRESULT virtual OnChar( UINT, WPARAM, LPARAM );
		LRESULT virtual OnContext( UINT, WPARAM, LPARAM );

		// ctrl drawing
		HRESULT OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds);


		EditWnd* edit();

		void OnAsyncLoad(const std::string& s);
protected:



	mol::punk<IColorPicker>	col_;

	mol::punk<IScintillAxProperties>	props_;
	mol::punk<IScintillAxText>			text_;
	mol::punk<IScintillAxPosition>		pos_;
	mol::punk<IScintillAxSelection>		selection_;
	mol::punk<IScintillAxLine>			line_;
	mol::punk<IScintillAxAnnotation>	annotation_;
	mol::punk<IScintillAxMarkers>		markers_;

	void Init();
	void disposeObject(IUnknown* unk);

	//bool loadAdminCOM(const std::wstring& p, const std::wstring& ext,  long enc);
	//bool saveAdminCOM(const std::wstring& p);
	std::string loadAdmin(const std::wstring& p);
	bool saveAdmin(const std::wstring& p);
	bool load(const std::wstring& p, const std::wstring& ext,  long enc);
	bool openSSH(const std::wstring& path,const std::wstring& ext,long enc);
	bool save(const std::wstring& location);
	bool saveSSH(const std::wstring& location);
};

///////////////////////////////////////////////////////////////////////////////

					


///////////////////////////////////////////////////////////////////////////////



#endif