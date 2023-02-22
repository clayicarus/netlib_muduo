#include "EventLoop.h"
#include <poll.h>
#include <assert.h>

using namespace netlib_muduo;

__thread EventLoop *t_loopInThisThread = nullptr;

EventLoop::EventLoop()
    : looping_(false), threadId_(muduo::CurrentThread::tid())
{
    LOG_TRACE << "EventLoop created " << this << " in thread " << threadId_;
    if(t_loopInThisThread) {
        LOG_FATAL << "Another EventLoop " << t_loopInThisThread
                  << " exists in this thread " << threadId_;
    } else {
        t_loopInThisThread = this;
    }
}

EventLoop::~EventLoop() 
{
    assert(!looping_);  // definitely not null
    t_loopInThisThread = nullptr;
}

EventLoop* EventLoop::getEventLoopOfCurrentThread()
{
    return t_loopInThisThread;
}

void EventLoop::loop()
{
    assert(!looping_);
    assertInLoopThread();
    looping_ = true;

    ::poll(NULL, 0, 5*1000);

    LOG_TRACE << "EventLoop " << this << " stop looping";    looping_ = false;
}

void EventLoop::abortNotInLoopThread()
{
    LOG_FATAL << "EventLoop::abortNotInLoopThread - EventLoop " << this
              << " was created in threadId_ = " << threadId_
              << ", current thread id = " <<  muduo::CurrentThread::tid();
}