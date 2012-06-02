#include "StdAfx.h"
#include "credMgr.h"
#include "win/dlg.h"
#include "ShellFolder.h"

class PwdDlg  : public mol::win::Dialog
{
public:

	PwdDlg(const mol::string& host, int port)
		: host_(host), port_(port)
	{}

	mol::ssh::wstring user;
	mol::ssh::wstring pwd;

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_EDIT_HOST,host_.c_str());
				setDlgItemInt(IDC_EDIT_PORT,port_);
				::SetFocus(getDlgItem(IDC_EDIT_USER));
				this->center();
				this->setForeGround();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					mol::string u;
					mol::string p;
					getDlgItemText(IDC_EDIT_USER,u);
					getDlgItemText(IDC_EDIT_PWD,p);
					user = mol::ssh::wstring( u.c_str() );
					pwd  = mol::ssh::wstring( p.c_str() );
					endDlg(LOWORD(wParam));
					return FALSE;
				}
				if (LOWORD(wParam) == IDCANCEL )
				{
					endDlg(LOWORD(wParam));
					return FALSE;
				}
			}
		}
		return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
	}

private:

	mol::string host_;
	int port_;

};

////////////////////////////////////////////////////////////////

class AccepHostDlg  : public mol::win::Dialog
{
public:

	AccepHostDlg(const mol::string& host, int port, const mol::string& hash)
		: host_(host), port_(port), hash_(hash)
	{}

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				mol::ostringstream oss;
				oss << _T("Do you want to trust host ") << host_ << _T(" port ") << port_ << _T("?");
				setDlgItemText(IDC_STATIC_UNKNOWN_HOST_MSG,oss.str());
				setDlgItemText(IDC_EDIT_HOST_HASH,hash_);
				this->center();
				this->setForeGround();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					endDlg(LOWORD(wParam));
					return FALSE;
				}
				if (LOWORD(wParam) == IDCANCEL )
				{
					endDlg(LOWORD(wParam));
					return FALSE;
				}
			}
		}
		return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
	}

private:

	mol::string host_;
	int port_;
	mol::string hash_;
};



bool CredentialManager::acceptHost( mol::string host, long port, mol::string hash )
{
	AccepHostDlg dlg( mol::toString(host), port, mol::toString(hash) );

	LRESULT r = dlg.doModal( IDD_DIALOG_SSH_ACCEPT_HOST, ::GetDesktopWindow() );

	return r == IDOK;
}

bool CredentialManager::getCredentials( mol::string host, long port, mol::ssh::SecureCredentials** credentials)
{
	if(!credentials)
		return false;

	*credentials = 0;

	PwdDlg dlg( host, port );
	LRESULT r = dlg.doModal( IDD_SCP_PWD_DIALOG, ::GetDesktopWindow() );
	if ( r != IDOK )
	{
		return false;
	}
	
	mol::ssh::string user = mol::ssh::wstring2utf8(dlg.user.data(),dlg.user.size());
	mol::ssh::string pwd = mol::ssh::wstring2utf8(dlg.pwd.data(),dlg.pwd.size());

	*credentials = new mol::ssh::SecureCredentials(host,port,user,pwd);

	return true;
}

CredentialManager& credentialManager()
{
	return mol::singleton<CredentialManager>();
}
