#ifndef MOL_LIB_TYPELIB_DEF_GUARD_DEFINE_
#define MOL_LIB_TYPELIB_DEF_GUARD_DEFINE_

#include "ole/punk.h"

namespace mol {

HRESULT typeLibForInterface(REFIID iid, ITypeLib** typelib );
HRESULT typeInfoForInterface(REFIID iid, ITypeInfo** typeinfo );


//////////////////////////////////////////////////////////////////////
// ITypeLib wrapper
//////////////////////////////////////////////////////////////////////

class TypeLib : public punk<ITypeLib>
{
public:

	virtual ~TypeLib() {}

	bool load();
	bool load(const std::wstring& lib);
	bool load(REFGUID libid,int major=1,int minor=1);
	bool registerTypelib();
    bool unRegisterTypelib();

	GUID getGUID();
	std::wstring getName();
	std::wstring getDescription();

	unsigned short major() { return major_; }
	unsigned short minor() { return minor_; }

	int typeInfoCount();
	HRESULT item( unsigned int index, ITypeInfo** ti );
	HRESULT item( REFGUID guid, ITypeInfo** ti );

	std::wstring getName(int index);
	std::wstring getDescription(int index);
	TYPEKIND typeKind( int index);
	GUID getGUID( int index);

protected:

	GUID			guid_;
	int				count_;
	unsigned short	major_;
	unsigned short	minor_;
};

} // end namespace mol

#endif

