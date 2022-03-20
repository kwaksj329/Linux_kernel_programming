ccflags-y = -Wno-unused-function -Wno-unused-label -Wno-unused-variable

obj-m = my_cdev.o

# TODO: Complite the Makefile for my_cdev module
CONFIG_MODULE_SIG=n
KDIR := ../../src/linux-5.15.4/

PWD := $(shell pwd)

all: my_cdev.c my_cdev.h
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

