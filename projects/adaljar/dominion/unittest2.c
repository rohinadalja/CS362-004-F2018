/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Unit Test 2 - Buying Cards
********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv)	
{
	int failCount=0;
	struct gameState testUnit;

	int seed = 800;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &testUnit);
	
 	printf("\n******  START Unit Test 2: Buying Cards  ******\n");
	
	testUnit.numBuys = 2;
	testUnit.coins = 4;
	
	printf("\nCheck for enough coins:\n");	
 	if(buyCard(2, &testUnit) == -1)
		printf("Passed Test (Check for enough coins)\n");
	else
	{
		printf("Failed Test (Check for enough coins)\n");
		failCount++;
	}
		
	testUnit.numBuys = 2;
	testUnit.coins = 10;

 	printf("\nAttempt to buy card:\n");		
	if(buyCard(2, &testUnit) == 0)
		printf("Passed Test (Attempt to buy card)\n");
	else
	{
		printf("Failed Test (Attempt to buy card)\n");
		failCount++;
	}

	testUnit.numBuys = 0;
	testUnit.coins = 10;

 	printf("\nCheck if user still has remaining buys:\n"); 
	if(buyCard(2, &testUnit) == -1)
		printf("Passed Test (remaining buys)\n");
	else
	{
		printf("Failed Test (remaining buys)\n");
		failCount++;
	}

	if (failCount == 0)
		printf("\n******    END Unit Test 2: ALL PASSED!     ******\n");
	else
		printf("\n******  END Unit Test 2: %d TESTS FAILED!  ******\n\n",failCount);

	return 0;
}