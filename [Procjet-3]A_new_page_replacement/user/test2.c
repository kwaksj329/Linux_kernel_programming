#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

#define memstat_syscall 548

int main(int argc, char** argv) {
        syscall(memstat_syscall);
        int memory;
        
	if(argc > 1)
                memory = atoi(argv[1]);
        else
                memory = 5;

        char *a, *b, *c, *d, *e;

        a = (char*)malloc(memory * 1024 * 1024 * sizeof(char));
        memset(a, '0', memory * 1024 * 1024 * sizeof(char));
        b = (char*)malloc(memory * 1024 * 1024 * sizeof(char));
        memset(b, '0', memory * 1024 * 1024 * sizeof(char));
        c = (char*)malloc(memory * 1024 * 1024 * sizeof(char));
        memset(c, '0', memory * 1024 * 1024 * sizeof(char));
        d = (char*)malloc(memory * 1024 * 1024 * sizeof(char));
        memset(d, '0', memory * 1024 * 1024 * sizeof(char));
        e = (char*)malloc(memory * 1024 * 1024 * sizeof(char));
        memset(e, '0', memory * 1024 * 1024 * sizeof(char));
        
	syscall(memstat_syscall);
        
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);

        return 0;
}
