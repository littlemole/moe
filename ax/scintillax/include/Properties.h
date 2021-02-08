#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_PROPS_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_PROPS_DEF_GUARD_

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

class ScintillAx;

class SciAxProperties : 
	public mol::Dispatch<IScintillAxProperties>,
	public mol::ProvideClassInfo<SciAxProperties>,
	public IScintillAxDispose,
	public IPersistStreamInit,
	public mol::interfaces< SciAxProperties, 
			mol::implements< 
				IDispatch, 
				IScintillAxProperties, 
				IScintillAxDispose,
				mol::interface_ex<IPersist,IPersistStreamInit>,
				mol::interface_ex<IPersistStream,IPersistStreamInit>,
				IPersistStreamInit,
				IProvideClassInfo> >
{
public:

	SciAxProperties();
	virtual ~SciAxProperties();

	typedef mol::com_obj<SciAxProperties> Instance;

	static Instance* CreateInstance( ScintillAx* sci);

	virtual void dispose();

	static REFGUID getCoClassID();
	
    virtual  HRESULT __stdcall put_Filename( BSTR fname);      
    virtual  HRESULT __stdcall get_Filename( BSTR *fname);    

    virtual  HRESULT __stdcall put_ReadOnly( VARIANT_BOOL vbReadOnly);       
    virtual  HRESULT __stdcall get_ReadOnly( VARIANT_BOOL *vbReadOnly);   

    virtual  HRESULT __stdcall put_Syntax( long typ);
    virtual  HRESULT __stdcall get_Syntax( long *typ);

    virtual  HRESULT __stdcall put_SysType( long typ);
    virtual  HRESULT __stdcall get_SysType( long *typ);

    virtual  HRESULT __stdcall put_Encoding( long typ);
    virtual  HRESULT __stdcall get_Encoding( long *typ);

    virtual  HRESULT __stdcall put_TabUsage( VARIANT_BOOL vbTabUsage);
    virtual  HRESULT __stdcall get_TabUsage( VARIANT_BOOL *vbTabUsage);

    virtual  HRESULT __stdcall put_TabIndents( VARIANT_BOOL vbTabIndents);
    virtual  HRESULT __stdcall get_TabIndents( VARIANT_BOOL *vbTabIndents);

    virtual  HRESULT __stdcall put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceIndents);
    virtual  HRESULT __stdcall get_BackSpaceUnindents( VARIANT_BOOL *vbBackSpaceIndents);

    virtual  HRESULT __stdcall put_TabWidth( long width);
    virtual  HRESULT __stdcall get_TabWidth( long *w);

    virtual  HRESULT __stdcall put_Overtype( VARIANT_BOOL over_type);
    virtual  HRESULT __stdcall get_Overtype( VARIANT_BOOL *over_type);

    virtual  HRESULT __stdcall put_UseContext( VARIANT_BOOL useMenu);     
    virtual  HRESULT __stdcall get_UseContext( VARIANT_BOOL *useMenu);   

    virtual  HRESULT __stdcall put_WriteBOM( VARIANT_BOOL vb);       
    virtual  HRESULT __stdcall get_WriteBOM( VARIANT_BOOL *vb);

    virtual  HRESULT __stdcall put_ShowLineNumbers( VARIANT_BOOL useLineNums);
	virtual  HRESULT __stdcall get_ShowLineNumbers( VARIANT_BOOL *useLineNums);

    virtual  HRESULT __stdcall SyntaxDisplayName( BSTR *syntax);
    virtual  HRESULT __stdcall GetSyntaxDisplayName(  long type, BSTR *syntax);

    virtual  HRESULT __stdcall SetIndent( long i);
    virtual  HRESULT __stdcall ConvertTabs( void);

	HRESULT virtual __stdcall Load( LPSTREAM pStm);
	HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	HRESULT virtual __stdcall GetClassID( CLSID *pClassID) ;
	HRESULT virtual __stdcall IsDirty( );
	HRESULT virtual __stdcall GetSizeMax( ULARGE_INTEGER* ui ) ;
	HRESULT virtual __stdcall InitNew();

	HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
	HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);

	HRESULT virtual __stdcall Dispose();

	HRESULT virtual __stdcall put_StyleSets( IScintillAxStyleSets* styles);
	HRESULT virtual __stdcall get_StyleSets( IScintillAxStyleSets** styles);


private:

	mol::bstr				filename_;	
	VARIANT_BOOL			vbContext_;
	VARIANT_BOOL			vbWriteBOM_;
	VARIANT_BOOL			vbReadOnly_;

	VARIANT_BOOL			vbTabUsage_;
	VARIANT_BOOL			vbTabIndents_;
	VARIANT_BOOL			vbBackSpaceUnindents_;
	long					tabWidth_;

	VARIANT_BOOL			vbOverType_;

	SCINTILLA_SYSTYPE		eol_;
	long					enc_;
	SCINTILLA_SYNTAX        syntax_;

	mol::punk<IScintillAxStyleSets> styleSets_;
	ScintillAx* sci_;
};


#endif