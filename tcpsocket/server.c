#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <sys/types.h> // socket(),open(),creat()
#include <sys/socket.h> // socket()

#include <arpa/inet.h> // htonl(),htons(),ntohl(),ntohs()

#define BACKLOG 3

void init_ser_sockaddr(struct sockaddr_in addr);

int main(int argc, char *argv[])
{
	// define a socket for server.
	// open a fd for this socket.
	struct sockaddr_in servaddr;
	init_ser_sockaddr(servaddr);

	int servfd = jjl_socket(AF_INET, SOCK_STREAM, 0);

	jjl_bind(servfd, &servaddr, sizeof(servaddr));

	listen(servfd, BACKLOG);

	while (1) {
		struct sockaddr_in clientaddr;
		bzero(&clientaddr, sizeof(clientaddr));
		socklen_t len = 0;
		int fd = jjl_accept(servfd, &clientaddr, &len);
		// do information exchange
		sleep(10);
		jjl_close(fd);
	}
	jjl_close(servfd);

	exit(0);
}

void init_ser_sockaddr(struct sockaddr_in addr)
{
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(3000);
	addr.sin_addr.s_addr = htons(INADDR_ANY);
}
