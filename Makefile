build:
	gcc task1.c -o task1 -Wall
	gcc task2.c -o task2 -Wall -lm
	gcc task4.c -o task4 -Wall -lm

clean:
	rm task1
	rm task2
	rm task4
