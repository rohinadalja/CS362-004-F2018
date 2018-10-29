/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Card Test 3 - Great Hall Card
********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main(int argc, char** argv) 
{
	printf("\n******  START Card Test 3: Great Hall Card  ******\n\n");
	
	int failCount = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 800;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {copper, minion, mine, silver, gold, cutpurse,
		sea_hag, tribute, smithy, council_room};
	
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(great_hall, choice1, choice2, choice3, &G, handpos, &bonus);
	
	
	if(G.handCount[G.whoseTurn] + 1 == testG.handCount[testG.whoseTurn])
		printf("Test Passed (hand count)\n");
	else
	{
		failCount++;
		printf("Test Failed (hand count)\n");
	}

	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
     
	if(G.numActions + 1 == testG.numActions)
		printf("Test Passed (check Great Hall action)\n");
	else
	{
		failCount++;
		printf("Test Failed (check Great Hall action)\n");
	}
	
	if (failCount == 0)
		printf("******    END Card Test 3: ALL PASSED!     ******\n");
	
	else
		printf("******  END Card Test 3: %d TESTS FAILED!  ******\n\n",failCount);
	
	return 0;
}
