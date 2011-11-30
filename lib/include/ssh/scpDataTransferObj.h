#ifndef _MOL_DEF_GUARD_DEFINE_SCP_DATA_TRANSFER_OBJ_DEFINE_
#define _MOL_DEF_GUARD_DEFINE_SCP_DATA_TRANSFER_OBJ_DEFINE_

#include "ssh.h"
#include "scp.h"
#include "sftp.h"

#include "ole/dataobj.h"
#include "ole/enum.h"
#include "ole/Stream.h"
#include "tcp/sockets.h"
#include <ShlObj.h>

struct ssh_session_struct;
struct ssh_scp_struct;



namespace mol {
namespace scp {


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


class DelayedDataTransferObj
	: public mol::ole::DataObjBase,
	  public IAsyncOperation,
	  public mol::interfaces< DelayedDataTransferObj, 
			       mol::implements<IDataObject,IAsyncOperation> >
{
public:

	DelayedDataTransferObj();	
    virtual ~DelayedDataTransferObj();

	bool init (const mol::string& host, int port, mol::ssh::CredentialCallback* cb, BOOL cancel = false);
	bool add (const mol::string& remotefile,unsigned long long size,bool isdir);

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

	UINT cf_filecontents_;
	UINT cf_filedescriptor_;

	mol::format_etc_dropeffect	feDe_;

	std::vector<FILEDESCRIPTOR*> fds_;

	mol::ssh::Session ssh_;
	mol::sftp::Session sftp_;

	BOOL asyncSupported_;
	BOOL asyncInProgress_;
	BOOL cancel_;
};






} // end namespace scp
} // end namespace mol
#endif