# Makefile — build with: make
obj-m = 1_kernel_ioctl.o 2_kernel_ioctl.o

KDIR := /lib/modules/$(shell uname -r)/build	#for native compilation
#KDIR := /home/pramod/be7/linux-rpi-5.12.y	#for cross compilation

PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
