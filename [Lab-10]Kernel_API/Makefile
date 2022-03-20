obj-m := list.o

CONFIG_MODULE_SIG=n
KDIR := ../../../../src/linux-5.15.4

PWD := $(shell pwd)

all: list.c
	make -C $(KDIR) M=$(PWD) modules
	@cp list.ko ../checker/

clean:
	make -C $(KDIR) M=$(PWD) clean
	@rm ../checker/*.ko
