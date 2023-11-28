all: temp_functions

temp_functions: main.o temp_functions.o
	gcc -o temp_functions main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	del temp_functions.exe
