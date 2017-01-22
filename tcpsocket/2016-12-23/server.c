#include "common.h"


int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	jjl_servaddr_config(servaddr);

	//int servfd = socket(AF_INET, SOCK_STREAM, 0);
	int servfd = jjl_socket(AF_INET, SOCK_STREAM, 0);
	jjl_bind(servfd, &servaddr, sizeof(servaddr));
	jjl_listen(servfd, 3);

	while (1) {
		struct sockaddr_in clientaddr;
		socklen_t len = 0;
		bzero(&clientaddr, sizeof(clientaddr));
		printf("hello\n");
		// int fd = jjl_accept(servfd, &clientaddr, &len);
		int fd = jjl_accept(servfd, NULL, NULL);
		// do info exchange
		// int port = ntohs(clientaddr.sin_port);
		int ip = ntohs(clientaddr.sin_addr.s_addr);
		printf("[info]: client ip: %d, port: %d\n", ip, port);
		jjl_close(fd);
	}
	jjl_close(servfd);
	return 0;
}

