CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unitTest randomTest

randomTest: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.o
	gcc -o randomtestcard1 dominion.o rngs.o randomtestcard1.c $(CFLAGS)
	echo "randomtestcard1.c:" >> randomtestresults.out
	./randomtestcard1 >> randomtestresults.out
	gcc -o randomtestcard2 dominion.o rngs.o randomtestcard2.c $(CFLAGS)
	echo "randomtestcard2.c:" >> randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	gcc -o randomtestcard3 dominion.o rngs.o randomtestcard3.c $(CFLAGS)
	echo "randomtestcard3.c:" >> randomtestresults.out
	./randomtestcard3 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out


unitTest: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.o
	gcc -o unittest1 dominion.o rngs.o unittest1.c $(CFLAGS)
	echo "unittest1.c:" >> unittestresults.out
	./unittest1 >> unittestresults.out
	gcc -o unittest2 dominion.o rngs.o unittest2.c $(CFLAGS)
	echo "unittest2.c:" >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcc -o unittest3 dominion.o rngs.o unittest3.c $(CFLAGS)
	echo "unittest3.c:" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcc -o unittest4 dominion.o rngs.o unittest4.c $(CFLAGS)
	echo "unittest4.c:" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcc -g -o unittest5 dominion.o rngs.o unittest5.c $(CFLAGS)
	echo "unittest5.c:" >> unittestresults.out
	./unittest5 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out
	#gdb ./unittest5

holder: randomtestcard1.c dominion.o
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1





clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
