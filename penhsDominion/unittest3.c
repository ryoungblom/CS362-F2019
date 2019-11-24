#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

  printf("/****************************************\n");
  printf("/********  AMBASSADOR ERRORS   **********\n");
  printf("/****************************************\n");

  int currentPlayer = 1;
  int i = 0;
  int j = 0;

  struct gameState G;

  int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  initializeGame (2, k, 8, &G);

  G.handCount[currentPlayer] = 5;

  G.hand[currentPlayer][0] = baron; //gives player 1 a curse card
  G.hand[currentPlayer][1] = baron; //gives player 1 a curse card
  G.hand[currentPlayer][2] = baron; //gives player 1 a curse card
  G.hand[currentPlayer][3] = curse; //gives player 1 a curse card
  G.hand[currentPlayer][4] = curse; //gives player 1 a curse card

  int supplyCheck = G.supplyCount[G.hand[currentPlayer][4]];

  int curseCount = 0;
  int handCount = G.handCount[currentPlayer];
  int newCurse = 0;


  for (int w = 0; w < G.handCount[currentPlayer]; w++) {

    //printf ("Card: %d \n", G.hand[currentPlayer][w]);

    if (G.hand[currentPlayer][w] == curse) {
      curseCount++;

    };
  };

  ambassadorCardEffect(4, 2, &G, 0, currentPlayer);

  if (G.supplyCount[G.hand[currentPlayer][4]] != supplyCheck - 2) {
    printf("error! Incorrect number of cards added back into supply!\n");
  }

  for (int w = 0; w < G.handCount[currentPlayer]; w++) {

    //printf ("Card: %d \n", G.hand[currentPlayer][w]);

    if (G.hand[currentPlayer][w] == curse) {
      newCurse++;

    };
  };

  if (curseCount+1 != newCurse || handCount != G.handCount[currentPlayer]+1) {
    printf("error! Incorrect number of cards given to player %d!\n", currentPlayer);
  }


  printf("\n");
  printf("\n");
  printf("\n");

  return 0;
};
