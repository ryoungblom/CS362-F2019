#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

  printf("/****************************************\n");
  printf("/**********  BARON 1 ERRORS   ***********\n");
  printf("/****************************************\n");

  int currentPlayer = 0;

  struct gameState G;

  int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  initializeGame (2, k, 8, &G);

  G.coins = 10;  //set gold
  int discardCount = G.discardCount[currentPlayer];

  int baronCount = 0;
  G.hand[0][0] = estate; //give player estate card
  G.hand[0][1] = baron; //give player estate card

  for (int w = 0; w < G.handCount[currentPlayer]; w++) {
    if (G.hand[currentPlayer][w] == baron) {
      baronCount++;
    };
  };

  baronCardEffect (1, &G, currentPlayer); //option 1:

  int newBaronCount = 0;

  for (int e = 0; e < G.handCount[currentPlayer]; e++) {
    if (G.hand[currentPlayer][e] == baron) {
      newBaronCount++;
    };
  };

  if (G.coins != 14) {
    printf("Error giving player coins! \n");
  }

  if (discardCount == G.discardCount[currentPlayer]) {
    printf("Error discarding both cards! \n");
  }

  else if (discardCount+2 != G.discardCount[currentPlayer]) {
    if (baronCount == newBaronCount) {
      printf("Error discarding a BARON card! \n");
    };
  };


  for (int q = 0; q < G.handCount[currentPlayer]; q++) {
    G.hand[currentPlayer][q] = baron;
  };

  baronCardEffect (1, &G, currentPlayer); //option 1:

  if (G.numBuys == G.numBuys) {
    printf("Buy increase error!\n");
  }

  G.hand[currentPlayer][4] = 15;

  int numBaron = 0;

  if (G.hand[currentPlayer][0] == 15) {
    numBaron++;
  };
  if (G.hand[currentPlayer][1] == 15) {
    numBaron++;
  };
  if (G.hand[currentPlayer][2] == 15) {
    numBaron++;
  };
  if (G.hand[currentPlayer][3] == 15) {
    numBaron++;
  };
  if (G.hand[currentPlayer][4] == 15) {
    numBaron++;
  };


  G.supplyCount[estate] = 2; //set estate supply to above 0
  baronCardEffect (0, &G, currentPlayer);

  int newNumBaron = 0;

  if (G.hand[currentPlayer][0] == 15) {
    newNumBaron++;
  };
  if (G.hand[currentPlayer][1] == 15) {
    newNumBaron++;
  };
  if (G.hand[currentPlayer][2] == 15) {
    newNumBaron++;
  };
  if (G.hand[currentPlayer][3] == 15) {
    newNumBaron++;
  };
  if (G.hand[currentPlayer][4] == 15) {
    newNumBaron++;
  };

  if (newNumBaron != numBaron-1) {
    printf("Error! Baron not Discarded!\n");
  }


  G.supplyCount[estate] = 1; //set estate supply to 1 so it can be decremented
  baronCardEffect (0, &G, currentPlayer);

  printf("Error! Game should have ended!\n");


printf("\n");
printf("\n");
printf("\n");

return 0;
};
