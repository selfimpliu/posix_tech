#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>

int jjl_socket(int domain, int type, int protocol);

void jjl_bind(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen);

void jjl_listen(int sockfd, int backlog);

int jjl_accept(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen);

void jjl_connect(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen);

void jjl_close(int fd);

void jjl_servaddr_config(struct sockaddr_in addr);
