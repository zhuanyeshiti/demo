tty:
	gcc -D REENTRANT -I /usr/include/nptl -L /usr/lib/nptl -lpthread -o a.out tty.c
mpty:
	gcc -o ptyhost -util /lib/libutil-2.24.so  mpty.c
clean:
	rm a.out
