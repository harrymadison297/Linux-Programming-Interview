## Threads

### Definition
Like processes, threads are a mechanism to perform multiple tasks concurrently. 

A single process can contain multiple threads:
* Independently executing the same program
* Main thread is start when process start up
* Threads share the same global memory (initialized data, uninitialized data, and heap segments)
* Threads in a process can execute concurrently. If one thread is blocked on I/O, other threads are still eligible to execute

#### Why we need multi thread ?
* Speed up program and use CPU more efficiency
* Don’t need to wait time between independently code (eg: Allow CPU run multi task)

#### POSIX Thread?
POSIX (Portable Operating System Interface) is a family of standards specified by the IEEE Computer Society.

### Thread identify
Each thread within a process is uniquely identified by a thread ID (TID):
* To  identify the thread (using in function like pthread_join,…)
* Useful to tag dynamic data structures with the ID of a particular thread

### Thread creation
When a program is started, the resulting process consists of a single thread, called the initial or main thread 
#### How to create new thread?
Using `pthread_create( *thread, *attr, *(*start), *arg)` to create a new thread:
* __thread__: unique identifier for this thread (TID)
* __attr__: thread attribute
* __start__: function first call in this thread
* __arg__: argument for start

### Thread manage
Like process, can wait for the thread identified by thread_id to terminate by `pthread_join( thread_id, **retval)`

When the thread terminates without any join, it produces the thread equivalent of a zombie process.
Aside from wasting system resources, if enough thread zombies accumulate, we won’t be able to create additional threads.

Else, a thread can be detached by `pthread_detach( thread_id)`, it is no longer possible to use `pthread_join()` and the thread can’t be made joinable again. It automatically clean up and remove the thread when it terminates.

### Thread termination


### Compling thread
Use `-pthread` for compile

### Thread synchronization
#### Mutexes
Allow threads to synchronize their use of a shared resource, for example, one thread doesn’t try to access a shared variable at the same time as another thread is modifying it
#### Condition variables
Allow threads to inform each other that a shared variable (or other shared resource) has changed state
### Thread vs Process
| Process           |  Threads          |
|:-----------------:|:-----------------:|
|Independently, when parent die, chill still continue|Dependend on parent process. If parent die, child also stop|
|Use standalone memory, share only text segment in memory|Share memory with parent process. Can be share memory between threads in process|
|Difficult to share infomation between processes (must see IPC)|Easier because of using share memory|
|Process creation is expensive|Create threads is more easier|