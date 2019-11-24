#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

  printf("/****************************************\n");
  printf("/**********  MINION ERRORS   ************\n");
  printf("/****************************************\n");

  int currentPlayer = 0;
  int i = 0;
  int j = 0;

  struct gameState G;

  int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  initializeGame (2, k, 8, &G);

/*int i, int j, int choice1, int choice2, int currentPlayer, struct gameState *state, int handPos*/

  G.coins = 10;


  minionCardEffect (1, 0, &G, 0, currentPlayer); //option 1:

  if (G.coins != 12) {
    printf("Error calculating +2 coins during Choice #1! ");
    if (G.coins > 12) {
      printf(" User receives too many coins. \n");
    }
    else {
      printf(" User needs more coins. \n");
    }
  }


  G.handCount[1] = 5;

  minionCardEffect (0, 1, &G, 0, currentPlayer); //option 2:

  //checks to make sure hand count is correct
  if (G.handCount[currentPlayer] != 4) {
    printf("User has the wrong number of cards! ");
    if (G.handCount[currentPlayer] > 4) {
      printf("User received too many cards. \n");
    }
    else {
      printf("User needs more cards. \n");
    }
  }

  if (G.handCount[1] > 4) {
    printf("Error! Other player needs to discard cards.\n");
  };



printf("\n");
printf("\n");
printf("\n");

return 0;
};
