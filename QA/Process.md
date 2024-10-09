## Process in Linux

### Process definition
1. **What is process?**
   
   Process is an instance of an executing program.
From the kernel’s point of view, a process consists of:
   * User-space memory containing program code and variables used by that code
   * Identify: PID, PPID, UID, GID, session, ..
   * Memory: Virtual memory tables
   * Infomation resource: file descriptors, signal, current working directory,...
