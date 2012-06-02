#include "StdAfx.h"
#include "EnumPidl.h"
#include "PidlMgr.h"
#include "win/shell.h"
#include "win/file.h"
#include "credmgr.h"

EnumIDList::EnumIDList()
{
	pFirst_ = pLast_ = pCurrent_ = NULL;
}

EnumIDList::~EnumIDList()
{
	deleteList();
}

EnumIDList::Instance* EnumIDList::createInstance(LPITEMIDLIST pidl, DWORD flags)
{
	Instance* instance = new Instance;
	instance->createEnumList(pidl,flags);
	return instance;
}


HRESULT __stdcall EnumIDList::Next(DWORD dwElements, LPITEMIDLIST apidl[], LPDWORD pdwFetched)
{
	DWORD    dwIndex;
	HRESULT  hr = S_OK;

	if(dwElements > 1 && !pdwFetched)
		return E_INVALIDARG;

	for(dwIndex = 0; dwIndex < dwElements; dwIndex++)
	{
		if(!pCurrent_)
		{
			hr =  S_FALSE;
			break;
		}

		apidl[dwIndex] = pidlManager().copy(pCurrent_->pidl);

		pCurrent_ = pCurrent_->pNext;
	}

	if(pdwFetched)
	   *pdwFetched = dwIndex;

	return hr;
}

HRESULT __stdcall EnumIDList::Skip(DWORD dwSkip)
{
	DWORD    dwIndex;
	HRESULT  hr = S_OK;

	for(dwIndex = 0; dwIndex < dwSkip; dwIndex++)
	{
		if(!pCurrent_)
		{
			hr = S_FALSE;
			break;
		}

		pCurrent_ = pCurrent_->pNext;
	}
	return hr;
}

HRESULT __stdcall EnumIDList::Reset(void)
{
	pCurrent_ = pFirst_;
	return S_OK;
}

HRESULT __stdcall EnumIDList::Clone(LPENUMIDLIST *ppEnum)
{
	::OutputDebugString(L"EnumIDList::Clone Not implemented\r\n");
	return E_NOTIMPL;
}

bool EnumIDList::createEnumList(LPITEMIDLIST parentPidl, DWORD dwFlags)
{
	if ( pidlManager().isRoot(pidlManager().getLastItem(parentPidl)) )
	{
		ViewModel* viewModel = viewModelRootFactory();

		for ( size_t i = 0; i < viewModel->server.size(); i++ )
		{
			std::wstring host = viewModel->server[i];
			LPITEMIDLIST pidl = pidlManager().createSftpServer(host);
			addToEnumList(pidl);
		}
		return true;
	}

	ViewModel* viewModel = viewModelPathFactory(parentPidl);
	if(!viewModel)
		return true;

	for ( size_t i = 0; i < viewModel->files.size(); i++ )
	{
		mol::sftp::RemoteFile& file = viewModel->files[i];
		if ( file.isDir() && (dwFlags & SHCONTF_FOLDERS))
		{
			LPITEMIDLIST pidl = pidlManager().createSftpPath(file.getName());
			addToEnumList(pidl);
		}
		else if ( dwFlags & SHCONTF_NONFOLDERS )
		{
			LPITEMIDLIST pidl = pidlManager().createSftpFile(file.getName());
			addToEnumList(pidl);
		}
	}
	return true;
}

bool EnumIDList::addToEnumList(LPITEMIDLIST pidl)
{
	LPENUMLIST  pNew = (LPENUMLIST)::CoTaskMemAlloc(sizeof(ENUMLIST));

	if(pNew)
	{
		//set the next pointer
		pNew->pNext = NULL;
		pNew->pidl = pidl;

		//is this the first item in the list?
		if(!pFirst_)
		{
			pFirst_ = pNew;
			pCurrent_ = pFirst_;
		}
   
		if(pLast_)
		{
			//add the new item to the end of the list
			pLast_->pNext = pNew;
		}
   
		//update the last item pointer
		pLast_ = pNew;

		return true;
	}
	return false;
}


void EnumIDList::deleteList()
{
	LPENUMLIST  pDelete;

	while(pFirst_)
	{
		pDelete = pFirst_;
		pFirst_ = pDelete->pNext;

		//free the pidl
		pidlManager().destroy(pDelete->pidl);
   
		//free the list item
		::CoTaskMemFree(pDelete);
    }

	pFirst_ = pLast_ = pCurrent_ = NULL;
}


