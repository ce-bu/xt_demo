obj-m += xt_demo.o


all: libxt_demo.so xt_demo.ko


xt_demo.ko : xt_demo.c
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

libxt_demo.so: libxt_demo.o
	gcc -shared -fPIC -o $@ $^

libxt_demo.o: libxt_demo.c
	gcc -O2 -Wall -D_INIT=$*_init -fPIC -c -o $@ $<;

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f *.o *.so
up: all
	sudo insmod xt_demo.ko

down:
	sudo rmmod xt_demo

.PHONY : all
