/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Unit Test 1 - Coin Check for Copper, Silver, Gold coins
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
	
 	printf("\n******  START Unit Test 1: Update Coins Test  ******\n");
	testUnit.hand[0][0]=copper;
	testUnit.hand[0][1]=copper;
	testUnit.hand[0][2]=copper;
	updateCoins(0, &testUnit, 0);
	
	if(testUnit.coins == 5)
		printf("Test Passed. (%d Coins)\n", testUnit.coins);
	else
	{
		printf("Failed Test: After adding copper, should have 5 coins: Test Failed. (%d Coins)\n", testUnit.coins);
		failCount++;
	}
	
	testUnit.hand[0][0]=copper;
	testUnit.hand[0][1]=copper;
	testUnit.hand[0][2]=copper;
	updateCoins(0, &testUnit, 1);
	
	if(testUnit.coins == 6)
		printf("Test Passed. (%d Coins)\n", testUnit.coins);
	else
	{
		printf("Failed Test: After adding bonus, should have 6 coins. (%d Coins)\n", testUnit.coins);
		failCount++;
	}

	testUnit.hand[0][0]=silver;
	testUnit.hand[0][1]=silver;
	testUnit.hand[0][2]=silver;
	updateCoins(0, &testUnit, 0);

	if(testUnit.coins == 8)
		printf("Test Passed. (%d Coins)\n", testUnit.coins);
	else
	{
		printf("Failed Test: After adding silver, should have 8 coins. (%d Coins)\n", testUnit.coins);
		failCount++;
	}
	
	testUnit.hand[0][0]=gold;
	testUnit.hand[0][1]=gold;
	testUnit.hand[0][2]=gold;
	testUnit.hand[0][3]=gold;
	testUnit.hand[0][4]=gold;
	updateCoins(0, &testUnit, 0);
	
	if(testUnit.coins == 15)
		printf("Test Passed. (%d Coins)\n", testUnit.coins);
	else
	{
		printf("Failed Test: After adding gold, should have 15 coins. (%d Coins)\n", testUnit.coins);
		failCount++;
	}

	if (failCount == 0)
		printf("******    END Unit Test 1: ALL PASSED!     ******\n");
	else
		printf("******  END Unit Test 1: %d TESTS FAILED!  ******\n\n",failCount);

	return 0;
}