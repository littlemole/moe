#ifndef _MOL_DEF_GUARD_DEFINE_SCP_CLIENT_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_SCP_CLIENT_DEF_GUARD_

#include "ssh.h"

struct ssh_session_struct;
struct ssh_scp_struct;

namespace mol {
namespace scp {

class Session
{
public:

	Session();
	Session(ssh_session_struct* session);
	~Session();
	void dispose();

	void open( int mode, const std::wstring& path );
	void open( ssh_session_struct* session, int mode, const std::wstring& path );
	bool enter_dir(  const std::wstring& dir, int mode );
	bool leave_dir();

	bool push_dir(  const std::wstring& localdir, int mode );
	bool push_file( const std::wstring& file, const std::string& content, int mode );
	bool push_file( const std::wstring& path, int mode );

	bool pull_file( const std::wstring& localdir);
	bool read_file( std::string& content);
	bool pull_dir( const std::wstring& localdir);

	operator ssh_scp_struct*()
	{
		return scp_;
	}
private:

	 ssh_session_struct* ssh_;
	 ssh_scp_struct* scp_;
};



} // end namespace scp
} // end namespace mol

#endif