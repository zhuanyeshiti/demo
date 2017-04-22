tty:
	gcc -D REENTRANT -I /usr/include/nptl -L /usr/lib/nptl -lpthread -o a.out tty.c
mpty:
	gcc -o ptyhost  mpty.c
clean:
	rm a.out
