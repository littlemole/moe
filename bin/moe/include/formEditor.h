#ifndef _MOE_DEF_FORMEDITOR_DEFINE_
#define _MOE_DEF_FORMEDITOR_DEFINE_

#include "shared.h"
#include "resource.h"
#include "editor.h"
#include "UserForm.h"

//////////////////////////////////////////////////////////////////////////////////
// FormEditor Wnd
//////////////////////////////////////////////////////////////////////////////////

class FormEditor 
	: 
	public mol::MdiChildFrame<FormEditor,Editor>
{
public:

	mol::punk<UserForm::Instance> userForm;

	typedef mol::com_instance<FormEditor> Instance;

	FormEditor();
	virtual ~FormEditor();

	static Instance* CreateInstance(const mol::string& p);

	/////////////////////////////////////////////////////////////////////

	// std windows msgs

	void OnMDIActivate(WPARAM unused,HWND activated);
	void OnNcDestroy();
	void OnDestroy();

	LRESULT OnSaveAs();
	LRESULT OnSave();
    void OnReload();

	LRESULT OnExecScript();
	LRESULT OnDebugScript();
	LRESULT OnExecForm(  );

protected:

	virtual void OnFileChangeNotify(mol::io::DirMon*);
	void checkModifiedOnDisk(const mol::string& path);

	bool initialize(const mol::string& p);

};

//////////////////////////////////////////////////////////////////////////////////


#endif




