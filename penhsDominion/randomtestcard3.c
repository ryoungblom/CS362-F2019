
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int randoms(int lower, int upper) {
  int num = (rand() %  (upper - lower + 1)) + lower;
  return num;
}

int randomCard() {

  int lower = 0;
  int upper = 33;

  int num = (rand() %  (upper - lower + 1)) + lower;
  return num;
}

int main () {

  srand(time(0));

  printf("/****************************************\n");
  printf("/********  TRIBUTE RANDOM TEST **********\n");
  printf("/****************************************\n");

  int check = 0;
  int counter = 0;
  int initError = 0;
  int baronError = 0;

  int c1Flag = 0;
  int c2Flag = 0;
  int c3Flag = 0;
  int c4Flag = 0;
  int c5Flag = 0;

  int para1 = 0;
  int para2 = 0;
  int para3 = 0;
  int para4 = 0;
  int nextPlayer = 0;


  while (check == 0) {

    struct gameState G;

    int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    int currentPlayer = randoms(0,0);
    int numPlayers = randoms(1, MAX_PLAYERS);
    int choice1 = randoms(0,1);
    int handSize = randoms(3, 10);
    int choice2 = randoms(0, 1);
    int deckCount = randoms(5,MAX_DECK);
    int tributeRevealedCards[2] = {-1, -1};
    nextPlayer = currentPlayer+1;


    if (initializeGame (numPlayers, k, 8, &G) == -1) {

      if (para3 < 2) {
        printf("Sample of FAILED Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice: %d\n", choice1);
        printf("     Current Player: %d\n", currentPlayer);
        printf("     Coins: %d\n", G.coins);
        printf("     Hand: \n");

        for (int e = 0; e < G.handCount[currentPlayer]; e++) {
          printf("          %d \n", G.hand[currentPlayer][e]);
        };
      }

      para3++;


      initError++;
      continue;
    };

    G.coins = randoms(0, 99);

    G.deckCount[currentPlayer] = deckCount;

    for (int e = 0; e < G.deckCount[currentPlayer]; e++) {
      //printf("HAND %d : %d\n", e, G.hand[currentPlayer][e]);
      G.deck[currentPlayer][e] = randomCard();
    };

    G.handCount[currentPlayer] = handSize;

    //printf("HANDCOUNT-PRE: %d\n", handSize);

    for (int h = 0; h < numPlayers; h++){
      G.handCount[h] = randoms(2,8);
      for (int e = 0; e < G.handCount[h]; e++) {
        //printf("HAND %d : %d\n", e, G.hand[currentPlayer][e]);
        G.hand[h][e] = randomCard();
      };
    }


    int coinsHolder = G.coins;
    int numActionsP = G.numActions;


    //printf("Estate-PRE: %d || gold: %d\n", estateCount, coinsHolder);
    int i = 0;

    for (int e = 0; e < G.handCount[currentPlayer]; e++) {
      if (G.hand[currentPlayer][e] > 26) {
        baronError++;
        //c3Flag = 1;
        continue;
      }
    };


    if (currentPlayer != numPlayers) {
      nextPlayer = currentPlayer++;
    }
    else {
      nextPlayer = 0;
    }

      if (G.handCount[nextPlayer] > 1) {
        if (G.hand[nextPlayer][G.handCount[nextPlayer]-1] == G.hand[nextPlayer][G.handCount[nextPlayer]-2]) {
          c5Flag = 1;
        }
      }

      G.discardCount[nextPlayer] = randoms (0,5);
      G.deckCount[nextPlayer] = randoms (0,5);


    tributeCardEffect(&G, currentPlayer, nextPlayer);


    //printf("HANDCOUNT-POST: %d\n", G.handCount[currentPlayer]);

    if (G.coins != coinsHolder) {
      c4Flag++;
      if (para1 < 2){
        printf("Sample of Working Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice1: %d\n", choice1);
        printf("     Choice2: %d\n", choice2);
        printf("     Current Player: %d\n", currentPlayer);
        printf("     Coins: %d\n", G.coins);
        printf("     Hand: \n");

        for (int e = 0; e < G.handCount[currentPlayer]; e++) {
          printf("          %d \n", G.hand[currentPlayer][e]);
        };

      }

      else {
        c1Flag = 1;
      }
      para1++;
    }

    if (G.numActions != numActionsP) {
      c4Flag++;
    //else if (1) {
      if (para2 < 1){
        printf("Sample of Working Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice1: %d\n", choice1);
        printf("     Choice2: %d\n", choice2);
        printf("     Current Player: %d\n", currentPlayer);
        printf("     Coins: %d\n", G.coins);
        printf("     Hand: \n");

        for (int e = 0; e < G.handCount[currentPlayer]; e++) {
          printf("          %d \n", G.hand[currentPlayer][e]);
        };

      }
      else {
        c2Flag = 1;
      }
      para2++;
    }

    if (G.handCount[currentPlayer] != handSize + 1) {
      c4Flag++;
    //else if (1) {
      if (para2 < 1){
        printf("Sample of Working Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice1: %d\n", choice1);
        printf("     Choice2: %d\n", choice2);
        printf("     Current Player: %d\n", currentPlayer);
        printf("     Coins: %d\n", G.coins);
        printf("     Hand: \n");

        for (int e = 0; e < G.handCount[currentPlayer]; e++) {
          printf("          %d \n", G.hand[currentPlayer][e]);
        };

      }
      else {
        c3Flag = 1;
      }
      para2++;
    }


    if (c4Flag != 0) {

      if (para4 < 2) {
        printf("Sample of FAILED Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice: %d\n", choice1);
        printf("     Current Player: %d\n", currentPlayer);
        printf("     Coins: %d\n", G.coins);
        printf("     Hand: \n");

        for (int e = 0; e < G.handCount[currentPlayer]; e++) {
          printf("          %d \n", G.hand[currentPlayer][e]);
        };
      }

      para4++;


      baronError++;
    }

    c4Flag = 0;
    counter++;

    if (counter > 999999 && (c1Flag == 1 && c2Flag == 1 && c3Flag == 1 && c5Flag == 1)) {
      check = 1;
    }

    else if (counter > 999999) {
      check = 1;
    }

  }

  printf("Errors on initialization: %d\n", initError);
  printf("Errors in gameplay: %d\n", baronError);

  printf("\n");
  printf("\n");

}
