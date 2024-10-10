# Interprocess communication
## Pipes and FIFOs

![](/Assets/pipe.png)
![](/Assets/pipe_flow.png)
### What is pipe?
* Pipe is a byte stream, couldn't randomly access the data in a pipe.
* Data can travel only in one direction through a pipe. One end of the pipe is used for writing, and the other end is used for reading.
* Pipe have a limited buffer. Once a pipe is full, writes to the pipe is block until the reader removes some data from pipe. 
### Creating and using pipes
### Pipes as method of process synchronization
### Using pipes to connect filters
### `popen()` : Talking to the shell
### Pipes and stdio buffering
### FIFOs
### Client-Server Application using FIFOs
### `read()` and `write()` on Pipes and FIFOs

## Socket
### What is socket?
Sockets are a method of IPC that allow data to be exchanged between applications, either on the same host (computer) or on different hosts connected by a network.
### How to create a socket?
### How to use a socket?
### Stream socket
### Datagram socket

## Message queue

## Shared memory

## Memory mapping

## Signal

## Semaphore

## File lock

## Mutex (threads)

## Condition variable (threads)