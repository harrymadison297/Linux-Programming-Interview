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
Use system call:
<br/> `int sockfd = socket(domain, type, protocol)`
* domain : argument specifies the communication domain for the socket (AF_LOCAL, AF_INET, AF_INET6)
* type : argument specifies the socket type (SOCK_STREAM, SOCK_DGRAM)
* protocol : Protocol value for Internet Protocol(IP), which is 0. This is the same number that appears on the protocol field in the IP header of a packet.
* sockfd: socket descriptor, an integer (like a file handle)

### How to use a socket?
The `sockfd` is a file descriptor returned when create `socket()`.

![](/Assets/socket_flow.png)

Use `sockfd` to manage socket:
* `int bind( sockfd, *addr, addrlen)` : After the creation of the socket, the bind function binds the socket to the address and port number specified in addr
* `int listen( sockfd, backlog)` : Wait for the client connect. 
* `int connect( sockfd, *addr, addrlen)` : Connects the sockfd to the address specified by addr.
* `int new_socket = accept( sockfd, *addr, *addrlen)` : accept the first connection request in queue, create a new connected socket, return `sockfd` refer to that socket. Now, client and server are ready to tranfer data.

### Stream socket
Base-on TCP connection (reliable, connection-oriented)

### Datagram socket
Base-on UDP connection (unreliable, connectionless)

## Message queue

## Shared memory

## Memory mapping

## Signal

## Semaphore

## File lock

## Mutex (threads)

## Condition variable (threads)