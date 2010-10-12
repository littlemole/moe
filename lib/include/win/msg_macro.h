#ifndef _MSG_MACRO_DEF_GUARD_DEFINE_
#define _MSG_MACRO_DEF_GUARD_DEFINE_


///////////////////////////////////////////////////////////////////
// msg handling 'attributes' for member functions
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
// handle a windows message
///////////////////////////////////////////////////////////////////

#define msg_handler(cmd,mfp)													\
class MsgHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	MsgHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addMsgHandler(														\
					cmd,														\
					make_handler(&ThisWindowType::##mfp ));						\
		return 0;																\
	}																			\
																				\
} msg_handler_##cmd##_##mfp ;											


#define msg_handler1(cmd,mfp,p1)												\
class MsgHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	MsgHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addMsgHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1 ));			\
		return 0;																\
	}																			\
																				\
} msg_handler_##cmd##_##mfp ;	



#define msg_handler2(cmd,mfp,p1,p2)											\
class MsgHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	MsgHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addMsgHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1,p2 ));		\
		return 0;																\
	}																			\
																				\
} msg_handler_##cmd##_##mfp ;	


///////////////////////////////////////////////////////////////////
// handle a WM_COMMAND message
///////////////////////////////////////////////////////////////////

#define cmd_handler(cmd,mfp)													\
class CmdHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	CmdHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_handler(&ThisWindowType::##mfp) );						\
		return 0;																\
	}																			\
																				\
} cmd_handler_##cmd##_##mfp ;	


#define cmd_handler1(cmd,mfp,p1)												\
class CmdHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	CmdHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1) );			\
		return 0;																\
	}																			\
																				\
} cmd_handler_##cmd##_##mfp ;	




#define cmd_handler2(cmd,mfp,p1,p2)												\
class CmdHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	CmdHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1,p2) );		\
		return 0;																\
	}																			\
																				\
} cmd_handler_##cmd##_##mfp ;

///////////////////////////////////////////////////////////////////
// handle a WM_COMMAND message and pass to corresponding method
// assumes a simple Method with no argumens
///////////////////////////////////////////////////////////////////

#define cmd_mem_handler(cmd,mfp)												\
	cmd_handler(cmd,On##mfp##cmd)												\
	LRESULT virtual On##mfp##cmd( UINT, WPARAM, LPARAM)							\
	{																			\
		mfp##();																\
		return 0;																\
	}

#define cmd_mem_handler1(cmd,mfp,p1)											\
	cmd_handler(cmd,On##mfp##cmd)												\
	LRESULT virtual On##mfp##cmd( UINT, WPARAM, LPARAM)							\
	{																			\
		mfp##(p1);																\
		return 0;																\
	}

#define cmd_mem_handler2(cmd,mfp,p1,p2)											\
	cmd_handler(cmd,On##mfp##cmd)												\
	LRESULT virtual On##mfp##cmd( UINT, WPARAM, LPARAM)							\
	{																			\
		mfp##(p1,p2);															\
		return 0;																\
	}

///////////////////////////////////////////////////////////////////
// handle several WM_COMMAND_MESSAGES
///////////////////////////////////////////////////////////////////


#define cmd_range_handler(i,j,mfp)													\
class CmdRangeHandler##i_##j##_##mfp##__	 										\
{																					\
public:																				\
																					\
	CmdRangeHandler##i_##j##_##mfp##__ ()											\
	{																				\
		static int x = init();														\
	}																				\
																					\
	static int init()																\
	{																				\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )										\
        {																			\
			mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(															\
					cmd, 															\
					make_handler(&ThisWindowType::##mfp) );							\
		}																			\
		return 0;																	\
	}																				\
																					\
} cmd_range_handler_##i##_##j##_##mfp ;	



#define make_cmd_range_handler(W,i,j,mfp)									\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addCmdHandler(												\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}



#define make_command_range_handler(W,i,j,mfp)								\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addCmdHandler(												\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}

///////////////////////////////////////////////////////////////////
// handle WM_Notify Message by Ctrl Id
///////////////////////////////////////////////////////////////////

#define notify_handler(cid,mfp)														\
class NotifyHandler##cid##mfp##__	 												\
{																					\
public:																				\
																					\
	NotifyHandler##cid##mfp##__ ()													\
	{																				\
		static int i = init();														\
	}																				\
																					\
	static int init()																\
	{																				\
		mol::msgMap<ThisWindowType>()												\
			.addNotifyIdHandler(													\
					cid,															\
					make_handler(&ThisWindowType::##mfp) );							\
		return 0;																	\
	}																				\
																					\
} notify_handler_##cid##_##mfp ;	



///////////////////////////////////////////////////////////////////
// handle WM_Notify Message by Notify Code
///////////////////////////////////////////////////////////////////

#define notify_code_handler(cmd,mfp)													\
class NotifyCodeHandler##cmd##mfp##__	 												\
{																						\
public:																					\
																						\
	NotifyCodeHandler##cmd##mfp##__ ()													\
	{																					\
		static int i = init();															\
	}																					\
																						\
	static int init()																	\
	{																					\
		mol::msgMap<ThisWindowType>()													\
			.addNotifyCodeHandler(														\
					cmd,																\
					make_handler(&ThisWindowType::##mfp) );								\
		return 0;																		\
	}																					\
																						\
} notify_code_handler_##cmd##_##mfp ;	


///////////////////////////////////////////////////////////////////
// handle WM_Notify Message by Ctrl id range
///////////////////////////////////////////////////////////////////

#define notify_range_handler(i,j,mfp)										\
class NotifyRangeHandler##i_##j##_##mfp##__	 								\
{																			\
public:																		\
																			\
	NotifyRangeHandler##i_##j##_##mfp##__ ()								\
	{																		\
		static int x = init();												\
	}																		\
																			\
	static int init()														\
	{																		\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<ThisWindowType>()									\
			.addNotifyHandler(												\
					cmd, 													\
					make_handler(&ThisWindowType::##mfp) );					\
		}																	\
		return 0;															\
	}																		\
																			\
} notify_range_handler_##i##_##j##_##mfp ;	


#define make_notify_range_handler(W,i,j,mfp)								\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addNotifyHandler(											\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}


#define make_notification_range_handler(W,i,j,mfp)							\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addNotifyHandler(											\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}

/////////////////////////////////////////////////////////////////
// auto insert CMD handler whitch forwards to a embedded OLE object
// calling specified interface and calling the specified Method
// the methods signature has to be HRESULT virtual __stdcall foo();
/////////////////////////////////////////////////////////////////

#define ole_cmd_handler(cmd,iface,method)										\
class OleCmdHandler##cmd##iface##method##__	 									\
{																				\
public:																			\
																				\
	OleCmdHandler##cmd##iface##method##__ ()									\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_ole_handler<ThisWindowType,iface>(&iface::##method) );	\
		return 0;																\
	}																			\
																				\
} ole_cmd_handler_##cmd##iface##_##method ;	



#endif



