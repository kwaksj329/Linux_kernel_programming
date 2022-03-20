#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char** argv) {

	int answer = 0;
	int i, j, opt, flag, num;
	unsigned int *arr;
	struct timeval start, end;
	long usertime;

	srand(time(NULL));

	while((opt = getopt(argc, argv, "n:")) != -1)
		if(opt == 'n')
			num = atoi(optarg);
	
	gettimeofday(&start, NULL);

	printf("The number of total random numbers: %d\n", num);

	arr = (unsigned int *)malloc(sizeof(unsigned int) * num);

	for(i = 0 ; i < num ; i++){
	
		arr[i] = rand() % (num - 1) + 2;
		//printf("n = %d\n", arr[i]);
	
	}

	for(i = 0 ; i < num ; i++){
		flag = 1;

                if(arr[i] != 2 && arr[i] % 2 == 0){
                        flag = 0;
                        continue;
                }

                for(j = 3; j * j <= arr[i]; j+=2){
                        if(arr[i] % j ==0){
                                flag = 0;
                                break;
                        }
                }

                if(flag == 1) answer++;
	}


	printf("The number of Prime number: %d\n", answer);
	
	gettimeofday(&end, NULL);

	usertime = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	printf("Processing time: %ld us \n", usertime);
	
	return 0;
}
