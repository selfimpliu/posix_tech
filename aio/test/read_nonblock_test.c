#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <assert.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUF_SIZE 10

int main(int argc, char *argv[])
{
	char *filepath = "./file";

	int fd = open(filepath, O_RDONLY);
//	int fd = open(filepath, O_RDONLY | O_NONBLOCK);
	if (fd == -1) {
		error(1, errno, __FILE__, __LINE__, "open() failed");
	}
	
	char buf[BUF_SIZE];
	memset(buf, 0, BUF_SIZE);
	size_t x = 0;
	int i = 0;
	while ((x = read(fd, buf, BUF_SIZE - 1)) > 0) {
		strcat(buf, "\0");
		//printf("str:%s\n", buf);
		printf("%d\n", i++);
	 	sleep(1);
	}

	if (x == 0) {
		fprintf(stderr, "read complete\n");
		exit(EXIT_SUCCESS);
	} else {
		perror("read() failed");
	}


	int closeres = close(fd);
	if (closeres == -1) {
		error(1, errno, __FILE__, __LINE__, "close() failed");
	}
	return 0;
}
