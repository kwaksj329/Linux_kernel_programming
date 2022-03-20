CC = gcc
OBJS = prime_sys_test.o
TARGET = prime_sys_test

all:
	make prime_sys_test

test_syscall: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	@rm -f $(OBJS)

test_syscall.o: prime_sys_test.c
	$(CC) -c prime_sys_test.c


.PHONY: clean
clean:
	rm -f $(TARGET)
