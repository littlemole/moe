#ifndef MOL_LIB_STREAM_DEF_GUARD_DEFINE_
#define MOL_LIB_STREAM_DEF_GUARD_DEFINE_

#include "ole/punk.h"


namespace mol {


//////////////////////////////////////////////////////////////////////
// IStream
//////////////////////////////////////////////////////////////////////

class Stream : public punk<IStream>
{
public:
    Stream();							
    Stream( IUnknown* iUnknown);
    Stream( punk<IStream>& iUnknown );	
    virtual ~Stream();		
    Stream& operator=( Stream& c );

	Stream(HGLOBAL glob);
	Stream(const char* data , size_t size = 0, int opt = GMEM_MOVEABLE | GMEM_NODISCARD );

	HGLOBAL global();
	std::string toString();

	HRESULT create();
	HRESULT create(HGLOBAL glob);
	HRESULT create(const char* data , size_t size = 0, int opt = GMEM_MOVEABLE | GMEM_NODISCARD );
	HRESULT create(IStream** pStream, const mol::string& path, DWORD flags = STGM_READWRITE | STGM_SHARE_DENY_WRITE | STGM_CREATE);

	HRESULT reset();

	static HGLOBAL Global(IStream* str);
	static std::string ToString(IStream* stream);

	static HRESULT Create(IStream** pStream);
	static HRESULT Create(IStream** pStream, HGLOBAL glob);
	static HRESULT Create(IStream** pStream, const char* data , size_t size = 0, int opt = GMEM_MOVEABLE | GMEM_NODISCARD );
	static HRESULT Create(IStream** pStream, const mol::string& path, DWORD flags = STGM_READWRITE | STGM_SHARE_DENY_WRITE | STGM_CREATE );

	HRESULT copyTo( IStream* pStream );
	HRESULT copyFrom( IStream* pStream );

	REFCLSID clsid();
	bool clsid( REFCLSID clsid);

private:
	CLSID clsid_;
};

} // end namespace mol

#endif