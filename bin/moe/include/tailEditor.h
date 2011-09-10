#ifndef _MOE_DEF_TAIL_EDITOR_DEFINE_
#define _MOE_DEF_TAIL_EDITOR_DEFINE_

#include "shared.h"
#include "resource.h"
#include "editor.h"

//////////////////////////////////////////////////////////////////////////////////
// FormEditor Wnd
//////////////////////////////////////////////////////////////////////////////////

class TailEditor 
	: 
	public mol::MdiChildFrame<TailEditor,Editor>
{
public:

	typedef mol::com_instance<TailEditor> Instance;

	TailEditor();
	virtual ~TailEditor();

	static Instance* CreateInstance(const mol::string& p);

	/////////////////////////////////////////////////////////////////////

	// std windows msgs

	void OnMDIActivate(WPARAM unused,HWND activated);
	void OnNcDestroy();
	void OnDestroy();
	void OnReload();

protected:

	virtual void OnFileChangeNotify(mol::io::DirMon*);
	void checkModifiedOnDisk( );
	void append(const mol::string& path,unsigned long long size);

	bool initialize(const mol::string& p);

	unsigned long long size_;
};

//////////////////////////////////////////////////////////////////////////////////


#endif