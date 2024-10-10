# Linux Programming interview

## Books
[Advanced Linux Programming.pdf](/Books/Advanced%20Linux%20Programming.pdf)

[The Linux Programming Interface.pdf](/Books/The%20Linux%20Programming%20Interface.pdf)

[Understanding Linux Kernel.pdf](/Books/Understanding%20Linux%20Kernel.pdf)

## Linux covered topics
1. Process <i>[Read here](/QA/Process.md)</i>
    * Process definition
      * PID, PPID
      * Command line argument
      * Envinronment
    * Who can access to a process (Process credentials)
      * UIDs and GIDs
      * File-system user permissions
      * Interface
    * Process creation
      * `folk()`
      * File access when folk a new process
      * Memory semantics
      * Race condition
    * Child process monitor
      * `wait( *status)`
      * `waitpid( pid, *status, options)`
      * Orphan process and zombie process
    * Program execution
      * `execve( path, argv, envp )`
      * Run a shell command `system( *command)`
    * Process priorities and scheduler
      * `getpriority( which, who)`
      * `setpriority( which, who)`
      * Realtime scheduling
    * Process memory and resource
        
		![](/Assets/Memory_layout.png)
      * Process infomation in file system (`/proc`)
    * Process termination
      * `exit(status)`
      * Exit handlers `atexit(void (*func)(void))`, `on_exit()`
      * Termination flow
    * Daemon process
      * Definition
      * How to create a daemon process
2. Threads <i>[Read here](/QA/Thread.md)</i>
    * Definition
  
        ![](/Assets/Thread_memory_layout.png)
    * Thread identify
      * `pthread_self()`
      * `pthread_equal( thread_id_1, thread_id_2)`
    * Thread creation
      * `pthread_create( *thread, *attr, *(*start), *arg)`
    * Thread manage
      * `pthread_join( thread, **retval)`
      * `pthread_detach( thread)`
    * Thread termination
      * `pthread_exit( *retval)`
    * Compling thread
      * `-pthread`
    * Thread synchronization
      * Mutexes
      * Condition variables
3. Inter-Process Communication <i>[Read here](/QA/IPC.md)</i>
   
    ![](/Assets/ipc.png)
4. File System Management <i>[Read here](/QA/FileSystem.md)</i>
5. Memory <i>[Read here](/QA/Memory.md)</i>
6. Networking <i>[Read here](/QA/Networking.md)</i>
7. Other <i>[Read here](/QA/Other.md)</i>
    * Serial communication
      * UART
      * SPI
      * I2C
      * USB
    * Wireless communication
      * Wifi
      * BLE
      * Zigbee