#ifndef CSIGNAL_DEFINE
#define CSIGNAL_DEFINE

#ifndef WIN32
#include <signal.h>

void signaling(int SigType, void(*h)(int)  );

#endif

#endif
