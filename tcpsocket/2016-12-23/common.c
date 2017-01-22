#include "common.h"


int jjl_socket(int domain, int type, int protocol)
{
	int fd = socket(domain, type, protocol);
	if (fd < 0) {
		perror("[error]: : socket() error");
		exit(1);
	}
	return fd;
}

void jjl_bind(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen)
{
	int res = bind(sockfd, (struct sockaddr *) addr, addrlen);
	if (res < 0) {
		perror("[error]: : bind() error");
		exit(1);
	}
}

void jjl_listen(int sockfd, int backlog)
{
	int res = listen(sockfd, backlog);
	if (res < 0) {
		perror("[error]: : listen() error");
		exit(1);
	}
}

int jjl_accept(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen)
{
	printf("[info]: accept() begin.\n");
	int fd = accept(sockfd, (struct sockaddr *) addr, addrlen);
	if (fd < 0) {
		perror("[error]: : accept() error");
		exit(1);
	}
	printf("[info]: accept() ok.\n");
	fflush(NULL);
	return fd;
}

void jjl_connect(int sockfd, const struct sockaddr_in *addr, socklen_t addrlen)
{
	int res = connect(sockfd, (struct sockaddr *) addr, addrlen);
	if (res < 0) {
		perror("[error]: : connect() error");
		exit(1);
	}
	printf("[info]: connect() ok\n");
	fflush(NULL);
}

void jjl_close(int fd)
{
	int res = close(fd);
	if (res < 0) {
		perror("[error]: : close() error");
		exit(1);
	}
}

void jjl_servaddr_config(struct sockaddr_in addr)
{
	addr.sin_family = AF_INET;
	addr.sin_port = htonl(3000);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
}
