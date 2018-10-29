/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Card Test 2 - Smithy Card
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
	int failCount = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 800;
	int numPlayers = 2;
	int player = 0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int count1 = 0, count2 = 0;
	int i = 0;

	initializeGame(numPlayers, k, seed, &state);

	printf("\n\n******  START Card Test 2: Smithy Card  ******\n\n");

	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);
	
	//Check hand count
	if(test.handCount[player] -1 == state.handCount[player])
		printf("Passed (check hand count)\n");
	else
	{
		failCount++;
		printf("Failed (check hand count)\n");
	}
	
	// Check player hand
	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed (Smithy card was added to player's hand)\n");
	else
	{
		failCount++;
		printf("Failed (Smithy card not added to player's hand)\n");
	}

	
	// Check if Smithy was played
	if(test.playedCardCount +2 == state.playedCardCount)
		printf("Passed (player played Smithy card)\n");
	else
	{
		failCount++;
		printf("Failed (Smithy card not played)\n");
	}
	
	
	// Count smithy cards in hand
	for (i = 0; i < state.handCount[0]; i++)
		if(state.hand[0][i] == smithy)
			count1++;
		
	for (i = 0; i < test.handCount[0]; i++)
		if(test.hand[0][i] == smithy)
			count2++;
	
	if(count1 == count2 -1)
		printf("Passed (count Smithy card in hand)\n");
	else
	{
		failCount++;
		printf("Failed (count Smithy card in hand)\n");
	}
	
	
	// Check if card was discarded
	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed (Smithy card was discarded)\n");	
	else
	{
		failCount++;
		printf("Failed (Smithy card not discarded)\n");
	}
	
	
	if (failCount == 0)
		printf("******    END Card Test 2: ALL PASSED!     ******\n");
	
	else
		printf("******  END Card Test 2: %d TESTS FAILED!  ******\n\n",failCount);

	return 0;
}