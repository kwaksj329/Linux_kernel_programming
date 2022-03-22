all: test test2

test: test.c
	gcc test.c -o test

test2: test2.c
	gcc test2.c -o test2

test_all: test test2
	./test
	./test2 10
