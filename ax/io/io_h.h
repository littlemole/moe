

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Sep 12 21:47:21 2011
 */
/* Compiler settings for io.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
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


#ifndef __io_h_h__
#define __io_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFile_FWD_DEFINED__
#define __IFile_FWD_DEFINED__
typedef interface IFile IFile;
#endif 	/* __IFile_FWD_DEFINED__ */


#ifndef __IDir_FWD_DEFINED__
#define __IDir_FWD_DEFINED__
typedef interface IDir IDir;
#endif 	/* __IDir_FWD_DEFINED__ */


#ifndef __IPath_FWD_DEFINED__
#define __IPath_FWD_DEFINED__
typedef interface IPath IPath;
#endif 	/* __IPath_FWD_DEFINED__ */


#ifndef __Path_FWD_DEFINED__
#define __Path_FWD_DEFINED__

#ifdef __cplusplus
typedef class Path Path;
#else
typedef struct Path Path;
#endif /* __cplusplus */

#endif 	/* __Path_FWD_DEFINED__ */


#ifndef __File_FWD_DEFINED__
#define __File_FWD_DEFINED__

#ifdef __cplusplus
typedef class File File;
#else
typedef struct File File;
#endif /* __cplusplus */

#endif 	/* __File_FWD_DEFINED__ */


#ifndef __Dir_FWD_DEFINED__
#define __Dir_FWD_DEFINED__

#ifdef __cplusplus
typedef class Dir Dir;
#else
typedef struct Dir Dir;
#endif /* __cplusplus */

#endif 	/* __Dir_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __IO_LIBRARY_DEFINED__
#define __IO_LIBRARY_DEFINED__

/* library IO */
/* [helpstring][version][uuid] */ 


enum IO_SYSTYPE
    {	IO_SYSTYPE_UNIX	= 0,
	IO_SYSTYPE_WIN32	= 1
    } ;


EXTERN_C const IID LIBID_IO;

#ifndef __IFile_INTERFACE_DEFINED__
#define __IFile_INTERFACE_DEFINED__

/* interface IFile */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5AF00596-158A-4ddd-BC20-83BC8D5E432F")
    IFile : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *f) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_EoL( 
            /* [in] */ long t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_EoL( 
            /* [retval][out] */ long *t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Encoding( 
            /* [in] */ long cp) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Encoding( 
            /* [retval][out] */ long *cp) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_UseBOM( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_UseBOM( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_EoF( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenReadOnly( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenAppend( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ long cnt,
            /* [retval][out] */ BSTR *file) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadText( 
            /* [retval][out] */ BSTR *file) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ long pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ BSTR file,
            /* [in] */ long len,
            /* [retval][out] */ long *s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteText( 
            /* [in] */ BSTR txt,
            /* [retval][out] */ long *s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ BSTR txt,
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFile * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFile * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IFile * This,
            /* [retval][out] */ BSTR *f);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EoL )( 
            IFile * This,
            /* [in] */ long t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EoL )( 
            IFile * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Encoding )( 
            IFile * This,
            /* [in] */ long cp);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Encoding )( 
            IFile * This,
            /* [retval][out] */ long *cp);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseBOM )( 
            IFile * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseBOM )( 
            IFile * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EoF )( 
            IFile * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IFile * This,
            /* [retval][out] */ long *s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IFile * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenReadOnly )( 
            IFile * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenAppend )( 
            IFile * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IFile * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IFile * This,
            /* [in] */ long cnt,
            /* [retval][out] */ BSTR *file);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadText )( 
            IFile * This,
            /* [retval][out] */ BSTR *file);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IFile * This,
            /* [in] */ long pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IFile * This,
            /* [in] */ BSTR file,
            /* [in] */ long len,
            /* [retval][out] */ long *s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteText )( 
            IFile * This,
            /* [in] */ BSTR txt,
            /* [retval][out] */ long *s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IFile * This,
            /* [in] */ BSTR txt,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        END_INTERFACE
    } IFileVtbl;

    interface IFile
    {
        CONST_VTBL struct IFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFile_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFile_get_Filename(This,f)	\
    ( (This)->lpVtbl -> get_Filename(This,f) ) 

#define IFile_put_EoL(This,t)	\
    ( (This)->lpVtbl -> put_EoL(This,t) ) 

#define IFile_get_EoL(This,t)	\
    ( (This)->lpVtbl -> get_EoL(This,t) ) 

#define IFile_put_Encoding(This,cp)	\
    ( (This)->lpVtbl -> put_Encoding(This,cp) ) 

#define IFile_get_Encoding(This,cp)	\
    ( (This)->lpVtbl -> get_Encoding(This,cp) ) 

#define IFile_put_UseBOM(This,vb)	\
    ( (This)->lpVtbl -> put_UseBOM(This,vb) ) 

#define IFile_get_UseBOM(This,vb)	\
    ( (This)->lpVtbl -> get_UseBOM(This,vb) ) 

#define IFile_get_EoF(This,vb)	\
    ( (This)->lpVtbl -> get_EoF(This,vb) ) 

#define IFile_get_Size(This,s)	\
    ( (This)->lpVtbl -> get_Size(This,s) ) 

#define IFile_Open(This,file,vb)	\
    ( (This)->lpVtbl -> Open(This,file,vb) ) 

#define IFile_OpenReadOnly(This,file,vb)	\
    ( (This)->lpVtbl -> OpenReadOnly(This,file,vb) ) 

#define IFile_OpenAppend(This,file,vb)	\
    ( (This)->lpVtbl -> OpenAppend(This,file,vb) ) 

#define IFile_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IFile_Read(This,cnt,file)	\
    ( (This)->lpVtbl -> Read(This,cnt,file) ) 

#define IFile_ReadText(This,file)	\
    ( (This)->lpVtbl -> ReadText(This,file) ) 

#define IFile_Seek(This,pos)	\
    ( (This)->lpVtbl -> Seek(This,pos) ) 

#define IFile_Write(This,file,len,s)	\
    ( (This)->lpVtbl -> Write(This,file,len,s) ) 

#define IFile_WriteText(This,txt,s)	\
    ( (This)->lpVtbl -> WriteText(This,txt,s) ) 

#define IFile_Create(This,txt,vb)	\
    ( (This)->lpVtbl -> Create(This,txt,vb) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFile_INTERFACE_DEFINED__ */


#ifndef __IDir_INTERFACE_DEFINED__
#define __IDir_INTERFACE_DEFINED__

/* interface IDir */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IDir;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92AF3107-79EB-480f-A118-6A3FF41E5085")
    IDir : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IEnumVARIANT **newEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long i,
            /* [retval][out] */ BSTR *direntry) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *cnt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDirVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDir * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDir * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDir * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDir * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDir * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDir * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDir * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            IDir * This,
            /* [retval][out] */ IEnumVARIANT **newEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IDir * This,
            /* [in] */ long i,
            /* [retval][out] */ BSTR *direntry);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IDir * This,
            /* [retval][out] */ long *cnt);
        
        END_INTERFACE
    } IDirVtbl;

    interface IDir
    {
        CONST_VTBL struct IDirVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDir_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDir_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDir_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDir_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDir_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDir_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDir_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDir__NewEnum(This,newEnum)	\
    ( (This)->lpVtbl -> _NewEnum(This,newEnum) ) 

#define IDir_Item(This,i,direntry)	\
    ( (This)->lpVtbl -> Item(This,i,direntry) ) 

#define IDir_Count(This,cnt)	\
    ( (This)->lpVtbl -> Count(This,cnt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDir_INTERFACE_DEFINED__ */


#ifndef __IPath_INTERFACE_DEFINED__
#define __IPath_INTERFACE_DEFINED__

/* interface IPath */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IPath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FFEB4898-0ECC-465a-851E-F5F7BB4136A8")
    IPath : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Extension( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Filename( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Path( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StripRoot( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Root( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddBackSlash( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveBackSlash( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddExtension( 
            /* [in] */ BSTR f,
            /* [in] */ BSTR e,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSubPath( 
            /* [in] */ BSTR p1,
            /* [in] */ BSTR p2,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exists( 
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsDir( 
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsRoot( 
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsUNC( 
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsNetDrive( 
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParentDir( 
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenDir( 
            /* [in] */ BSTR f,
            /* [retval][out] */ IDir **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenFile( 
            /* [in] */ BSTR f,
            /* [retval][out] */ IFile **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseDir( 
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileOpenDlg( 
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileSaveDlg( 
            /* [retval][out] */ BSTR *ret) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPath * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPath * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPath * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPath * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPath * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPath * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Extension )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Filename )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Path )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StripRoot )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Root )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddBackSlash )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveBackSlash )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddExtension )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [in] */ BSTR e,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSubPath )( 
            IPath * This,
            /* [in] */ BSTR p1,
            /* [in] */ BSTR p2,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exists )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsDir )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsRoot )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsUNC )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsNetDrive )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParentDir )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenDir )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ IDir **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenFile )( 
            IPath * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ IFile **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseDir )( 
            IPath * This,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileOpenDlg )( 
            IPath * This,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSaveDlg )( 
            IPath * This,
            /* [retval][out] */ BSTR *ret);
        
        END_INTERFACE
    } IPathVtbl;

    interface IPath
    {
        CONST_VTBL struct IPathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPath_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPath_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPath_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPath_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPath_Extension(This,f,ret)	\
    ( (This)->lpVtbl -> Extension(This,f,ret) ) 

#define IPath_Filename(This,f,ret)	\
    ( (This)->lpVtbl -> Filename(This,f,ret) ) 

#define IPath_Path(This,f,ret)	\
    ( (This)->lpVtbl -> Path(This,f,ret) ) 

#define IPath_StripRoot(This,f,ret)	\
    ( (This)->lpVtbl -> StripRoot(This,f,ret) ) 

#define IPath_Root(This,f,ret)	\
    ( (This)->lpVtbl -> Root(This,f,ret) ) 

#define IPath_AddBackSlash(This,f,ret)	\
    ( (This)->lpVtbl -> AddBackSlash(This,f,ret) ) 

#define IPath_RemoveBackSlash(This,f,ret)	\
    ( (This)->lpVtbl -> RemoveBackSlash(This,f,ret) ) 

#define IPath_AddExtension(This,f,e,ret)	\
    ( (This)->lpVtbl -> AddExtension(This,f,e,ret) ) 

#define IPath_IsSubPath(This,p1,p2,ret)	\
    ( (This)->lpVtbl -> IsSubPath(This,p1,p2,ret) ) 

#define IPath_Exists(This,f,ret)	\
    ( (This)->lpVtbl -> Exists(This,f,ret) ) 

#define IPath_IsDir(This,f,ret)	\
    ( (This)->lpVtbl -> IsDir(This,f,ret) ) 

#define IPath_IsRoot(This,f,ret)	\
    ( (This)->lpVtbl -> IsRoot(This,f,ret) ) 

#define IPath_IsUNC(This,f,ret)	\
    ( (This)->lpVtbl -> IsUNC(This,f,ret) ) 

#define IPath_IsNetDrive(This,f,ret)	\
    ( (This)->lpVtbl -> IsNetDrive(This,f,ret) ) 

#define IPath_ParentDir(This,f,ret)	\
    ( (This)->lpVtbl -> ParentDir(This,f,ret) ) 

#define IPath_OpenDir(This,f,ret)	\
    ( (This)->lpVtbl -> OpenDir(This,f,ret) ) 

#define IPath_OpenFile(This,f,ret)	\
    ( (This)->lpVtbl -> OpenFile(This,f,ret) ) 

#define IPath_ChooseDir(This,ret)	\
    ( (This)->lpVtbl -> ChooseDir(This,ret) ) 

#define IPath_FileOpenDlg(This,ret)	\
    ( (This)->lpVtbl -> FileOpenDlg(This,ret) ) 

#define IPath_FileSaveDlg(This,ret)	\
    ( (This)->lpVtbl -> FileSaveDlg(This,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPath_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Path;

#ifdef __cplusplus

class DECLSPEC_UUID("44DC1E37-CB3D-4328-B154-E50250F07A8F")
Path;
#endif

EXTERN_C const CLSID CLSID_File;

#ifdef __cplusplus

class DECLSPEC_UUID("C4E08E9A-0B46-4fd4-BB8D-588ABC27F52E")
File;
#endif

EXTERN_C const CLSID CLSID_Dir;

#ifdef __cplusplus

class DECLSPEC_UUID("302B0FE6-EE9A-4303-92B9-E6B69B573318")
Dir;
#endif
#endif /* __IO_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


