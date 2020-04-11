all: build run clean
build: lab3z1v30.c lab3z2v30.c MainFile.c
	gcc -Wall -O0 -g3 -DDEBUG -pedantic-errors -std=c89 lab3z1v30.c lab3z2v30.c MainFile.c -o programm
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm