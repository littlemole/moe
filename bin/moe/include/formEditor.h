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

	LRESULT OnMDIActivate(WPARAM unused,HWND activated);
	LRESULT OnDestroy();

	LRESULT OnSaveAs();
	LRESULT OnSave();
    void OnReload();

	LRESULT OnExecScript();
	LRESULT OnDebugScript();
	LRESULT OnExecForm(  );

protected:

	bool initialize(const mol::string& p);


};

//////////////////////////////////////////////////////////////////////////////////


#endif




