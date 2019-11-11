CFLAGS= -Wall -fpic -coverage -lm -std=c99

all: randomTest

randomTest: testme.c
	gcc -o testme testme.c $(CFLAGS)
	echo "testme.c:" >> testResults.out
	./testme >> testResults.out
	gcov testme.c -b -f >> testResults.out
	echo "finished" >> testResults.out


clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out
