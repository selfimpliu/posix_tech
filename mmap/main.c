#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	char *filepath = "./00.txt";
	int fd;
	struct stat sbuf;
	if (argc != 2) {
		fprintf(stderr, "usage: %s offset\n", argv[0]);
		exit(1);
	}
	fd = open(filepath, O_CREAT | O_RDWR);
	if (fd == -1) {
		error(1, errno, __FILE__, __LINE__, "open() failed");
	}

	char *s = "test";
	size_t len = strlen(s);
	if (write(fd, s, len) != len) {
		error(1, errno, __FILE__, __LINE__, "write() failed");
	}
	memset(&sbuf, 0, sizeof(sbuf));
	if (fstat(fd, &sbuf) == -1) {
		error(1, errno, __FILE__, __LINE__, "stat() failed");
	}

	int offset = atoi(argv[1]);
	if (offset < 0 || offset > sbuf.st_size - 1) {
		fprintf(stderr, "mmap : offset must be in the range 0 = %lu\n", sbuf.st_size - 1);
		exit(1);
	}

	char *data;
	// caddr_t 是什么类型？
	if ((data = mmap(NULL, sbuf.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)) == (void *) (-1)) {
		error(1, errno, __FILE__, __LINE__, "mmap() failed");
	}

	printf("byte at offset %d is '%c'\n", offset, data[offset]);
	data[1] = '0';
	memset(data, 0, sbuf.st_size);
	strncpy(data, "abcd", strlen("abcd"));
	munmap(data, sbuf.st_size);
	close(fd);
	return 0;
}











