#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

  printf("/****************************************\n");
  printf("/**********  TRIBUTE ERRORS   ***********\n");
  printf("/****************************************\n");

  int currentPlayer = 0;
  int nextPlayer = currentPlayer +1;
  int i = 0;

  int tributeRevealedCards[2] = {-1, -1};

  struct gameState G;

  int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  initializeGame (2, k, 8, &G);


  G.deckCount[nextPlayer] = 0;

  refactoredTribute(i, tributeRevealedCards, currentPlayer, nextPlayer, &G);


  G.discardCount[nextPlayer] = 5;
  int discardTest = G.discardCount[nextPlayer];

  G.deckCount[nextPlayer] = 4;
  G.deck[nextPlayer][0] = baron;
  G.deck[nextPlayer][1] = baron;
  G.deck[nextPlayer][0] = baron;
  G.deck[nextPlayer][1] = baron;

  G.deck[nextPlayer][G.deckCount[nextPlayer]-1] = baron;
  G.deck[nextPlayer][G.deckCount[nextPlayer]-2] = curse;

  refactoredTribute(i, tributeRevealedCards, currentPlayer, nextPlayer, &G);

  //printf("Discard Count: %d\n", G.discardCount[nextPlayer]);

  if (G.discardCount[nextPlayer] != discardTest-2) {
    printf("Error discarding cards! \n");
  }


  G.deckCount[nextPlayer] = 4;
  G.deck[nextPlayer][0] = baron;
  G.deck[nextPlayer][1] = baron;
  G.deck[nextPlayer][0] = baron;
  G.deck[nextPlayer][1] = baron;
  G.deck[nextPlayer][G.deckCount[nextPlayer]-1] = copper;
  G.deck[nextPlayer][G.deckCount[nextPlayer]-2] = gardens;

  G.coins = 10;
  int coins = G.coins;
  G.handCount[currentPlayer] = 5;
  int cardNo = G.handCount[currentPlayer]; //5

  refactoredTribute(i, tributeRevealedCards, currentPlayer, nextPlayer, &G);

  if (G.coins != coins + 2) {
    printf ("Coin count wrong! \n");
  }

  printf("Cards: %d\n", G.handCount[currentPlayer]);

  if (cardNo+2 != G.handCount[currentPlayer]) {
    printf("Error! Card drawing failure! \n");
  }



  printf("\n");
  printf("\n");
  printf("\n");

  return 0;
};
