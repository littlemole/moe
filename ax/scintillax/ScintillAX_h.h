

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon May 24 13:50:40 2010
 */
/* Compiler settings for .\ScintillAX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __ScintillAX_h_h__
#define __ScintillAX_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IScintillAx_FWD_DEFINED__
#define __IScintillAx_FWD_DEFINED__
typedef interface IScintillAx IScintillAx;
#endif 	/* __IScintillAx_FWD_DEFINED__ */


#ifndef ___IScintillAxEvents_FWD_DEFINED__
#define ___IScintillAxEvents_FWD_DEFINED__
typedef interface _IScintillAxEvents _IScintillAxEvents;
#endif 	/* ___IScintillAxEvents_FWD_DEFINED__ */


#ifndef __IScintillAxEvents_FWD_DEFINED__
#define __IScintillAxEvents_FWD_DEFINED__
typedef interface IScintillAxEvents IScintillAxEvents;
#endif 	/* __IScintillAxEvents_FWD_DEFINED__ */


#ifndef __ScintillAx_FWD_DEFINED__
#define __ScintillAx_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScintillAx ScintillAx;
#else
typedef struct ScintillAx ScintillAx;
#endif /* __cplusplus */

#endif 	/* __ScintillAx_FWD_DEFINED__ */


#ifndef __ScintillAxProperties_FWD_DEFINED__
#define __ScintillAxProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScintillAxProperties ScintillAxProperties;
#else
typedef struct ScintillAxProperties ScintillAxProperties;
#endif /* __cplusplus */

#endif 	/* __ScintillAxProperties_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __Scintilla_LIBRARY_DEFINED__
#define __Scintilla_LIBRARY_DEFINED__

/* library Scintilla */
/* [helpstring][version][uuid] */ 


enum SCINTILLA_SYSTYPE
    {	SCINTILLA_SYSTYPE_UNIX	= 0,
	SCINTILLA_SYSTYPE_WIN32	= 1
    } ;

enum SCINTILLA_ENCODING
    {	SCINTILLA_ENCODING_ANSI	= 0,
	SCINTILLA_ENCODING_UTF8	= 1,
	SCINTILLA_ENCODING_UTF16	= 2
    } ;

enum SCINTILLA_SYNTAX
    {	SCINTILLA_SYNTAX_PLAIN	= 0,
	SCINTILLA_SYNTAX_HTML	= 1,
	SCINTILLA_SYNTAX_CSS	= 2,
	SCINTILLA_SYNTAX_VB	= 3,
	SCINTILLA_SYNTAX_JS	= 4,
	SCINTILLA_SYNTAX_SQL	= 5,
	SCINTILLA_SYNTAX_SHELL	= 6,
	SCINTILLA_SYNTAX_PERL	= 7,
	SCINTILLA_SYNTAX_CPP	= 8,
	SCINTILLA_SYNTAX_JAVA	= 9,
	SCINTILLA_SYNTAX_CSHARP	= 10
    } ;

EXTERN_C const IID LIBID_Scintilla;

#ifndef __IScintillAx_INTERFACE_DEFINED__
#define __IScintillAx_INTERFACE_DEFINED__

/* interface IScintillAx */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1120EC6A-130F-440e-9B1D-F02D505FB5BC")
    IScintillAx : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *fnt) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *fnt) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **fnt) = 0;
        
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Filename( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *fname) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnly( 
            /* [in] */ VARIANT_BOOL vbReadOnly) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *vbReadOnly) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Syntax( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Syntax( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_SysType( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_SysType( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Encoding( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Encoding( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabUsage( 
            /* [in] */ VARIANT_BOOL vbTabUsage) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabUsage( 
            /* [retval][out] */ VARIANT_BOOL *vbTabUsage) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabIndents( 
            /* [in] */ VARIANT_BOOL vbTabIndents) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabIndents( 
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BackSpaceUnindents( 
            /* [in] */ VARIANT_BOOL vbBackSpaceIndents) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BackSpaceUnindents( 
            /* [retval][out] */ VARIANT_BOOL *vbBackSpaceIndents) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabWidth( 
            /* [in] */ long width) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabWidth( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Overtype( 
            /* [in] */ VARIANT_BOOL over_type) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Overtype( 
            /* [retval][out] */ VARIANT_BOOL *over_type) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_UseContext( 
            /* [in] */ VARIANT_BOOL useMenu) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_UseContext( 
            /* [retval][out] */ VARIANT_BOOL *useMenu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadUTF8( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetText( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetText( 
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TextLength( 
            /* [retval][out] */ long *len) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ BSTR txt,
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Modified( 
            /* [retval][out] */ VARIANT_BOOL *vbModified) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaretPos( 
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCaretPos( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CharAt( 
            /* [in] */ long p,
            /* [retval][out] */ BSTR *ch) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scroll( 
            /* [in] */ long cCols,
            /* [in] */ long cLines) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ScrollIntoView( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSearchPos( 
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSearchPos( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAnchorPos( 
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAnchorPos( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineCount( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CurrentLine( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineFromPos( 
            /* [in] */ long p,
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PosFromLine( 
            /* [in] */ long l,
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineEndPos( 
            /* [in] */ long l,
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FirstVisibleLine( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LinesOnScreen( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineLength( 
            /* [in] */ long l,
            /* [retval][out] */ long *len) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineText( 
            /* [in] */ long l,
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLineText( 
            /* [in] */ long l,
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GotoLine( 
            /* [in] */ long l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelection( 
            /* [out] */ long *pFirst,
            /* [out] */ long *pLast) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSelection( 
            /* [in] */ long pFirst,
            /* [in] */ long pLast) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelectionText( 
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSelectionStart( 
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelectionStart( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSelectionEnd( 
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelectionEnd( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReplaceSelection( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Search( 
            /* [in] */ BSTR sWhat,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbFound) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Replace( 
            /* [in] */ BSTR sWhat,
            /* [in] */ BSTR w,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbReplaced) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Undo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Redo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SavePoint( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFocus( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomIn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomOut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIndent( 
            /* [in] */ long i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertTabs( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTextRange( 
            /* [in] */ long pStart,
            /* [in] */ long pEnd,
            /* [retval][out] */ BSTR *rng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Properties( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SyntaxDisplayName( 
            /* [retval][out] */ BSTR *syntax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSyntaxDisplayName( 
            /* [in] */ long type,
            /* [retval][out] */ BSTR *syntax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertColorDialog( 
            HWND wnd) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_WriteBOM( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_WriteBOM( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][bindable][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            IScintillAx * This,
            /* [in] */ IFontDisp *fnt);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IScintillAx * This,
            /* [in] */ IFontDisp *fnt);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IScintillAx * This,
            /* [retval][out] */ IFontDisp **fnt);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Filename )( 
            IScintillAx * This,
            /* [in] */ BSTR fname);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IScintillAx * This,
            /* [retval][out] */ BSTR *fname);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnly )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL vbReadOnly);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *vbReadOnly);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Syntax )( 
            IScintillAx * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Syntax )( 
            IScintillAx * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SysType )( 
            IScintillAx * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SysType )( 
            IScintillAx * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Encoding )( 
            IScintillAx * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Encoding )( 
            IScintillAx * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabUsage )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL vbTabUsage);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabUsage )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabUsage);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabIndents )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL vbTabIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabIndents )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackSpaceUnindents )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL vbBackSpaceIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackSpaceUnindents )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *vbBackSpaceIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabWidth )( 
            IScintillAx * This,
            /* [in] */ long width);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabWidth )( 
            IScintillAx * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Overtype )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL over_type);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Overtype )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *over_type);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseContext )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL useMenu);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseContext )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *useMenu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IScintillAx * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadUTF8 )( 
            IScintillAx * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IScintillAx * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetText )( 
            IScintillAx * This,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetText )( 
            IScintillAx * This,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TextLength )( 
            IScintillAx * This,
            /* [retval][out] */ long *len);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            IScintillAx * This,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IScintillAx * This,
            /* [in] */ BSTR txt,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Modified )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *vbModified);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCaretPos )( 
            IScintillAx * This,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCaretPos )( 
            IScintillAx * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CharAt )( 
            IScintillAx * This,
            /* [in] */ long p,
            /* [retval][out] */ BSTR *ch);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            IScintillAx * This,
            /* [in] */ long cCols,
            /* [in] */ long cLines);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScrollIntoView )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSearchPos )( 
            IScintillAx * This,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSearchPos )( 
            IScintillAx * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAnchorPos )( 
            IScintillAx * This,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAnchorPos )( 
            IScintillAx * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineCount )( 
            IScintillAx * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CurrentLine )( 
            IScintillAx * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineFromPos )( 
            IScintillAx * This,
            /* [in] */ long p,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PosFromLine )( 
            IScintillAx * This,
            /* [in] */ long l,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineEndPos )( 
            IScintillAx * This,
            /* [in] */ long l,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FirstVisibleLine )( 
            IScintillAx * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LinesOnScreen )( 
            IScintillAx * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineLength )( 
            IScintillAx * This,
            /* [in] */ long l,
            /* [retval][out] */ long *len);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineText )( 
            IScintillAx * This,
            /* [in] */ long l,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLineText )( 
            IScintillAx * This,
            /* [in] */ long l,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GotoLine )( 
            IScintillAx * This,
            /* [in] */ long l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelection )( 
            IScintillAx * This,
            /* [out] */ long *pFirst,
            /* [out] */ long *pLast);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelection )( 
            IScintillAx * This,
            /* [in] */ long pFirst,
            /* [in] */ long pLast);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelectionText )( 
            IScintillAx * This,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelectionStart )( 
            IScintillAx * This,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelectionStart )( 
            IScintillAx * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelectionEnd )( 
            IScintillAx * This,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelectionEnd )( 
            IScintillAx * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReplaceSelection )( 
            IScintillAx * This,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Search )( 
            IScintillAx * This,
            /* [in] */ BSTR sWhat,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbFound);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Replace )( 
            IScintillAx * This,
            /* [in] */ BSTR sWhat,
            /* [in] */ BSTR w,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbReplaced);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Undo )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Redo )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SavePoint )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFocus )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomIn )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomOut )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIndent )( 
            IScintillAx * This,
            /* [in] */ long i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertTabs )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTextRange )( 
            IScintillAx * This,
            /* [in] */ long pStart,
            /* [in] */ long pEnd,
            /* [retval][out] */ BSTR *rng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SyntaxDisplayName )( 
            IScintillAx * This,
            /* [retval][out] */ BSTR *syntax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSyntaxDisplayName )( 
            IScintillAx * This,
            /* [in] */ long type,
            /* [retval][out] */ BSTR *syntax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertColorDialog )( 
            IScintillAx * This,
            HWND wnd);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WriteBOM )( 
            IScintillAx * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WriteBOM )( 
            IScintillAx * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        END_INTERFACE
    } IScintillAxVtbl;

    interface IScintillAx
    {
        CONST_VTBL struct IScintillAxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAx_putref_Font(This,fnt)	\
    ( (This)->lpVtbl -> putref_Font(This,fnt) ) 

#define IScintillAx_put_Font(This,fnt)	\
    ( (This)->lpVtbl -> put_Font(This,fnt) ) 

#define IScintillAx_get_Font(This,fnt)	\
    ( (This)->lpVtbl -> get_Font(This,fnt) ) 

#define IScintillAx_put_Filename(This,fname)	\
    ( (This)->lpVtbl -> put_Filename(This,fname) ) 

#define IScintillAx_get_Filename(This,fname)	\
    ( (This)->lpVtbl -> get_Filename(This,fname) ) 

#define IScintillAx_put_ReadOnly(This,vbReadOnly)	\
    ( (This)->lpVtbl -> put_ReadOnly(This,vbReadOnly) ) 

#define IScintillAx_get_ReadOnly(This,vbReadOnly)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,vbReadOnly) ) 

#define IScintillAx_put_Syntax(This,typ)	\
    ( (This)->lpVtbl -> put_Syntax(This,typ) ) 

#define IScintillAx_get_Syntax(This,typ)	\
    ( (This)->lpVtbl -> get_Syntax(This,typ) ) 

#define IScintillAx_put_SysType(This,typ)	\
    ( (This)->lpVtbl -> put_SysType(This,typ) ) 

#define IScintillAx_get_SysType(This,typ)	\
    ( (This)->lpVtbl -> get_SysType(This,typ) ) 

#define IScintillAx_put_Encoding(This,typ)	\
    ( (This)->lpVtbl -> put_Encoding(This,typ) ) 

#define IScintillAx_get_Encoding(This,typ)	\
    ( (This)->lpVtbl -> get_Encoding(This,typ) ) 

#define IScintillAx_put_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> put_TabUsage(This,vbTabUsage) ) 

#define IScintillAx_get_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> get_TabUsage(This,vbTabUsage) ) 

#define IScintillAx_put_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> put_TabIndents(This,vbTabIndents) ) 

#define IScintillAx_get_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> get_TabIndents(This,vbTabIndents) ) 

#define IScintillAx_put_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> put_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IScintillAx_get_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> get_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IScintillAx_put_TabWidth(This,width)	\
    ( (This)->lpVtbl -> put_TabWidth(This,width) ) 

#define IScintillAx_get_TabWidth(This,w)	\
    ( (This)->lpVtbl -> get_TabWidth(This,w) ) 

#define IScintillAx_put_Overtype(This,over_type)	\
    ( (This)->lpVtbl -> put_Overtype(This,over_type) ) 

#define IScintillAx_get_Overtype(This,over_type)	\
    ( (This)->lpVtbl -> get_Overtype(This,over_type) ) 

#define IScintillAx_put_UseContext(This,useMenu)	\
    ( (This)->lpVtbl -> put_UseContext(This,useMenu) ) 

#define IScintillAx_get_UseContext(This,useMenu)	\
    ( (This)->lpVtbl -> get_UseContext(This,useMenu) ) 

#define IScintillAx_Load(This,fname)	\
    ( (This)->lpVtbl -> Load(This,fname) ) 

#define IScintillAx_LoadUTF8(This,fname)	\
    ( (This)->lpVtbl -> LoadUTF8(This,fname) ) 

#define IScintillAx_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IScintillAx_SaveAs(This,fname)	\
    ( (This)->lpVtbl -> SaveAs(This,fname) ) 

#define IScintillAx_SetText(This,txt)	\
    ( (This)->lpVtbl -> SetText(This,txt) ) 

#define IScintillAx_GetText(This,txt)	\
    ( (This)->lpVtbl -> GetText(This,txt) ) 

#define IScintillAx_TextLength(This,len)	\
    ( (This)->lpVtbl -> TextLength(This,len) ) 

#define IScintillAx_Append(This,txt)	\
    ( (This)->lpVtbl -> Append(This,txt) ) 

#define IScintillAx_Insert(This,txt,p)	\
    ( (This)->lpVtbl -> Insert(This,txt,p) ) 

#define IScintillAx_Modified(This,vbModified)	\
    ( (This)->lpVtbl -> Modified(This,vbModified) ) 

#define IScintillAx_SetCaretPos(This,p)	\
    ( (This)->lpVtbl -> SetCaretPos(This,p) ) 

#define IScintillAx_GetCaretPos(This,p)	\
    ( (This)->lpVtbl -> GetCaretPos(This,p) ) 

#define IScintillAx_CharAt(This,p,ch)	\
    ( (This)->lpVtbl -> CharAt(This,p,ch) ) 

#define IScintillAx_Scroll(This,cCols,cLines)	\
    ( (This)->lpVtbl -> Scroll(This,cCols,cLines) ) 

#define IScintillAx_ScrollIntoView(This)	\
    ( (This)->lpVtbl -> ScrollIntoView(This) ) 

#define IScintillAx_SetSearchPos(This,p)	\
    ( (This)->lpVtbl -> SetSearchPos(This,p) ) 

#define IScintillAx_GetSearchPos(This,p)	\
    ( (This)->lpVtbl -> GetSearchPos(This,p) ) 

#define IScintillAx_SetAnchorPos(This,p)	\
    ( (This)->lpVtbl -> SetAnchorPos(This,p) ) 

#define IScintillAx_GetAnchorPos(This,p)	\
    ( (This)->lpVtbl -> GetAnchorPos(This,p) ) 

#define IScintillAx_LineCount(This,cnt)	\
    ( (This)->lpVtbl -> LineCount(This,cnt) ) 

#define IScintillAx_CurrentLine(This,l)	\
    ( (This)->lpVtbl -> CurrentLine(This,l) ) 

#define IScintillAx_LineFromPos(This,p,l)	\
    ( (This)->lpVtbl -> LineFromPos(This,p,l) ) 

#define IScintillAx_PosFromLine(This,l,p)	\
    ( (This)->lpVtbl -> PosFromLine(This,l,p) ) 

#define IScintillAx_LineEndPos(This,l,p)	\
    ( (This)->lpVtbl -> LineEndPos(This,l,p) ) 

#define IScintillAx_FirstVisibleLine(This,l)	\
    ( (This)->lpVtbl -> FirstVisibleLine(This,l) ) 

#define IScintillAx_LinesOnScreen(This,cnt)	\
    ( (This)->lpVtbl -> LinesOnScreen(This,cnt) ) 

#define IScintillAx_LineLength(This,l,len)	\
    ( (This)->lpVtbl -> LineLength(This,l,len) ) 

#define IScintillAx_LineText(This,l,txt)	\
    ( (This)->lpVtbl -> LineText(This,l,txt) ) 

#define IScintillAx_SetLineText(This,l,txt)	\
    ( (This)->lpVtbl -> SetLineText(This,l,txt) ) 

#define IScintillAx_GotoLine(This,l)	\
    ( (This)->lpVtbl -> GotoLine(This,l) ) 

#define IScintillAx_GetSelection(This,pFirst,pLast)	\
    ( (This)->lpVtbl -> GetSelection(This,pFirst,pLast) ) 

#define IScintillAx_SetSelection(This,pFirst,pLast)	\
    ( (This)->lpVtbl -> SetSelection(This,pFirst,pLast) ) 

#define IScintillAx_GetSelectionText(This,txt)	\
    ( (This)->lpVtbl -> GetSelectionText(This,txt) ) 

#define IScintillAx_SetSelectionStart(This,p)	\
    ( (This)->lpVtbl -> SetSelectionStart(This,p) ) 

#define IScintillAx_GetSelectionStart(This,p)	\
    ( (This)->lpVtbl -> GetSelectionStart(This,p) ) 

#define IScintillAx_SetSelectionEnd(This,p)	\
    ( (This)->lpVtbl -> SetSelectionEnd(This,p) ) 

#define IScintillAx_GetSelectionEnd(This,p)	\
    ( (This)->lpVtbl -> GetSelectionEnd(This,p) ) 

#define IScintillAx_ReplaceSelection(This,txt)	\
    ( (This)->lpVtbl -> ReplaceSelection(This,txt) ) 

#define IScintillAx_Search(This,sWhat,lFlags,vbFound)	\
    ( (This)->lpVtbl -> Search(This,sWhat,lFlags,vbFound) ) 

#define IScintillAx_Replace(This,sWhat,w,lFlags,vbReplaced)	\
    ( (This)->lpVtbl -> Replace(This,sWhat,w,lFlags,vbReplaced) ) 

#define IScintillAx_Undo(This)	\
    ( (This)->lpVtbl -> Undo(This) ) 

#define IScintillAx_Redo(This)	\
    ( (This)->lpVtbl -> Redo(This) ) 

#define IScintillAx_SavePoint(This)	\
    ( (This)->lpVtbl -> SavePoint(This) ) 

#define IScintillAx_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define IScintillAx_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define IScintillAx_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#define IScintillAx_SetFocus(This)	\
    ( (This)->lpVtbl -> SetFocus(This) ) 

#define IScintillAx_ZoomIn(This)	\
    ( (This)->lpVtbl -> ZoomIn(This) ) 

#define IScintillAx_ZoomOut(This)	\
    ( (This)->lpVtbl -> ZoomOut(This) ) 

#define IScintillAx_SetIndent(This,i)	\
    ( (This)->lpVtbl -> SetIndent(This,i) ) 

#define IScintillAx_ConvertTabs(This)	\
    ( (This)->lpVtbl -> ConvertTabs(This) ) 

#define IScintillAx_Print(This)	\
    ( (This)->lpVtbl -> Print(This) ) 

#define IScintillAx_GetTextRange(This,pStart,pEnd,rng)	\
    ( (This)->lpVtbl -> GetTextRange(This,pStart,pEnd,rng) ) 

#define IScintillAx_Properties(This)	\
    ( (This)->lpVtbl -> Properties(This) ) 

#define IScintillAx_SyntaxDisplayName(This,syntax)	\
    ( (This)->lpVtbl -> SyntaxDisplayName(This,syntax) ) 

#define IScintillAx_GetSyntaxDisplayName(This,type,syntax)	\
    ( (This)->lpVtbl -> GetSyntaxDisplayName(This,type,syntax) ) 

#define IScintillAx_InsertColorDialog(This,wnd)	\
    ( (This)->lpVtbl -> InsertColorDialog(This,wnd) ) 

#define IScintillAx_put_WriteBOM(This,vb)	\
    ( (This)->lpVtbl -> put_WriteBOM(This,vb) ) 

#define IScintillAx_get_WriteBOM(This,vb)	\
    ( (This)->lpVtbl -> get_WriteBOM(This,vb) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAx_INTERFACE_DEFINED__ */


#ifndef ___IScintillAxEvents_DISPINTERFACE_DEFINED__
#define ___IScintillAxEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IScintillAxEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IScintillAxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2D33B016-176A-40fe-B665-B114A6511AC8")
    _IScintillAxEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IScintillAxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IScintillAxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IScintillAxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IScintillAxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IScintillAxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IScintillAxEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IScintillAxEventsVtbl;

    interface _IScintillAxEvents
    {
        CONST_VTBL struct _IScintillAxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IScintillAxEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IScintillAxEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IScintillAxEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IScintillAxEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IScintillAxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IScintillAxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IScintillAxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IScintillAxEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IScintillAxEvents_INTERFACE_DEFINED__
#define __IScintillAxEvents_INTERFACE_DEFINED__

/* interface IScintillAxEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3766918-A0A4-48b7-942A-BA4B4D524CD0")
    IScintillAxEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnFileNameChanged( 
            /* [in] */ BSTR fname,
            /* [in] */ BSTR fPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnShowMenu( 
            /* [out] */ VARIANT_BOOL *vbShowMenue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPosChange( 
            /* [in] */ long iLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnChar( 
            /* [in] */ BSTR ch) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSyntax( 
            /* [in] */ long s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSystem( 
            /* [in] */ long s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEncoding( 
            /* [in] */ long e) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnFileNameChanged )( 
            IScintillAxEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ BSTR fPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnShowMenu )( 
            IScintillAxEvents * This,
            /* [out] */ VARIANT_BOOL *vbShowMenue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPosChange )( 
            IScintillAxEvents * This,
            /* [in] */ long iLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnChar )( 
            IScintillAxEvents * This,
            /* [in] */ BSTR ch);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSyntax )( 
            IScintillAxEvents * This,
            /* [in] */ long s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSystem )( 
            IScintillAxEvents * This,
            /* [in] */ long s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnEncoding )( 
            IScintillAxEvents * This,
            /* [in] */ long e);
        
        END_INTERFACE
    } IScintillAxEventsVtbl;

    interface IScintillAxEvents
    {
        CONST_VTBL struct IScintillAxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxEvents_OnFileNameChanged(This,fname,fPath)	\
    ( (This)->lpVtbl -> OnFileNameChanged(This,fname,fPath) ) 

#define IScintillAxEvents_OnShowMenu(This,vbShowMenue)	\
    ( (This)->lpVtbl -> OnShowMenu(This,vbShowMenue) ) 

#define IScintillAxEvents_OnPosChange(This,iLine)	\
    ( (This)->lpVtbl -> OnPosChange(This,iLine) ) 

#define IScintillAxEvents_OnChar(This,ch)	\
    ( (This)->lpVtbl -> OnChar(This,ch) ) 

#define IScintillAxEvents_OnSyntax(This,s)	\
    ( (This)->lpVtbl -> OnSyntax(This,s) ) 

#define IScintillAxEvents_OnSystem(This,s)	\
    ( (This)->lpVtbl -> OnSystem(This,s) ) 

#define IScintillAxEvents_OnEncoding(This,e)	\
    ( (This)->lpVtbl -> OnEncoding(This,e) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ScintillAx;

#ifdef __cplusplus

class DECLSPEC_UUID("9B5488B0-33FB-44df-8D58-672A1C1E08C1")
ScintillAx;
#endif

EXTERN_C const CLSID CLSID_ScintillAxProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("C16CD143-5126-414a-AFDE-406F31E95D13")
ScintillAxProperties;
#endif
#endif /* __Scintilla_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


