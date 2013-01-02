#pragma once
#include "scieditor.h"

class Style
{
public:
	WPARAM style_;
	bool bold_;
	bool italic_;
	bool eol_;
	const char* font_;
	long size_;
	COLORREF foreColor_;
	COLORREF backColor_;
	const char* description_;


};


#include "ole/Ctrl.h"
#include "ole/Bstr.h"
#include "ole/Persist.h"
#include "ScintillAx_h.h"

class AxStyleSets : 
	public mol::com_registerobj<AxStyleSets,CLSID_ScintillAxStyleSets>,
	public mol::Dispatch<IScintillAxStyleSets>,
	public IPersistStreamInit,
	public mol::interfaces< AxStyleSets, 
				mol::implements< 
					IDispatch, 
					IScintillAxStyleSets,				
					mol::interface_ex<IPersist,IPersistStreamInit>,
					mol::interface_ex<IPersistStream,IPersistStreamInit>,
					IPersistStreamInit> >
{
public:

	typedef mol::com_instance<AxStyleSets> Instance;

	static Instance* CreateInstance();
	virtual void dispose() {};

	virtual HRESULT __stdcall _NewEnum(IEnumVARIANT** newEnum);
	virtual HRESULT __stdcall Item( VARIANT index, IScintillAxStyleSet** item);
	virtual HRESULT __stdcall get_Count( long* cnt);

	virtual HRESULT __stdcall Load( LPSTREAM pStm);
	virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	virtual HRESULT __stdcall GetClassID( CLSID *pClassID) ;
	virtual HRESULT __stdcall IsDirty( );
	virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER* ui ) ;
	virtual HRESULT __stdcall InitNew();

	mol::COMCollection collection_;
};


class AxStyleSet : 
	public mol::Dispatch<IScintillAxStyleSet>,
	public IPersistStreamInit,
	public mol::interfaces< AxStyleSet, 
				mol::implements< 
					IDispatch, 
					IScintillAxStyleSet,				
					mol::interface_ex<IPersist,IPersistStreamInit>,
					mol::interface_ex<IPersistStream,IPersistStreamInit>,
					IPersistStreamInit> >
{
public:

	typedef mol::com_instance<AxStyleSet> Instance;

	static Instance* CreateInstance(long id);
	virtual void dispose() {};

	virtual HRESULT __stdcall _NewEnum(IEnumVARIANT** newEnum);
	virtual HRESULT __stdcall Item( VARIANT index, IScintillAxStyle** item);
	virtual HRESULT __stdcall get_Count( long* cnt);
	virtual HRESULT __stdcall AddKeyWords( BSTR words);
	virtual HRESULT __stdcall CountKeyWords(long* cnt);
	virtual HRESULT __stdcall GetKeyWord(long index, BSTR* words);
    virtual HRESULT __stdcall  get_Id(  long *id); 


	virtual HRESULT __stdcall Load( LPSTREAM pStm);
	virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	virtual HRESULT __stdcall GetClassID( CLSID *pClassID) ;
	virtual HRESULT __stdcall IsDirty( );
	virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER* ui ) ;
	virtual HRESULT __stdcall InitNew();

	mol::COMCollection collection_;
	mol::COMCollection keyWords_;
	long id_;
};


class AxStyle : 
	public mol::Dispatch<IScintillAxStyle>,
	public IPersistStreamInit,
	public mol::interfaces< AxStyle, 
				mol::implements< 
					IDispatch, 
					IScintillAxStyle,				
					mol::interface_ex<IPersist,IPersistStreamInit>,
					mol::interface_ex<IPersistStream,IPersistStreamInit>,
					IPersistStreamInit> >
{
public:

	typedef mol::com_instance<AxStyle> Instance;

	static Instance* CreateInstance();
	virtual void dispose() {};

    virtual HRESULT __stdcall  get_Id(  long *id);        
    virtual HRESULT __stdcall  get_Description(  BSTR *desc);
    virtual HRESULT __stdcall  get_Bold(  VARIANT_BOOL *vb);
    virtual HRESULT __stdcall  put_Bold(  VARIANT_BOOL vb);
    virtual HRESULT __stdcall  get_Italic(  VARIANT_BOOL *vb);
    virtual HRESULT __stdcall  put_Italic(  VARIANT_BOOL vb);
    virtual HRESULT __stdcall  get_Eol(  VARIANT_BOOL *vb);       
    virtual HRESULT __stdcall  put_Eol(  VARIANT_BOOL vb);      
    virtual HRESULT __stdcall  get_Fontname(  BSTR *desc);      
    virtual HRESULT __stdcall  put_Fontname(  BSTR desc);     
    virtual HRESULT __stdcall  get_Fontsize( long *id);     
    virtual HRESULT __stdcall  put_Fontsize( long id);     
    virtual HRESULT __stdcall  get_Forecolor( BSTR *col);    
    virtual HRESULT __stdcall  put_Forecolor( BSTR col);     
    virtual HRESULT __stdcall  get_Backcolor( BSTR *col);     
    virtual HRESULT __stdcall  put_Backcolor(BSTR col);   

	virtual HRESULT __stdcall Load( LPSTREAM pStm);
	virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	virtual HRESULT __stdcall GetClassID( CLSID *pClassID) ;
	virtual HRESULT __stdcall IsDirty( );
	virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER* ui ) ;
	virtual HRESULT __stdcall InitNew();


	long id_;
	mol::bstr desc_;
	VARIANT_BOOL bold_;
	VARIANT_BOOL italic_;
	VARIANT_BOOL eol_;
	mol::bstr fontname_;
	long fontsize_;
	mol::bstr foreColor_;
	mol::bstr backColor_;
};


