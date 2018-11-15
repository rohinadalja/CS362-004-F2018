//Rohin Adalja - Random Tester for Adventurer Card
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define NUM_COINS 20
#define NUM_TESTS 20

int failCount = 0;

void customAssert(int flag, char *msg)
{
    if (flag == 0) 
    {
        printf("FAILED ASSERTION: %s\n", msg);
        failCount++;
    }
}

void printResults()
{
    if (failCount == 0)
        printf("\n -->  ALL TESTS COMPLETED SUCCESSFULLY <-- \n\n");
    else
        printf("\n -->  OH NO! %d Tests failed! <-- \n\n", failCount);
}

int main(int argc, char *argv[]) 
{
    printf("******   Random Test: Adventurer   ******\n");
    if (argc < 2)
    {
        printf("Incorrect # of arguments provided");
        return 0;
    }
    else
    {
        int seed = atoi(argv[1]);
        int n;
        for (n = 0; n < NUM_TESTS; n++)
        {
            struct gameState g;
            int check, numPlayer;
            int k[10] = {smithy, adventurer, village, minion, mine, cutpurse, sea_hag, steward, gardens, embargo};
        
            printf("Random Test Output %d:\n", n + 1);

            numPlayer = (rand() % 3) + 2;
            check = initializeGame(numPlayer, k, seed, &g);
            customAssert(check == 0, "Error: Failure to Initialize");

            g.handCount[numPlayer] = rand() % MAX_HAND;
            g.deckCount[numPlayer] = rand() % MAX_DECK;
            g.discardCount[numPlayer] = rand() % MAX_DECK;
            
            printf("~~ State before using Adventurer Card ~~\n");
            printf ("Deck cnt: %d\n", g.deckCount[numPlayer]);
            printf ("Hand cnt: %d\n", g.handCount[numPlayer]);
            printf ("Card #: %d\n\n", g.handCount[numPlayer] + g.deckCount[numPlayer] + g.discardCount[numPlayer]);

            check = cardEffect(adventurer, 1, 1, 1, &g, 0, 0);
            customAssert(check == 0, "Error: Failure when using card (when called cardEffect)"); 

            printf("~~ State after using Adventurer Card ~~\n");
            printf ("Deck cnt: %d\n", g.deckCount[numPlayer]);
            printf ("Hand cnt: %d\n", g.handCount[numPlayer]);
            printf ("Card #: %d\n\n", g.handCount[numPlayer] + g.deckCount[numPlayer] + g.discardCount[numPlayer]);
            
        }
        printResults();
        printf ("******   END - Random Test: Adventurer   ******\n\n");

        return 0;
    }
}