#include "types.h"
#include "stat.h"
#include "user.h"
#include "x86.h"


int main()
{
	int pid, i;
	int SIZE = 4096 + 1;
	char *space = (char *)malloc(SIZE);
	printf(1, "cow test.\n");
	procdump();
	if ((pid = fork()) == 0) {
		printf(1, "\nChild process before changing values\n\n");
		procdump();
		for (i = 0; i < SIZE; i++) {
			space[i]++;
		}
		printf(1, "\nChild process after changing values\n\n");
		procdump();
		exit();
	} else
		wait();
	free(space);
	exit();
	return 1;
}