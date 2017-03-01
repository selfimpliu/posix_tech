#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>
#include <string.h>

// 记录日志，通常要分级别。
// 要记录的信息至少有：时间、文件、行号、msg 
// 用perror()不能记录时间、文件、行号等信息，但是出错原因记录的很准确。


void read_diskfile_readonly()
{
	const char *pathname = "/home/work/git/posix_tech/file";
	int flags = O_RDONLY;
	int fd = open(pathname, flags);
	if (fd == -1) {
		error_at_line(1, errno, __FILE__, __LINE__, "open() failed");
	}
	int x = close(fd);
	if (x == -1) {
		printf("%s : %d\n", __FILE__, __LINE__);
		perror("close failed");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	read_diskfile_readonly();
	
	return 0;
}
