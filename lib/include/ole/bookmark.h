#ifndef MOL_DEFINE_IE_FAVORITES_DEF_GUARD_
#define MOL_DEFINE_IE_FAVORITES_DEF_GUARD_

#include "win/shell.h"
#include <intshcut.h>

namespace mol {



/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class Bookmark
{
public:

	typedef std::vector<Bookmark>		BookMarkVector;
	typedef BookMarkVector::iterator	BookMarkIterator;

	Bookmark();
	Bookmark(const std::wstring& url, const std::wstring& title);
	~Bookmark();

	std::wstring url;
	std::wstring title;

	unsigned int size();
	Bookmark& item(unsigned int index);

	BookMarkIterator begin();
	BookMarkIterator end();

	static std::wstring getUrl( const std::wstring& uri );

	HMENU getMenu();
	Bookmark& getBookmarkFromMenuId(int id);
protected:

	static HMENU getMenu(Bookmark& parent, HMENU menu, int& id);
	static Bookmark& getBookmarkFromMenuId(Bookmark& parent,int id, int& c);

	void recurseFavs( LPITEMIDLIST favs, mol::io::ShellFolder& parentFolder );

	BookMarkVector bookmarks_;
};

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class Bookmarks : public Bookmark
{
public:

	Bookmarks();
	~Bookmarks();
};

/////////////////////////////////////////////////////////////////////////////////

inline Bookmark& bookmarks()
{
	return mol::singleton<Bookmarks>();
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

} //end namespace mol

#endif

