#ifndef MUDUO_BASE_EVENTLOOP_H
#define MUDUO_BASE_EVENTLOOP_H

#include <muduo/base/Thread.h>
#include <muduo/base/Logging.h>

namespace netlib_muduo
{

class EventLoop 
{
public:
    // noncopyable
    EventLoop(EventLoop&) = delete;
    EventLoop& operator=(EventLoop&) = delete;

    EventLoop();
    ~EventLoop();

    void loop();

    void assertInLoopThread()
    {
        if(!isInLoopThread()) {
            abortNotInLoopThread();
        }
    }

    bool isInLoopThread() const { return threadId_ == muduo::CurrentThread::tid(); }

    static EventLoop* getEventLoopOfCurrentThread();
private:
    void abortNotInLoopThread();

    bool looping_;
    const pid_t threadId_;
};

}

#endif