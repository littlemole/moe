#ifndef _MOE_DEF_TAIL_EDITOR_DEFINE_
#define _MOE_DEF_TAIL_EDITOR_DEFINE_

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

	static Instance* CreateInstance(const std::wstring& p);

	/////////////////////////////////////////////////////////////////////

	// std windows msgs

	void OnReload();
	LRESULT OnClose();

protected:

	virtual void OnFileChangeNotify(mol::io::DirMon*);
	void checkModifiedOnDisk( );
	void append(const std::wstring& path,unsigned long long size);

	bool initialize(const std::wstring& p);

	unsigned long long size_;

	mol::io::DirMon monitor_;
};

//////////////////////////////////////////////////////////////////////////////////


#endif
