#pragma once

#include "thread/sync.h"
#include <list>

///////////////////////////////////////////////////////////////////////////
//
// RefPtr - a reference counted pointer
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// helpers for RefPtr
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// MemPool implements helpers to implement
// class specific operator new and delete
// for fast small object allocation
///////////////////////////////////////////////////////////////////////////

namespace mol {

template<class T, unsigned int C=512>
class MemPool
{
public:
    void* alloc(size_t n)
    {
        if ( n != sizeof(T) )
            return ::operator new(n);

        if ( free_list_.size() > 0 )
        {
            T* t = free_list_.front();
            free_list_.pop_front();
            return t;
        }
        T* t = (T*) ::operator new( C * n );
        for ( unsigned int i = 1; i < C; ++i )
        {
            free_list_.push_back( &t[i] );
        }
        return (void*)t;
    }

    void free(void* p, size_t n)
    {
        if ( p == 0 )
            return;

        if ( n != sizeof(T) )
        {
           ::operator delete (p);
           return;
        }

        free_list_.push_front((T*)p);
    }

private:
    std::list<T*>       free_list_;
};

///////////////////////////////////////////////////////////////////////////
// MACRO hack to inject small object allocation
// into class definition
//
///////////////////////////////////////////////////////////////////////////

#define MOL_MEMPOOLED(T,C)                                      \
    static void* operator new(size_t size)                      \
    {                                                           \
        return pool().alloc(size);                              \
    }                                                           \
                                                                \
    static void operator delete(void* p, size_t size)           \
    {                                                           \
        return pool().free(p,size);                             \
    }                                                           \
                                                                \
protected:                                                      \
    static mol::MemPool<T,C>& pool()                            \
    {                                                           \
        static mol::MemPool<T,C>            p;                  \
        return p;                                               \
    }                                                           

///////////////////////////////////////////////////////////////////////////
// template to derive from to add small object allocation
///////////////////////////////////////////////////////////////////////////

template<class T, int C>
class MemPooled 
{
public:
    static void* operator new(size_t size)                      
    {                                                           
        return pool().alloc(size);                              
    }                                                           
                                                                
    static void operator delete(void* p, size_t size)           
    {                                                           
        return pool().free(p,size);                             
    }                                                           
                                                                
protected:                                                      
    static mol::MemPool<T,C>& pool()                                 
    {                                                           
        static mol::MemPool<T,C>            p;                               
        return p;                                               
    }     
};

///////////////////////////////////////////////////////////////////////////
// Policies for RefPtr
///////////////////////////////////////////////////////////////////////////

// destruction policies

///////////////////////////////////////////////////////////////////////////
// destruction policy for objects
///////////////////////////////////////////////////////////////////////////

class SimpleObjectPolicy
{
public:
    template<class T>
    static void release(T& t)
    {
        if ( t.count_ )
            delete t.count_;
        t.count_ = 0;

        if ( t.t_ )
            delete t.t_;
        t.t_ = 0;
    }
};

///////////////////////////////////////////////////////////////////////////
// destruction policy for arrays
///////////////////////////////////////////////////////////////////////////

class ArrayObjectPolicy
{
public:
    template<class T>
    static void release(T& t)
    {
        if ( t.count_ )
            delete[] t.count_;
        t.count_ = 0;

        if ( t.t_ )
            delete t.t_;
        t.t_ = 0;
    }

};

// threading policies

///////////////////////////////////////////////////////////////////////////
// single thread policy
///////////////////////////////////////////////////////////////////////////

template<class P=SimpleObjectPolicy>
class SingleThreadPolicy
{
public:
    typedef P Policy; 
    template<class T>
    static void increment(T& t)
    {
        if ( t.count_ )
            (*(t.count_))++;
    }

    template<class T>
    static void decrement(T& t)
    {
        if ( t.count_ )
        {
            (*(t.count_)).i--;
            if ( (*(t.count_)).i < 1)
            {
                release(t);
            }
        }
    }

    template<class T>
    static void release(T& t)
    {
        P::release(t);
    }

    template<class T>
    static void init(T& t)
    {
        if ( t.t_ )
            t.count_ = new mol::RefPtr<T::Type,SingleThreadPolicy<P> >::Count(1);
    }
};

///////////////////////////////////////////////////////////////////////////
// multithread policy
///////////////////////////////////////////////////////////////////////////

template<class P=SimpleObjectPolicy>
class MultiThreadPolicy
{
public:
    typedef P Policy; 

    template<class T>
    static void increment(T& t)
    {
        LOCK(t.p_.cs_);
        if ( t.count_ )
            (t.count_->i)++;
    }

    template<class T>
    static void decrement(T& t)
    {
        LOCK(t.p_.cs_);
        if ( t.count_ )
        {
            (t.count_->i)--;
            if ( t.count_->i < 1)
            {
                release(t);
            }
        }
    }

    template<class T>
    static void release(T& t)
    {
        P::release(t);
    }

    template<class T>
    static void init(T& t)
    {
        LOCK(t.p_.cs_);
        if ( t.t_ )
            t.count_ = new mol::RefPtr<T::Type,MultiThreadPolicy<P> >::Count(1);
    }

private:
    mol::CriticalSection cs_;
};

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// Ref counted pointer of type T, with threading and destruction policy
///////////////////////////////////////////////////////////////////////////

template<class T, class P=MultiThreadPolicy<SimpleObjectPolicy>, int C = 512 >
class RefPtr 
{
friend typename P;
friend typename P::Policy; 
public:
    typedef T Type; 
    RefPtr()
    {
        count_ = 0;
        t_     = 0;
    }
   
    RefPtr( const RefPtr& ref )
    {
        count_ = 0;
        t_     = ref.t_;
        if ( t_ )
        {
            count_ = ref.count_;
            P::increment(*this);
        }
    }

    RefPtr( const T* t )
    {
        count_ = 0;
        t_ = (T*)t;
        if ( t_)
            P::init(*this);
    }

    virtual ~RefPtr()
    {
        if ( t_ )
            P::decrement(*this);
    }

    RefPtr& operator=(const RefPtr& ref)
    {
        if ( t_ )
            P::decrement(*this);
        count_ = 0;
        t_     = ref.t_;
        if ( t_ )
        {
            count_ = ref.count_;
            P::increment(*this);
        }
        return *this;
    }

    RefPtr& operator=(const T* t) 
    {
        if ( t_ )
            P::decrement(*this);

        count_ = 0;

        t_     = (T*)t;
        if ( t_ )
            P::init(*this);

        return *this;
    }

    operator bool() const
    {
        return (t_ != 0);
    }

    T*& operator->() 
    {
        return t_;
    }

    T& operator*() 
    {
        return *t_;
    }

    // make inheritance avail - hui!what a hack!
    template<class U>
    operator mol::RefPtr<U,P>&()
    {
        return *((mol::RefPtr<U,P>*)(this));        
    }

private:
    T*                  t_;         // raw pointer we ref count
    P                   p_;         // policy instance - zero class for single, critical section for multihread policy

    // small object allocated class for counting
    class Count : public mol::MemPooled<Count,C>
    {
    public:
        Count(unsigned int x) : i(x) {}
        unsigned int i;
        operator int () { return i; };
        int operator++(int) { i++; return i; };
        int operator--(int) { i--; return i; };
    };

    Count*              count_;     // the shared ref count
};

// helper macros

#define MOL_REFPTR(T)   RefPtr<T,MultiThreadPolicy<SimpleObjectPolicy> >
#define MOL_AREFPTR(T)  RefPtr<T,MultiThreadPolicy<ArrayObjectPolicy> >
#define MOL_SREFPTR(T)  RefPtr<T,SingleThreadPolicy<SimpleObjectPolicy> >
#define MOL_SAREFPTR(T) RefPtr<T,SingleThreadPolicy<ArrayObjectPolicy> >

class RefChar : public mol::MemPooled<RefChar,512>
{
public:
        RefChar(const char* s) : c(0) 
        {
            int len = strlen(s)+1;
            c = new char(len);
            memcpy((char*)c,s,len);
        }

        RefChar(const std::string& s) : c(0) 
        {
            int len = s.size()+1;
            c = new char(len);
			memcpy((char*)c,s.c_str(),len);
        }

        virtual ~RefChar()
        {
            if (c)
                delete c;
        }

        const char* c;
        operator const char* () { return c; };
};

typedef mol::RefPtr<RefChar> Char;

} // end namespace mol