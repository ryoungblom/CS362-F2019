#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

  printf("/****************************************\n");
  printf("/************  MINE ERRORS   ************\n");
  printf("/****************************************\n");

  int currentPlayer = 0;
  //int nextPlayer = currentPlayer +1;
  int i = 0;
  int j = 0;
  int choice1 = 4;
  int choice2 = 5;

  struct gameState G;

  int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  initializeGame (2, k, 8, &G);

  G.handCount[currentPlayer] = 5;

  G.hand[currentPlayer][0] = baron;
  G.hand[currentPlayer][1] = copper;
  G.hand[currentPlayer][2] = gold;
  G.hand[currentPlayer][3] = copper;
  G.hand[currentPlayer][4] = copper;

  int curHand = G.handCount[currentPlayer];

  refactoredMine(j, i, choice1, choice2, currentPlayer, &G, 0);


  if ( (getCost(G.hand[currentPlayer][choice1]) + 4) == getCost(choice2) )
  {
      printf("Error! Card shouldn't be able to be obtained\n");
  }

  if (curHand != G.handCount[currentPlayer]) {
    printf("error! Card not added to hand!\n");
  }





  printf("\n");
  printf("\n");
  printf("\n");

  return 0;
};
