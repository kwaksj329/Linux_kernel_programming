#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#define NR_my_syscall 549

int main(int argc, char** argv) {

	int answer = 0;
	int opt, num;
	struct timeval start, end;
	long time;

	while((opt = getopt(argc, argv, "n:")) != -1)
		if(opt == 'n')
			num = atoi(optarg);
	
	gettimeofday(&start, NULL);
	answer = syscall(NR_my_syscall, &num);
	printf("The number of Prime number: %d\n", answer);
	gettimeofday(&end, NULL);

	time = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	printf("Processing time: %ld us \n", time);

	/*
	if (ret != 0) {
		fprintf(stderr, "ERR[%d]: syscall %d is failed\n", ret, NR_my_syscall);
		return -1;
	}*/
	return 0;
}
