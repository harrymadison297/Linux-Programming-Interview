#include "include/sock_com.h"

/* 
@brief Initial local socket 
@eg: int sockfd_local = sock_server_init_local("/tmp/server_sock", 100);
*/
int sock_server_init_local(const char * sockpath, int max_connection)
{
    struct sockaddr_un local_sockaddr;

    /* Create local socket */
    int sockfd_local = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (sockfd_local < 0)
        errExit("Couldn't create local socket!");

    /* Clean old local socket */
    if (remove(sockpath) == -1 && errno != ENOENT)
        errExit("Couldn't remove old local socket");

    /* Binding local address */
    memset(&local_sockaddr, 0, sizeof(struct sockaddr_un));
    local_sockaddr.sun_family = AF_LOCAL;
    strncpy(local_sockaddr.sun_path, sockpath, sizeof(local_sockaddr.sun_path) - 1);
    if(bind(sockfd_local, (struct sockaddr *) &local_sockaddr,  sizeof(struct sockaddr_un)) == -1)
        errExit("Couldn't bind");

    /* Listening on local address */
    if (listen(sockfd_local, max_connection) == -1)
        errExit("Couldn't listen on local socket");

    return sockfd_local;
}

int sock_client_init_local(const char * sockpath)
{
    struct sockaddr_un addr;
    /* Create client socket */
    int client_sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);       
    if (client_sockfd == -1)
        errExit("Couldn't create socket");

    /* Construct server address, and make the connection */
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, sockpath, sizeof(addr.sun_path) - 1);
    if (connect(client_sockfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
        errExit("Couldn't connect!");
    
    return client_sockfd;
}