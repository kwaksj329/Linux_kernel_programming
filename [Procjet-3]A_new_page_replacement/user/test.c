#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

#define memstat_syscall 548

int main() {
        syscall(memstat_syscall);
        FILE *fp, *fp2;
        fp = fopen("file_for_test", "r");
        fp2 = fopen("file_for_test2", "r");
	
	while(fgetc(fp) != EOF);
	while(fgetc(fp2) != EOF);
        
	syscall(memstat_syscall);
        
	fclose(fp);
	fclose(fp2);

        return 0;
}
