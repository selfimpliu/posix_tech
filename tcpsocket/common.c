#include "common.h"


// int open(const char *pathname, int flags);
int jjl_open(const char *pathname, int flags)
{
	int res = open(pathname, flags);
	if (res < 0) {
		perror("error: open error");
		exit(1);
	}
	return res;
}

// int close(int fd);
void jjl_close(int fd)
{
	if (close(fd) < 0) {
		perror("error: close error");
		exit(1);
	}
	printf("info: close()\n");
}

// int socket(int domain, int type, int protocol);
int jjl_socket(int domain, int type, int protocol)
{
	int res = socket(domain, type, protocol);
	if (res < 0) {
		perror("error: socket() error");
		exit(1);
	}
	printf("info: socket()\n");
	return res;
}

// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void jjl_bind(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen)
{
	int res = bind(sockfd, (struct sockaddr *) addr, addrlen);
	if (res < 0) {
		perror("error: bind error");
		exit(1);
	}
	printf("info: bind()\n");
}

// int listen(int sockfd, int backlog);
void jjl_listen(int sockfd, int backlog)
{
	int res = listen(sockfd, backlog);
	if (res < 0) {
		perror("error: listen error");
		exit(1);
	}
	printf("info: listen()\n");
}

// int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int jjl_accept(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen)
{
	int res = accept(sockfd, (struct sockaddr *) addr, addrlen);
	if (res < 0) {
		perror("error: accept error");
		exit(1);
	}
	printf("info: accept()\n");
	return res;
}

// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int jjl_connect(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen)
{
	int res = connect(sockfd, (struct sockaddr *) addr, addrlen);
	if (res < 0) {
		perror("error: connect error");
		exit(1);
	}
	printf("info: connect()\n");
	return res;
}
