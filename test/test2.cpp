//
// Created by clay on 23-2-21.
//

#include "../EventLoop.h"

netlib_muduo::EventLoop* p_loop;

void threadFunc()
{
    p_loop->loop();
}

int main()
{
    netlib_muduo::EventLoop loop;
    p_loop = &loop;
    muduo::Thread t(threadFunc);
    t.start();
    t.join();
    return 0;
}