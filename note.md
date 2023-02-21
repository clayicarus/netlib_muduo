## 什么也不做的EventLoop

### one loop per thread

- 不同的线程有不同的tid

  在构造时判断static变量是否为0即可，为0时则设置为该线程的tid。



### loop只能由构造线程执行，不能由别的线程执行

- 判断该线程的tid是否等于记录的tid即可



