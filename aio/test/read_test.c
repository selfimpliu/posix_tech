#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define STRING_SIZE (10)

int main(int argc, char *argv[])
{
	char *filepath = "/home/work/git/posix_tech/aio/test/file";

	int fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		error(1, errno, __FILE__, __LINE__, "open() failed");
	}
	// 如果不初始化,内存中的值会格式化为0吗?
	char buf[STRING_SIZE] = "";
	size_t x = 0;
	while ((x = read(fd, buf, STRING_SIZE-1)) > 0 ) {
		strcat(buf, "\0");
		printf("%s", buf);
		memset(buf, 0, STRING_SIZE);
	}
	if (x == -1) {
		error(1, errno, __FILE__, __LINE__, "read() failed");
	}
	

	return 0;
}

