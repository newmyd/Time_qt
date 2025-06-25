#include "thread.h"

Thread::Thread()
{
    //
}

void Thread::run()
{
    while(1)
    {
        emit returnResult(0);
        usleep(100);
    }
    return ;
}
