#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CONTEXT_TYPE_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CONTEXT_TYPE_DEF_GUARD_

#include <typeinfo>

namespace mol {
namespace di  {

class Type
{
public:
	Type()
	{
		class Undef {};
		ti_ = &typeid(Undef);
	}

	Type(const std::type_info& ti)
		:ti_(&ti)
	{}

	Type(const Type& t)
		:ti_(t.ti_)
	{}

	Type& operator=(const Type& t)
	{
		ti_ = t.ti_;
	}

	bool before(const Type& t) const
	{
		return ti_->before(*t.ti_) != 0;
	}

    inline const std::type_info& get() const
	{
		return *ti_;
	}

	inline const char* name() const
	{
		return ti_->name();
	}

private:
	const std::type_info* ti_;
};


inline bool operator==(const Type& lhs, const Type& rhs)
{
	return (lhs.get() == rhs.get()) != 0;
}


inline bool operator!=(const Type& lhs, const Type& rhs)
{
	return (lhs.get() != rhs.get()) != 0;
}

inline bool operator<(const Type& lhs, const Type& rhs)
{
	return (lhs.before(rhs)) ;
}

inline bool operator>(const Type& lhs, const Type& rhs)
{
	return rhs < lhs;
}

inline bool operator<=(const Type& lhs, const Type& rhs)
{
	return !(lhs > rhs);
}

inline bool operator>=(const Type& lhs, const Type& rhs)
{
	return !(lhs < rhs);
}

////////////////////////////////////////////////////////////////////////

template<class T>
Type type()
{
	return Type(typeid(T));
}


template<class T>
class parse
{
public:
	static T string(const std::string& str)
	{
		T value;
		std::istringstream iss(str);
		iss >> value;
		return value;
	}
};


template<>
class parse<std::string>
{
public:
	static std::string string(const std::string& str)
	{
		return str;
	}
};

//////////////////////////////////////////////////////////////////////////////////


template<class T, class F>
void foreach( T& t, F f)
{
	std::for_each( t.begin(), t.end(), f);
}



template<class T, class F>
void foreach( const T& t, F f)
{
	std::for_each( t.cbegin(), t.cend(), f);
}

//////////////////////////////////////////////////////////////////////////////////

template<class T, class F>
bool loop_if( T& t, F f)
{
	auto it = std::find_if( t.begin(), t.end(), f);

	if ( it == t.end() ) {
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////

template<class T>
void clone( const std::list<T>& clonee, std::list<T>& clone )
{
	for( std::list<T>::const_iterator it = clonee.begin(); it != clonee.end(); it++)
	{
		clone.push_back( (*it)->clone() );
	}
}

template<class T>
std::vector<T>* clone( std::vector<T>* clonee )
{
	std::vector<T>* result = new std::vector<T>;
	for( std::vector<T>::const_iterator it = clonee->begin(); it != clonee->end(); it++)
	{
		result->push_back( (*it)->clone() );
	}
	return result;
}

template<class K, class V>
std::map<K,V>* clone( std::map<K,V>* clonee )
{
	std::map<K,V>* result = new std::map<K,V>;
	for( std::map<K,V>::const_iterator it = clonee->begin(); it != clonee->end(); it++)
	{
		result->insert( std::make_pair( (*it).first, (*it).second->clone() ) );
	}
	return result;
}


/*
//////////////////////////////////////////////////////////////////////////////////

template<class T>
class Factory : public ComponentFactory
{
public:

	virtual typename mol::di::Component<T>::Ptr component(mol::di::Context* ctx) = 0;
};

*/

//////////////////////////////////////////////////////////////////////////////////



class ContextEx
{
public:
	explicit ContextEx(const std::string& msg)
		:msg_(msg)
	{}

	const char* msg()
	{
		return msg_.c_str();
	}

private:
	std::string msg_;
};


class ContextBuilderEx : public ContextEx
{
public:
	explicit ContextBuilderEx(const std::string& msg)
		:ContextEx(msg)
	{}
};

///////////////////////////////////////////////////////////

} // end namespace mol 
} // end namespace di  


#endif 