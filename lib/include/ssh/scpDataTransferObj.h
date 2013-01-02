#ifndef _MOL_DEF_GUARD_DEFINE_SCP_DATA_TRANSFER_OBJ_DEFINE_
#define _MOL_DEF_GUARD_DEFINE_SCP_DATA_TRANSFER_OBJ_DEFINE_

#include "ssh.h"
#include "scp.h"
#include "sftp.h"

#include "ole/dataobj.h"
#include "ole/enum.h"
#include "ole/Stream.h"
#include "tcp/sockets.h"
#include "thread/events.h"

#include <ShlObj.h>

struct ssh_session_struct;
struct ssh_scp_struct;



namespace mol {
namespace scp {


UINT cfstr_filecontents();
UINT cfstr_filedescriptor();
UINT cfstr_isSShData();

struct FileDescriptor : public FILEDESCRIPTOR
{
	void set(const mol::string& fn, UINT attr, UINT sizeLow , UINT sizeHigh = 0, UINT flags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI)
	{
		::ZeroMemory((FILEDESCRIPTOR*)this,sizeof(FILEDESCRIPTOR));
		wcsncpy(cFileName,fn.c_str(), fn.size()+1);
		dwFlags = flags;
		dwFileAttributes = attr;

		nFileSizeHigh = sizeHigh;
		nFileSizeLow = sizeLow;
	}

	void set(const mol::string& fn, UINT attr, int size = 0, UINT flags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI)
	{
		set( fn, attr, size, 0, flags );
	}

	void setDirectory(const mol::string& fn, UINT flags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI)
	{
		set(fn,FILE_ATTRIBUTE_DIRECTORY,0,flags);
	}

	void setFile(const mol::string& fn, int sizeLow, int sizeHigh, UINT flags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI)
	{
		set(fn,FILE_ATTRIBUTE_NORMAL,sizeLow,sizeHigh,flags); 
	}

	void setFile(const mol::string& fn, int size, UINT flags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI)
	{
		set(fn,FILE_ATTRIBUTE_NORMAL,size,flags); 
	}

	FileDescriptor& operator=(const FileDescriptor& rhs )
	{
		if ( this == &rhs )
		{
			return *this;
		}
		::ZeroMemory((FILEDESCRIPTOR*)this,sizeof(FILEDESCRIPTOR));
		wcscpy(this->cFileName,rhs.cFileName);
		this->dwFileAttributes = rhs.dwFileAttributes;
		this->dwFlags = rhs.dwFlags;
		this->nFileSizeHigh = rhs.nFileSizeHigh;
		this->nFileSizeLow = rhs.nFileSizeLow;
		return *this;
	}
};


struct FileGroupDescriptor : public FILEGROUPDESCRIPTOR
{
	UINT size()
	{
		return cItems;
	}

	FILEDESCRIPTOR* item(size_t index)
	{
		if ( (UINT)index > cItems-1 )
			return 0;

		return (FILEDESCRIPTOR*)(&(this->fgd[index]));
	}

	FILEDESCRIPTOR* operator[](size_t index)
	{
		return item(index);
	}

	static size_t size(size_t n) 
	{
		size_t s = sizeof(FILEGROUPDESCRIPTOR)+sizeof(FILEDESCRIPTOR)*(n-1);
		return s;
	}

	static FileGroupDescriptor* alloc(size_t n)
	{
		size_t size = FileGroupDescriptor::size(n);
		FILEGROUPDESCRIPTOR* fgd = (FILEGROUPDESCRIPTOR*)malloc(size);
		fgd->cItems = (UINT)n;
		return (FileGroupDescriptor*)fgd;
	}

	static FileGroupDescriptor* fromMedium(STGMEDIUM * pmedium)
	{
		if ( pmedium->tymed != TYMED_HGLOBAL)
			return 0;

		mol::global glob;
		glob.attach(pmedium->hGlobal);

		FileGroupDescriptor* src = (FileGroupDescriptor*)glob.lock();

		size_t size = src->size();

		FileGroupDescriptor* dest = 0;
		if ( size )
		{
			dest = FileGroupDescriptor::alloc(size);
			memcpy(dest,src,size);
		}
		glob.unLock();		
		glob.detach();

		return dest;
	}
};

class FGD
{
public:
	FGD(size_t n)
		: fgd_(FileGroupDescriptor::alloc(n))
	{}

	~FGD()
	{
		free(fgd_);
	}

	FileGroupDescriptor* operator->()
	{
		return fgd_;
	}


	FileGroupDescriptor* operator*()
	{
		return fgd_;
	}

	void toMedium(STGMEDIUM * pmedium)
	{
		pmedium->tymed = TYMED_HGLOBAL;

		mol::global glob( (void*)fgd_, fgd_->size(),GMEM_MOVEABLE );
		pmedium->hGlobal = (HGLOBAL)glob;
		glob.detach();
	}

private:

	FileGroupDescriptor* fgd_;
};




class scpStream : 
	public IStream, 
	public mol::interfaces< scpStream, 
				mol::implements<
						mol::interface_ex<ISequentialStream,IStream>,
						IStream> >
{
public:
	scpStream();
	virtual ~scpStream();

	void dispose() 
	{
		disconnect();
	}

	void initScp(const mol::string& host, int port, const mol::string& filename, mol::ssh::CredentialCallback* cb);

	virtual HRESULT __stdcall  Read( void *pv, ULONG cb, ULONG *pcbRead);
    virtual HRESULT __stdcall  Write( const void *pv, ULONG cb, ULONG *pcbWritten);
	virtual HRESULT __stdcall  Seek( LARGE_INTEGER dlibMove, DWORD dwOrigin,ULARGE_INTEGER *plibNewPosition);
	virtual HRESULT __stdcall  SetSize( ULARGE_INTEGER libNewSize);
	virtual HRESULT __stdcall  CopyTo( IStream *pstm,ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead,  ULARGE_INTEGER *pcbWritten);
	virtual HRESULT __stdcall  Commit(  DWORD grfCommitFlags);
	virtual HRESULT __stdcall  Revert( void);
	virtual HRESULT __stdcall  LockRegion( ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
    virtual HRESULT __stdcall  UnlockRegion(  ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
    virtual HRESULT __stdcall  Stat( STATSTG *pstatstg, DWORD grfStatFlag);
    virtual HRESULT __stdcall  Clone( IStream **ppstm);

private:

	bool connect();
	void disconnect();

	mol::string filename_;
	size_t size_;
	size_t nread_;
	bool connected_;

	mol::ssh::Session ssh_;
	mol::scp::Session scp_;

	mol::string host_;
	int port_;

	mol::ssh::CredentialCallback* cb_;
};

#if (_MSC_VER < 1700 )
#define IMoeDataObjectAsyncCapability IAsyncOperation
#else
#define IMoeDataObjectAsyncCapability IDataObjectAsyncCapability
#endif

class DelayedDataTransferObj
	: public mol::ole::DataObjBase,
	  public IMoeDataObjectAsyncCapability,
	  public mol::interfaces< DelayedDataTransferObj, 
			       mol::implements<IDataObject,IMoeDataObjectAsyncCapability> >
{
public:

	DelayedDataTransferObj();	
    virtual ~DelayedDataTransferObj();

	bool init (const mol::string& host, int port, mol::ssh::CredentialCallback* cb, BOOL cut = false);
	bool add (const mol::string& remotefile,unsigned long long size,bool isdir);

	template<class E>
	void connect( E* e, IUnknown* unk )
	{
		holder_ = unk;
		dropEffectEvent_ += e;
	}

	HRESULT virtual __stdcall GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium );
	HRESULT virtual __stdcall QueryGetData( FORMATETC * pFormatetc );
	HRESULT virtual __stdcall EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc );
	HRESULT virtual __stdcall SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease );

	HRESULT virtual __stdcall  SetAsyncMode( BOOL fDoOpAsync);
    HRESULT virtual __stdcall  GetAsyncMode( BOOL *pfIsOpAsync);
    HRESULT virtual __stdcall  StartOperation( IBindCtx *pbcReserved);
    HRESULT virtual __stdcall  InOperation( BOOL *pfInAsyncOp);
    HRESULT virtual __stdcall  EndOperation(  HRESULT hResult,IBindCtx *pbcReserved, DWORD dwEffects);

protected:

	void enumerateRemoteDir(const mol::string& filename,unsigned long long size,bool isdir);

	void connect()
	{
		if ( ssh_.is_connected() )
			return;

		ssh_.open( mol::toUTF8(host_),cb_,port_);
		sftp_.open(ssh_);
	}

	mol::string host_;
	int port_;

	mol::string remoteroot_;

	mol::ssh::CredentialCallback* cb_;

	//UINT cf_filecontents_;
	//UINT cf_filedescriptor_;

	mol::format_etc_dropeffect	feDe_;
	mol::format_etc_pref_dropeffect		fepDe_;

	std::vector<FileDescriptor*> fds_;
	std::vector<std::wstring> files_;
	//std::vector<FILEDESCRIPTOR*> fds_;

	mol::ssh::Session ssh_;
	mol::sftp::Session sftp_;

	BOOL asyncSupported_;
	BOOL asyncInProgress_;
	BOOL cut_;

	mol::events::Event<IDataObject*>			dropEffectEvent_;

	mol::punk<IUnknown> holder_;
};






} // end namespace scp
} // end namespace mol
#endif