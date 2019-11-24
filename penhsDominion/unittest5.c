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
  G.hand[currentPlayer][3] = mine;
  G.hand[currentPlayer][4] = copper;

  int numMine = 0;

  if (G.hand[currentPlayer][0] == 11) {
    numMine++;
  };
  if (G.hand[currentPlayer][1] == 11) {
    numMine++;
  };
  if (G.hand[currentPlayer][2] == 11) {
    numMine++;
  };
  if (G.hand[currentPlayer][3] == 11) {
    numMine++;
  };
  if (G.hand[currentPlayer][4] == 11) {
    numMine++;
  };



  int hand1 = G.hand[currentPlayer][0];
  int hand2 = G.hand[currentPlayer][1];
  int hand3 = G.hand[currentPlayer][2];
  int hand4 = G.hand[currentPlayer][3];
  int hand5 = G.hand[currentPlayer][4];


  int curHand = G.handCount[currentPlayer];


  int ufivet = mineCardEffect(choice1, choice2, &G, 0, currentPlayer);

  if (ufivet != 0) {
    printf ("Error! Mine returned an error!\n");
  }

  if ( (getCost(G.hand[currentPlayer][choice1]) + 4) == getCost(choice2) )
  {
      printf("Error! Card shouldn't be able to be obtained\n");
  }

  if (curHand != G.handCount[currentPlayer]) {
    printf("error! Card not added to hand!\n");
  }


  int newNumMine = 0;

  if (G.hand[currentPlayer][0] == 11) {
    newNumMine++;
  };
  if (G.hand[currentPlayer][1] == 11) {
    newNumMine++;
  };
  if (G.hand[currentPlayer][2] == 11) {
    newNumMine++;
  };
  if (G.hand[currentPlayer][3] == 11) {
    newNumMine++;
  };
  if (G.hand[currentPlayer][4] == 11) {
    newNumMine++;
  };

  if (newNumMine != numMine-1) {
    printf("Error! Wrong card discarded, should have discarded Mine!\n");
  }

  printf("\n");
  printf("\n");
  printf("\n");

  return 0;
};

//cd desktop/school/osu/se/CS362-F2019//penhsDominion/
