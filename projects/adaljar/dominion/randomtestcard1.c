//Rohin Adalja - Random Tester for Village Card
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
	printf("******   Random Test: Village   ******\n");
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
			int check, numPlayersRand, handAfter, randActions, handBefore, handCntRand, actionsAfter, actionsBefore;
			int k[10] = {smithy, adventurer, village, minion, mine, cutpurse, sea_hag, steward, gardens, embargo};

			handCntRand = rand() % 6;
			numPlayersRand = (rand() % 2) + 2;
			randActions = rand() % 10;

			check = initializeGame(numPlayersRand, k, seed, &g);
			customAssert(check == 0, "Error: After calling initializeGame.");

			g.hand[0][0] = village;
			g.whoseTurn = 0;
			g.handCount[0] = handCntRand;
			g.numActions = randActions;

			handBefore = numHandCards(&g);
			actionsBefore = g.numActions;

			check = playCard(0, 0, 0, 0, &g);
			customAssert(check == 0, "Error: After calling playCard");

			handAfter = numHandCards(&g);
			actionsAfter = g.numActions;
			
			customAssert(handAfter == handBefore, "Error: Village should add 1 card to hand.");
			customAssert(actionsAfter == actionsBefore + 1, "Error: Village should add 2 actions");
		}
		printResults();
		printf ("******   END - Random Test: Village   ******\n\n");
		
		return 0;
    }

}