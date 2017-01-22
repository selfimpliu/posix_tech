#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>


// int open(const char *pathname, int flags);
int jjl_open(const char *pathname, int flags);

// int close(int fd);
void jjl_close(int fd);

// int socket(int domain, int type, int protocol);
int jjl_socket(int domain, int type, int porotocol);

// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void jjl_bind(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen);

// int listen(int sockfd, int backlog);
void jjl_listen(int sockfd, int backlog);

// int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int jjl_accept(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen);

// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int jjl_connect(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen);
