#include "ssh/scpDataTransferObj.h"

#include <libssh/libssh.h>
#include <libssh/callbacks.h>
#include <libssh/scp.h>
#include <libssh/sftp.h>


namespace mol {
namespace scp {


scpStream::scpStream(  )
	: connected_(false),size_(0),cb_(0),nread_(0)
{}

scpStream::~scpStream()
{
}

void scpStream::initScp(const mol::string& host, int port, const mol::string& filename, mol::ssh::CredentialCallback* cb)
{
	filename_ = filename;
	cb_		  = cb;
	host_	  = host;
	port_	  = port;
}

bool scpStream::connect()
{
	if ( !ssh_.is_connected() )
	{
		ssh_.open( mol::toUTF8(host_),cb_,port_);
		if ( !ssh_.is_connected() )
			return false;
	}

	nread_ = 0;
		
	scp_.open( ssh_, mol::SSH_SCP_READ, filename_ );

	int rc = ssh_scp_pull_request(scp_);
	if (rc != SSH_SCP_REQUEST_NEWFILE)
	{
		return false;
	}

	size_ = ssh_scp_request_get_size(scp_);
	const char* filename = ssh_scp_request_get_filename(scp_);
	filename_ = mol::fromUTF8(filename);
	int mode = ssh_scp_request_get_permissions(scp_);

	connected_ = true;
	return true;
}

void scpStream::disconnect()
{
	ODBGS("Stream disconnect");
	scp_.dispose();
	ssh_.dispose();
	connected_ = false;
}

HRESULT __stdcall scpStream::Read( void *pv, ULONG cb, ULONG *pcbRead)
{	
	ODBGS("scpStream read");
	if ( cb )
	{
		if ( pcbRead )
		{
			*pcbRead = 0;
		}

		if ( size_ && nread_ >= size_ )
		{
			disconnect();
			return 0 == cb ? S_OK : S_FALSE;
		}

		if (!connect())
			return E_FAIL;

		char* buffer = new char[cb];

		ssh_scp_accept_request(scp_);

		ULONG nread = 0;
		while ( nread < cb )
		{
			int rc = ssh_scp_read(scp_, buffer, cb-nread);
			if (rc == SSH_ERROR)
			{
				disconnect();
				nread_ = 0;
				delete[] buffer;
				return E_FAIL;
			}

			memcpy( ((char*)pv)+nread, buffer, rc );

			nread_ += rc;
			nread  += rc;

			if ( pcbRead )
			{
				*pcbRead += rc;
			}
			
			if ( nread_ >= size_ )
			{
				int rc = ssh_scp_pull_request(scp_);
				if (rc != SSH_SCP_REQUEST_EOF)
				{
					disconnect();
					nread_ = 0;
					delete[] buffer;
					return E_FAIL;			
				}
				//disconnect();
				delete[] buffer;
				return nread == cb ? S_OK : S_FALSE;
			}
		}
		if ( nread == cb  )
		{
			disconnect();
		}
		delete[] buffer;
		return nread == cb ? S_OK : S_FALSE;
	}
	return E_FAIL;
}

HRESULT __stdcall scpStream::Write( const void *pv, ULONG cb, ULONG *pcbWritten)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::Seek( LARGE_INTEGER dlibMove, DWORD dwOrigin,ULARGE_INTEGER *plibNewPosition)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::SetSize( ULARGE_INTEGER libNewSize)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::CopyTo( IStream *pstm,ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead,  ULARGE_INTEGER *pcbWritten)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::Commit(  DWORD grfCommitFlags)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::Revert( void)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::LockRegion( ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::UnlockRegion(  ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType)
{
	return E_NOTIMPL;
}

HRESULT __stdcall scpStream::Stat( STATSTG *pstatstg, DWORD grfStatFlag)
{
	ODBGS("Stream Stat");
	connect();

	if ( grfStatFlag == STATFLAG_DEFAULT)
	{
		pstatstg->pwcsName = (mol::TCHAR*)::CoTaskMemAlloc(filename_.size()*sizeof(wchar_t));
		memcpy(pstatstg->pwcsName,filename_.c_str(),filename_.size()*sizeof(wchar_t));
	}
	else
	{
		pstatstg->pwcsName = 0;
	}

	FILETIME nullTime;
	::ZeroMemory(&nullTime,sizeof(FILETIME));
	pstatstg->atime = nullTime;

	ULARGE_INTEGER ui;
	ui.HighPart = 0;
	ui.LowPart = (DWORD)size_;

	pstatstg->cbSize = ui;
	pstatstg->clsid = CLSID_NULL;
	pstatstg->ctime = nullTime;
	pstatstg->grfLocksSupported = 0;
	pstatstg->grfMode = 0;
	pstatstg->grfStateBits = 0;
	pstatstg->mtime = nullTime;
	pstatstg->type = STGTY_STREAM;

	return S_OK;
}

HRESULT __stdcall scpStream::Clone( IStream **ppstm)
{
	return E_NOTIMPL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


DelayedDataTransferObj::DelayedDataTransferObj()
{
	asyncSupported_    = false;
	asyncInProgress_   = false;

	cf_filecontents_   = ::RegisterClipboardFormat(CFSTR_FILECONTENTS);
	cf_filedescriptor_ = ::RegisterClipboardFormat(CFSTR_FILEDESCRIPTOR);
}

bool DelayedDataTransferObj::init(const mol::string& host, int port, mol::ssh::CredentialCallback* cb, BOOL cancel)
{
	host_   = host;
	port_   = port;
	cb_     = cb;
	cancel_ = cancel;

	cf_filecontents_   = ::RegisterClipboardFormat(CFSTR_FILECONTENTS);
	cf_filedescriptor_ = ::RegisterClipboardFormat(CFSTR_FILEDESCRIPTOR);

	return true;
}

bool DelayedDataTransferObj::add(const mol::string& remotefile,unsigned long long size,bool isdir)
{
	mol::string tmp = remotefile;

	if ( tmp[tmp.size()-1] == L'/' )
		tmp = tmp.substr(0,tmp.size()-1);

	size_t pos = tmp.find_last_of(L"/");
	if ( pos != std::string::npos)
	{
		tmp = tmp.substr(0,pos+1);
		if ( remoteroot_ != L"" && remoteroot_ != tmp )
			return false;

		remoteroot_ = tmp;
	}

	enumerateRemoteDir(remotefile,size,isdir);

	return true;
}
//////////////////////////////////////////////////////////////////////////////////

DelayedDataTransferObj::~DelayedDataTransferObj()
{
	for ( size_t i = 0; i < fds_.size(); i++)
	{
		delete fds_[i];
	}
	fds_.clear();

	ODBGS("destroyed DelayedDataTransferObj::~DelayedDataTransferObj");
}


void DelayedDataTransferObj::enumerateRemoteDir(const mol::string& filename,unsigned long long size,bool isdir)
{
	ODBGS("DelayedDataTransferObj enumerateRemoteDir");

	try 
	{			
		if ( isdir )
		{
			connect();
			std::vector<mol::sftp::RemoteFile> v = sftp_.list(filename);
			for ( size_t i = 0; i < v.size(); i++)
			{
				if ( v[i].getName() == _T(".") )
					continue;

				if ( v[i].getName() == _T("..") )
					continue;

				if ( v[i].isDir() )
				{
	
					mol::string tmp = filename;

					mol::ostringstream oss;
					oss << tmp;
					if ( tmp[tmp.size()-1] != L'/' )
					{
						oss << L"/";
					}

					oss << v[i].getName();
					tmp = oss.str();

					FILEDESCRIPTOR* fd = new FILEDESCRIPTOR;
					::ZeroMemory(fd,sizeof(fd));
					wcsncpy(fd->cFileName,tmp.c_str(), tmp.size()+1);
					fd->dwFlags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI;
					fd->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
					fd->nFileSizeLow = 0;

					fds_.push_back(fd);

					enumerateRemoteDir(tmp,v[i].getSize(),true);
	
				}
				else
				{
					mol::string tmp = filename;

					mol::ostringstream oss;
					oss << tmp;
					if ( tmp[tmp.size()-1] != L'/' )
					{
						oss << L"/";
					}

					oss <<  v[i].getName();
					tmp = oss.str();

					FILEDESCRIPTOR* fd = new FILEDESCRIPTOR;
					::ZeroMemory(fd,sizeof(fd));
					wcsncpy(fd->cFileName,tmp.c_str(), tmp.size()+1);
					fd->dwFlags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI;
					fd->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;

					LARGE_INTEGER li;
					li.QuadPart = v[i].getSize();
					fd->nFileSizeHigh = li.HighPart;
					fd->nFileSizeLow = li.LowPart;

					fds_.push_back(fd);
				}
			}
		}
		else
		{
					FILEDESCRIPTOR* fd = new FILEDESCRIPTOR;
					::ZeroMemory(fd,sizeof(fd));
					wcsncpy(fd->cFileName,filename.c_str(), filename.size()+1);
					fd->dwFlags = FD_FILESIZE | FD_ATTRIBUTES |FD_PROGRESSUI;
					fd->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;

					LARGE_INTEGER li;
					li.QuadPart = size;
					fd->nFileSizeHigh = li.HighPart;
					fd->nFileSizeLow = li.LowPart;

					fds_.push_back(fd);
		}
	}
	catch(...)
	{
		return ;
	}
}

HRESULT __stdcall DelayedDataTransferObj::GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium )
{
	ODBGS("DataTransferObj::GetData");

	::ZeroMemory(pmedium, sizeof(*pmedium));	

	if ( pFormatetc->cfFormat == cf_filedescriptor_)
	{
		ODBGS("DataTransferObj::GetData - Filedescriptor");

		size_t size = sizeof(FILEGROUPDESCRIPTOR)+sizeof(FILEDESCRIPTOR)*(fds_.size()-1);
		FILEGROUPDESCRIPTOR* fgd = (FILEGROUPDESCRIPTOR*)malloc(size);
		
		fgd->cItems = (UINT)fds_.size();

		for ( size_t i = 0; i < fds_.size(); i++)
		{
			mol::ostringstream oss;
			mol::string tmp = fds_[i]->cFileName;

			size_t pos = tmp.find(remoteroot_);
			if ( pos == std::string::npos)
				continue;

			tmp = tmp.substr(pos+remoteroot_.size());

			pos = tmp.find(L"/");
			while(pos!=std::string::npos)
			{
				tmp[pos] = L'\\';
				pos = tmp.find(L"/");
			}

			ODBGS(tmp);

			wcscpy(fgd->fgd[i].cFileName, tmp.c_str() );
			fgd->fgd[i].dwFlags = fds_[i]->dwFlags;
			fgd->fgd[i].dwFileAttributes = fds_[i]->dwFileAttributes;
			fgd->fgd[i].nFileSizeHigh = fds_[i]->nFileSizeHigh;
			fgd->fgd[i].nFileSizeLow = fds_[i]->nFileSizeLow;
		}

		pmedium->tymed = TYMED_HGLOBAL;

		mol::global glob( (void*)fgd, size,GMEM_MOVEABLE );
		pmedium->hGlobal = (HGLOBAL)glob;
		glob.detach();

		free(fgd);
		return S_OK;
	}

	if ( pFormatetc->cfFormat == cf_filecontents_)
	{
		if (pFormatetc->lindex >= 0 && pFormatetc->lindex < fds_.size())
		{
			ODBGS1("DataTransferObj::GetData - cf_filecontents_ - index",pFormatetc->lindex);
			pmedium->tymed = TYMED_ISTREAM;

			mol::string s = fds_[pFormatetc->lindex]->cFileName;

			mol::punk< mol::com_obj<scpStream> > scpstream = new mol::com_obj<scpStream>;	
			scpstream->initScp( host_, port_,s,cb_);

			HRESULT hr = scpstream.queryInterface(&(pmedium->pstm));
			return hr;
		}
	}
	return DV_E_FORMATETC;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DelayedDataTransferObj::QueryGetData( FORMATETC * pFormatetc )
{
	ODBGS("DelayedDataTransferObj::QueryGetData");

	if ( pFormatetc->cfFormat == cf_filedescriptor_)
	{		
		return S_OK;
	}

	if ( pFormatetc->cfFormat == cf_filecontents_)
	{		
		return S_OK;
	}

	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DelayedDataTransferObj::EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc )
{
	ODBGS("DataTransferObj::EnumFormatEtc");

	mol::com_obj<mol::enum_format>* efi = new mol::com_obj<mol::enum_format>;

	mol::format_etc fe_filedescriptor(cf_filedescriptor_,NULL,DVASPECT_CONTENT,-1,TYMED_HGLOBAL);
	efi->add(fe_filedescriptor);

	for ( size_t i = 0; i < fds_.size(); i++)
	{
		mol::format_etc fe_filecontents(cf_filecontents_,NULL,DVASPECT_CONTENT,(LONG)i,TYMED_ISTREAM);
		efi->add(fe_filecontents);
	}

	efi->QueryInterface(IID_IEnumFORMATETC,(void**)ppenumFormatetc);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DelayedDataTransferObj::SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease )
{
	ODBGS("DataTransferObj::SetData");

	return E_NOTIMPL;
}


//////////////////////////////////////////////////////////////////////////////////
// IAsyncOperation
//////////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall  DelayedDataTransferObj::SetAsyncMode( BOOL fDoOpAsync)
{
	asyncSupported_ = fDoOpAsync;
	return S_OK;
}

HRESULT __stdcall  DelayedDataTransferObj::GetAsyncMode( BOOL *pfIsOpAsync)
{
	if(!pfIsOpAsync)
		return E_INVALIDARG;

	*pfIsOpAsync = asyncSupported_;
	return S_OK;
}

HRESULT __stdcall  DelayedDataTransferObj::StartOperation( IBindCtx *pbcReserved)
{
	((IAsyncOperation*)this)->AddRef();
	asyncInProgress_ = true;
	return S_OK;
}

HRESULT __stdcall  DelayedDataTransferObj::InOperation( BOOL *pfInAsyncOp)
{
	if(!pfInAsyncOp)
		return E_INVALIDARG;

	*pfInAsyncOp = asyncInProgress_;
	return S_OK;
}

HRESULT __stdcall  DelayedDataTransferObj::EndOperation(  HRESULT hResult,IBindCtx *pbcReserved, DWORD dwEffects)
{
	asyncInProgress_   = false;
	((IAsyncOperation*)this)->Release();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////



} // end namespace scp
} // end namespace mol
