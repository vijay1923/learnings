# Makefile — build with: make
obj-m = char2.o

KDIR := /lib/modules/$(shell uname -r)/build
#KDIR := /home/pramod/be7/linux-rpi-5.12.y

PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
