#include "util/x.h"
#include "thread/signal.h"

#ifndef WIN32
#include <pthread.h>

void signaling(int SigType, void(*h)(int)  )
{
  struct sigaction handler;

  handler.sa_handler = h;

  //create mask
  if ( sigfillset( &handler.sa_mask) < 0 )
     throw mol::X( "error setting signal mask");

  //set signal handling
  if ( sigaction( SigType, &handler,0 ) < 0 )
     throw mol::X ( "error setting signal handling" );
}

#endif

