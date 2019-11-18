
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

int main () {

  srand(time(0));

  printf("/****************************************\n");
  printf("/**********  BARON RANDOM TEST ***********\n");
  printf("/****************************************\n");

  int check = 0;
  int counter = 0;
  int initError = 0;
  int baronError = 0;

  int c1Flag = 0;
  int c2Flag = 0;
  int c3Flag = 0;
  int c5Flag = 0;
  int estateFlag = 0;

  int para1 = 0;
  int para2 = 0;
  int para3 = 0;
  int para4 = 0;


  while (check == 0) {

    estateFlag = 0;

    struct gameState G;

    int * k = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    int currentPlayer = randoms(0,0);
    int numPlayers = randoms(1, MAX_PLAYERS);
    int choice1 = randoms(0,1);
    int randomCard1 = randoms(0,5);
    int randomCard2 = randoms(0,5);
    int randomCard3 = randoms(0,5);
    int randomCard4 = randoms(0,5);
    int randomCard5 = randoms(0,5);

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

    G.coins = randoms(0, 10);

    G.hand[currentPlayer][0] = randomCard1; //give player random card
    G.hand[currentPlayer][1] = randomCard2; //give player random card
    G.hand[currentPlayer][2] = randomCard3; //give player random card
    G.hand[currentPlayer][3] = randomCard4; //give player random card
    G.hand[currentPlayer][4] = randomCard5; //give player random card


    int coinsHolder = G.coins;

    for (int e = 0; e < G.handCount[currentPlayer]; e++) {
      //printf("HAND %d : %d\n", e, G.hand[currentPlayer][e]);
      if (G.hand[currentPlayer][e] > 26) {
        estateFlag = 1;
      };
    };

    if (estateFlag == 1) {
      continue;
      initError++;
    }

    int estateCount = 0;

    G.supplyCount[estate] = randoms(1,5);

    for (int e = 0; e < G.handCount[currentPlayer]; e++) {
      //printf("HAND %d : %d\n", e, G.hand[currentPlayer][e]);
      if (G.hand[currentPlayer][e] == estate) {
        estateCount++;
      };
    };

    //printf("Estate-PRE: %d || gold: %d\n", estateCount, coinsHolder);

    //printf ("COUNTER: %d \n", counter);

    if (refactoredBaron (choice1, currentPlayer, &G) != 0) {
      baronError++;
      counter++;
      continue;
    }


    //assert statement
    /*if (G.coins != coinsHolder+4) {
    printf("Error giving player coins! \n");
    baronError++;
    continue;
  }*/

    int newEstateCount = 0;

    for (int e = 0; e < G.handCount[currentPlayer]; e++) {
      if (G.hand[currentPlayer][e] == estate) {
        newEstateCount++;
      };
    };

    //printf("Estate-POST: %d || coins: %d\n", newEstateCount, G.coins);

    if (G.coins != coinsHolder && c1Flag == 0) {

      if (coinsHolder + 4 != G.coins) {
        baronError++;
      }

      if (para1 < 1){
        printf("Sample of Working Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice: %d\n", choice1);
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

    else if (choice1 == 1 && estateCount == 0 && c3Flag == 0 && c1Flag == 0) {
      c3Flag =1;
    }

    else if (newEstateCount < estateCount) {

      if (newEstateCount - 1 != estateCount) {
        baronError++;
      }

      if (para2 < 1){
        printf("Sample of Working Parameters: \n");
        printf("     Number of Players: %d\n", numPlayers);
        printf("     Choice: %d\n", choice1);
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

    else if (G.supplyCount[estate] == 0 && choice1 == 0) {
      c5Flag = 1;
    }

    else {

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
