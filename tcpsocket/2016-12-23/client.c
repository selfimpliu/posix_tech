#include "common.h"

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	
	int servfd = jjl_socket(AF_INET, SOCK_STREAM, 0);
	jjl_servaddr_config(servaddr);

	jjl_connect(servfd, &servaddr, sizeof(servaddr));
	
	// do infomation exchange
	sleep(10);	
	jjl_close(servfd);
	return 0;
}
