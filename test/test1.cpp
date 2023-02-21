#include <iostream>
#include "../EventLoop.h"

void threadFunc()
{
    printf("threadFunc(): pid = %d, tid = %d\n", getpid(), muduo::CurrentThread::tid());

    netlib_muduo::EventLoop loop;
    netlib_muduo::EventLoop::getEventLoopOfCurrentThread()->loop();
}

int main()
{
    printf("main(): pid = %d, tid = %d\n", getpid(), muduo::CurrentThread::tid());
    netlib_muduo::EventLoop eventLoop;

    muduo::Thread t1(threadFunc);
    t1.start();

    eventLoop.loop();
    return 0;
}
