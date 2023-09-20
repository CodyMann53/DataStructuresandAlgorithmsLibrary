all: linkedlisttest

linkedlisttest: linkedlist.o linkedlisttest.o
	gcc -o linkedlisttest linkedlisttest.o linkedlist.o

linkedlisttest.o: linkedlisttest.c
	gcc -c linkedlisttest.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

.PHONY: clean all
clean:
	rm -f linkedlisttest linkedlisttest.o linkedlist.o