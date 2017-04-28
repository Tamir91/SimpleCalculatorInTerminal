all: my_math int_loop
	gcc -g -Wall -ansi -pedantic my_math int_loop -o all 

my_math: my_math.c
	gcc -c -Wall -ansi -pedantic my_math.c -o my_math

int_loop: int_loop.c
	gcc -c -Wall -ansi -pedantic int_loop.c -o int_loop

clean:
	rm -f *.o my_math
	rm -f *.o int_loop
	rm -f *.o all