#include "StdAfx.h"
#include "PidlMgr.h"

#include "PidlMgr.h"
//#include "ShlFldr.h"
#include "resource.h"
#include <sstream>



PidlMgr& pidlManager()
{
	return mol::singleton<PidlMgr>();
}

PidlMgr::PidlMgr()
{
}

PidlMgr::~PidlMgr()
{
}

LPCITEMIDLIST PidlMgr::getRootPidl()
{
	return rootPidl_;
}


LPITEMIDLIST PidlMgr::create(SFTPPIDLTYPE type, const std::wstring& txt)
{
	LPITEMIDLIST   pidlOut = NULL;
	USHORT         uSize = 0;

	USHORT pathsize = (USHORT)(txt.size()+1)*sizeof(wchar_t);
	uSize = sizeof(ITEMIDLIST) + (sizeof(SFTPPIDLDATA) + pathsize);

	pidlOut = (LPITEMIDLIST)::CoTaskMemAlloc(uSize + sizeof(ITEMIDLIST));

	if(pidlOut)
	{
		LPITEMIDLIST		pidlTemp = pidlOut;
		LPSFTPPIDLDATA		pData;

		pidlTemp->mkid.cb = uSize;
		pData = getDataPointer(pidlTemp);
		pData->type = type;
		switch(type)
		{
			case PT_SFTP_ROOT:
				break;
			case PT_SFTP_SERVER:
			case PT_SFTP_DIR:
			case PT_SFTP_FILE:
				wcscpy(pData->path,txt.c_str());
				break;
		}
   
		//set the NULL terminator to 0
		pidlTemp = getNextItem(pidlTemp);
		pidlTemp->mkid.cb = 0;
		pidlTemp->mkid.abID[0] = 0;
	}
	return pidlOut;
}

void PidlMgr::destroy(LPITEMIDLIST pidl)
{
	::CoTaskMemFree(pidl);
}



void PidlMgr::setSftpRoot(LPCITEMIDLIST pidl)
{
	rootPidl_ = copy(pidl);
}


LPITEMIDLIST PidlMgr::createSftpServer(const std::wstring& server)
{
	return create(PT_SFTP_SERVER, server);
}

LPITEMIDLIST PidlMgr::createSftpPath(const std::wstring& path)
{
	return create(PT_SFTP_DIR, path);
}

LPITEMIDLIST PidlMgr::createSftpFile(const std::wstring& path)
{
	return create(PT_SFTP_FILE, path);
}


LPITEMIDLIST PidlMgr::getParentItem(LPITEMIDLIST pidl)
{
	LPITEMIDLIST p = copy(pidl);
	ILRemoveLastID(p);
	return p;
}

LPITEMIDLIST PidlMgr::getNextItem(LPCITEMIDLIST pidl)
{
	if(pidl)
		if ( pidl->mkid.cb == 0 )
			return NULL;
		else
			return (LPITEMIDLIST)(LPBYTE)(((LPBYTE)pidl) + pidl->mkid.cb);
	else
		return (NULL);
}

UINT PidlMgr::getSize(LPCITEMIDLIST pidl)
{
	UINT cbTotal = 0;
	LPITEMIDLIST pidlTemp = (LPITEMIDLIST) pidl;

	if(pidlTemp)
	{
		while(pidlTemp->mkid.cb)
		{
			cbTotal += pidlTemp->mkid.cb;
			pidlTemp = getNextItem(pidlTemp);
		}  

	    //add the size of the NULL terminating ITEMIDLIST
	    cbTotal += sizeof(ITEMIDLIST);
	  }

	return (cbTotal);
}

std::wstring PidlMgr::getData(LPCITEMIDLIST pidl)
{
	if(!pidl)
		return L"";

	if ( isRoot(pidl) )
	{
		return L"ssh:/";
	}

	LPSFTPPIDLDATA  pData = getDataPointer(pidl);

	if ( pData->type != PT_SFTP_ROOT && 
		 pData->type != PT_SFTP_SERVER && 
		 pData->type != PT_SFTP_DIR && 
		 pData->type != PT_SFTP_FILE )
		 return L"";

	if(!pData->path)
		return L"";
	std::wstring ret(pData->path);
	return ret;
}

std::wstring PidlMgr::getSftpRoot(LPCITEMIDLIST pidl)
{
	return getData(pidl);
}


std::wstring PidlMgr::getSftpServerName(LPCITEMIDLIST pidl)
{
	LPCITEMIDLIST tmp = pidl;
	if ( isRoot(tmp) )
	{
		tmp = getNextItem(tmp);
	}

	std::wstring s = getData(tmp);
	size_t pos = s.find(L":");
	if ( pos != std::wstring::npos )
	{
		return s.substr(0,pos);
	}
	return s;
}

int PidlMgr::getSftpServerPort(LPCITEMIDLIST pidl)
{
	LPCITEMIDLIST tmp = pidl;
	if ( isRoot(tmp) )
	{
		tmp = getNextItem(tmp);
	}

	std::wstring s = getData(tmp);
	size_t pos = s.find(L":");
	if ( pos != std::wstring::npos )
	{
		std::wstring sport = s.substr(pos+1);
		std::wistringstream iss(sport);
		int port = 0;
		iss >> port;
		return port;
	}
	return 22;
}

LPITEMIDLIST PidlMgr::getLastItem(LPCITEMIDLIST pidl)
{
	LPITEMIDLIST   pidlLast = NULL;

	//get the PIDL of the last item in the list
	if(pidl)
	{
		while(pidl->mkid.cb)
		{
			pidlLast = (LPITEMIDLIST)pidl;
			pidl = getNextItem(pidl);
		}  
	}

	return pidlLast;
}

bool  PidlMgr::isEqual(LPCITEMIDLIST pidl1, LPCITEMIDLIST pidl2)
{
	if ( ILIsEqual(pidl1,pidl2) )
		return true;

	if ( isRoot(pidl1) || isRoot(pidl2) )
	{
		if ( isRoot(pidl1) && isRoot(pidl2) )
		{
			return true;
		}
		return false;
	}

	std::wstring p1 = getPidlPath(pidl1);
	std::wstring p2 = getPidlPath(pidl2);
	return p1 == p2;
}

std::wstring PidlMgr::getSftpPath(LPCITEMIDLIST pidl)
{
	LPCITEMIDLIST tmp = pidl;
	if ( isRoot(tmp) )
	{
		tmp = getNextItem(tmp);
	}
	if ( isServer(tmp) )
	{
		tmp = getNextItem(tmp);
	}
	return getPidlPath(tmp);
}

std::wstring PidlMgr::getSftpFilename(LPCITEMIDLIST pidl)
{
	LPCITEMIDLIST tmp = getLastItem(pidl);
	return getData(tmp);
}
LPITEMIDLIST PidlMgr::copy(LPCITEMIDLIST pidlSource)
{
	LPITEMIDLIST pidlTarget = NULL;
	UINT cbSource = 0;

	if(NULL == pidlSource)
		return (NULL);

	// Allocate the new pidl
	cbSource = getSize(pidlSource);
	pidlTarget = (LPITEMIDLIST)::CoTaskMemAlloc(cbSource);
	if(!pidlTarget)
	   return (NULL);

	// Copy the source to the target
	CopyMemory(pidlTarget, pidlSource, cbSource);

	return pidlTarget;
}

bool PidlMgr::isRoot(LPCITEMIDLIST pidl)
{
	if (!pidl)
		return true;

	if ( ILIsEqual(pidl,rootPidl_) )
	{
		return true;
	}

	return false;
}

bool PidlMgr::isPath(LPCITEMIDLIST pidl)
{
	if (!pidl)
		return false;

	LPSFTPPIDLDATA  pData = getDataPointer(pidl);
	return (PT_SFTP_DIR == pData->type);
}

bool PidlMgr::isFile(LPCITEMIDLIST pidl)
{
	if (!pidl)
		return false;

	LPSFTPPIDLDATA  pData = getDataPointer(pidl);
	return (PT_SFTP_FILE == pData->type);
}

bool PidlMgr::isServer(LPCITEMIDLIST pidl)
{
	if (!pidl)
		return false;

	LPSFTPPIDLDATA  pData = getDataPointer(pidl);
	return (PT_SFTP_SERVER == pData->type);
}

bool PidlMgr::isDir(LPCITEMIDLIST pidl)
{
	if (!pidl)
		return true;

	LPCITEMIDLIST  tmp = getLastItem(pidl);
	return !isFile(tmp);
}

LPSFTPPIDLDATA PidlMgr::getDataPointer(LPCITEMIDLIST pidl)
{
	if(!pidl)
		return NULL;
	return (LPSFTPPIDLDATA)(pidl->mkid.abID);
}


std::wstring PidlMgr::getPidlPath(LPCITEMIDLIST pidl)
{
	std::wostringstream oss;

	LPCITEMIDLIST tmp = pidl; 
	if ( isRoot(tmp) )
	{
		std::wstring data = getData(tmp);
		oss << L"ssh://";
		tmp = getNextItem(tmp);
	}

	if ( isServer(tmp) )
	{
		std::wstring data = getData(tmp);
		oss << data;
		tmp = getNextItem(tmp);
	}

	while(tmp && tmp->mkid.cb)
	{
		std::wstring data = getData(tmp);
		oss << L"/" << data;
		tmp = getNextItem(tmp);
	}

	return oss.str();
}

LPITEMIDLIST PidlMgr::concat(LPCITEMIDLIST pidl1, LPCITEMIDLIST pidl2)
{
	LPITEMIDLIST   pidlNew;
	UINT           cb1 = 0, 
				   cb2 = 0;

	//are both of these NULL?
	if(!pidl1 && !pidl2)
	   return NULL;

	//if pidl1 is NULL, just return a copy of pidl2
	if(!pidl1)
	{
	   pidlNew = copy(pidl2);

	   return pidlNew;
	}

	//if pidl2 is NULL, just return a copy of pidl1
	if(!pidl2)
	{
	   pidlNew = copy(pidl1);

	   return pidlNew;
	}

	cb1 = getSize(pidl1) - sizeof(ITEMIDLIST);

	cb2 = getSize(pidl2);

	//create the new PIDL
	pidlNew = (LPITEMIDLIST)::CoTaskMemAlloc(cb1 + cb2);

	if(pidlNew)
	{
	   //copy the first PIDL
	   ::CopyMemory(pidlNew, pidl1, cb1);
   
	  //copy the second PIDL
	   ::CopyMemory(((LPBYTE)pidlNew) + cb1, pidl2, cb2);
	}

	return pidlNew;
}

