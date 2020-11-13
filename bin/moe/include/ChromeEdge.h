#ifndef _MOL_DEF_DEFINE_GUARD_CHROME_EDGE_DEFINE_
#define _MOL_DEF_DEFINE_GUARD_CHROME_EDGE_DEFINE_

#include "WebView2.h"


template<class I, class ... Args>
class SimpleCallBack : public I,
	public mol::interfaces< SimpleCallBack<I, Args...>, mol::implements< IUnknown, I> >

{
public:

	using callback = std::function<void(Args...)>;

	void dispose()
	{}

protected:
	callback cb_;
};

template<class I, class ... Args>
class Callback : public SimpleCallBack<I, Args...>
{
public:

	using Instance = mol::com_obj<Callback<I, Args...>>;

	static mol::punk<I> CreateInstance(callback cb)
	{
		Instance* i = new Instance();
		mol::punk<I> pun(i);
		i->cb_ = cb;
		return pun;
	}

	HRESULT __stdcall Invoke(Args... args)
	{
		cb_(args...);
		return S_OK;
	}
};



template<class I, class T>
struct CallbackMaker;

template<class I, class R, class T, class ... Args>
struct CallbackMaker<I, R(T::*)(Args...) const>
{
	template<class L>
	static auto make(L lambda)
	{
		return Callback<I, Args...>::CreateInstance(lambda);
	}
};

template<class I, class R, class T, class ... Args>
struct CallbackMaker<I, R(T::*)(Args...)>
{
	template<class L>
	static auto make(L lambda)
	{
		return Callback<I, Args...>::CreateInstance(lambda);
	}
};


template<class I, class L>
auto make_callback(L lambda)
{
	using type = decltype(&L::operator());
	return CallbackMaker<I, type>::make(lambda);
}




class WebViewControllerCallback :
	public SimpleCallBack< ICoreWebView2CreateCoreWebView2ControllerCompletedHandler, HRESULT, ICoreWebView2Controller*>
{
private:
	HWND hWnd_;
public:

	using Instance = mol::com_obj<WebViewControllerCallback>;

	static mol::punk<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler> CreateInstance(HWND hWnd, callback cb)
	{
		Instance* i = new Instance();
		mol::punk<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler> pun(i);
		i->hWnd_ = hWnd;
		i->cb_ = cb;
		return i;
	}

	HRESULT __stdcall Invoke(HRESULT hr, ICoreWebView2Controller* controller)
	{
		RECT bounds;
		GetClientRect(hWnd_, &bounds);
		controller->put_Bounds(bounds);
		cb_(hr, controller);
		return S_OK;
	}
};

class ChromeEdge : public ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler,
	public mol::interfaces< ChromeEdge, mol::implements< IUnknown, ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler> >
{
private:
	mol::punk<ICoreWebView2Environment> chromeEnv_;

	using callback = std::function<void(HRESULT, ICoreWebView2Controller*)>;
	using closure = std::pair<HWND, callback>;
	std::list<closure> callbacks_;

public:

	std::wstring userdata;
	std::wstring chromeFolder;

	ChromeEdge()
	{
		userdata = mol::app<mol::win::AppBase>().CreateAppPath(_T("moe"));
		//use static runtime
		//chromeFolder = L"C:\\moe\\bin\\moe\\webview2\\Microsoft.WebView2.FixedVersionRuntime.87.0.664.8.x64";
	}

	~ChromeEdge()
	{}

	typedef mol::com_obj<ChromeEdge> Instance;

	static mol::punk< ChromeEdge> CreateInstance()
	{
		Instance* i = new Instance();
		mol::punk< ChromeEdge> pun(i);
		return pun;
	}

	void dispose()
	{

	}

	void createWebView(HWND hWnd, std::function<void(HRESULT, ICoreWebView2Controller*)> cb)
	{
		if (chromeEnv_)
		{
			auto cc = WebViewControllerCallback::CreateInstance(hWnd, cb);
			chromeEnv_->CreateCoreWebView2Controller(hWnd, cc);
			return;
		}

		callbacks_.push_back(std::make_pair(hWnd, cb));
		HRESULT hr = CreateCoreWebView2EnvironmentWithOptions(chromeFolder.c_str(), userdata.c_str(), nullptr, this);

	}


	HRESULT __stdcall Invoke(HRESULT, ICoreWebView2Environment* env)
	{
		chromeEnv_ = env;
		for (auto it = callbacks_.begin(); it != callbacks_.end(); it++)
		{
			auto cc = WebViewControllerCallback::CreateInstance((*it).first, (*it).second);
			env->CreateCoreWebView2Controller((*it).first, cc);
		}
		callbacks_.clear();
		return S_OK;
	};

};

#endif
