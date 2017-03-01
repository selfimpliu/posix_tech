#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <aio.h>
#include <signal.h>

#define BUF_SIZE 20
#define err_exit(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)
#define errmsg(msg) do { perror(msg); } while (0)

#define IO_SIGNAL SIGUSER1
struct io_request {
	int 			reqnum;
	int 			status;
	struct aiocb 	*aiocbp;
};
static volatile sig_atomig_t gotSIGQUIT = 0;
static void quit_handler(int sig) 
{
	gotSIGQUIT = 1;
}
static void aiosig_handler(int sig, siginfo_t *si, void ucontext)
{
	write(STDOUT_FILENO, "I/O comletion signal received\n", 31);
}

int main(int argc, char *argv[])
{
	struct io_request *io_list;
	struct aiocb *aiocblist;
	struct sigacation sa;
	int s, j;
	int numreqs;
	int openreqs;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <pathname> <pathname> ... \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	numreqs = argc - 1;
	io_list = calloc(numreqs, sizeof(struct io_request));
	if (io_list == NULL) {
		err_exit("calloc");
	}
	return 0;
}
