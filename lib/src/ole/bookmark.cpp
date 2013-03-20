#include "ole/bookmark.h"
#include "win/res.h"
/////////////////////////////////////////////////////////////////////////////////

namespace mol {

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

Bookmark::Bookmark()
{}

Bookmark::Bookmark(const mol::string& u, const mol::string& t)
{
	url   = u;
	title = t;
}

Bookmark::~Bookmark()
{}

unsigned int Bookmark::size()
{
	return (unsigned int)bookmarks_.size();
}

Bookmark& Bookmark::item(unsigned int index)
{
	return bookmarks_.at(index);
}

Bookmark::BookMarkIterator Bookmark::begin()
{
	return bookmarks_.begin();
}

Bookmark::BookMarkIterator Bookmark::end()
{
	return bookmarks_.end();
}

HMENU Bookmark::getMenu()
{
	int id = 10000;
	mol::Menu menu;
	menu.createContext();
	menu.detach();
	getMenu(*this,menu,id);
	return menu;
}

Bookmark& Bookmark::getBookmarkFromMenuId(int id)
{
	int c = 10000;
	return getBookmarkFromMenuId(*this,id,c);
}

HMENU Bookmark::getMenu(Bookmark& parent, HMENU menu, int& id)
{
	mol::Menu m;
	m.attach(menu,false);

	for ( unsigned int i = 0; i < parent.size(); i++ )
	{
		Bookmark& bm = parent.item(i);
		
		if ( bm.size() > 0 )
		{
			mol::Menu sub;
			sub.create();
			sub.detach();
			m.addSubmenu( sub, bm.title );
			getMenu( bm, sub, id );
		}
		else
		{
			if ( bm.url != _T("") )
			{
				m.addItem( id, bm.title );
				id++;
			}
		}
	}
	return m;
}

Bookmark& Bookmark::getBookmarkFromMenuId(Bookmark& parent,int id, int& c)
{
	static Bookmark notUsedNeverReached;

	for ( unsigned int i = 0; i < parent.size(); i++ )
	{
		Bookmark& bm = parent.item(i);

		if ( bm.size() > 0 )
		{
			Bookmark& b = getBookmarkFromMenuId( bm, id, c );
			if ( &b != &notUsedNeverReached )
				return b;
		}
		else
		{
			if ( c == id )
				return bm;
			c++;
		}
	}
	
	return notUsedNeverReached;
}

/////////////////////////////////////////////////////////////////////////////////

void Bookmark::recurseFavs( LPITEMIDLIST favs, mol::io::ShellFolder& parentFolder )
{
	mol::io::ShellFolder folder(favs,parentFolder);

	if(!folder)
		return;

	if ( S_OK == folder.enumObjects(0,SHCONTF_FOLDERS|SHCONTF_NONFOLDERS) )
	while ( mol::io::Shit s = folder.next(0) )
	{
		mol::string title = folder.getDisplayNameOf(*s,SHGDN_NORMAL);
		mol::string uri   = folder.getDisplayNameOf(*s,SHGDN_FORPARSING);
		mol::string url   = getUrl(uri);

		mol::Bookmark bm(url,title);
		//if ( s->isDir() )  // VISTA?
		{
			bm.recurseFavs( *s, folder );
		}
		bookmarks_.push_back( bm );
	}
}

/////////////////////////////////////////////////////////////////////////////////

mol::string Bookmark::getUrl( const mol::string& uri )
{
	mol::punk<IUniformResourceLocator> url;
	url.createObject(CLSID_InternetShortcut);

	mol::CoStrBuf c;

	mol::string ret;
	if (url)
	{
		mol::punk<IPersistFile> pfile(url);
		if ( pfile )
		{
			std::wstring ws = mol::towstring(uri);

			HRESULT hr = pfile->Load(ws.c_str(), STGM_READ);
			if ( hr == S_OK )
			{
				hr = url->GetURL(&c);
				if ( hr == S_OK )
				{
					ret = mol::toString(c);
				}
			}
		}
	}
	return ret;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

Bookmarks::Bookmarks()
{
	mol::io::Shit favs = mol::io::desktop().getSpecialFolder( CSIDL_FAVORITES );

	mol::io::ShellFolder folder(*favs);

	recurseFavs( *favs, mol::io::desktop() );
}

Bookmarks::~Bookmarks()
{

}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

} //end namespace mol