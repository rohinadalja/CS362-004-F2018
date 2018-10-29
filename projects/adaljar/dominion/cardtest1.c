/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Card Test 1 - Adventurer Card
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
	struct gameState test1, test2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int count1 = 0, count2 = 0;
	int i=0;

	initializeGame(numPlayers, k, seed, &test1);

	printf("\n******  START Card Test 1: Adventurer Card  ******\n\n");

	memcpy(&test2, &test1, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &test1, handpos, &bonus);

	player = whoseTurn(&test2);
	
	if(test2.deckCount[player] -1 == test1.deckCount[player])			// Deck Count
		printf("Passed (deck count)\n");
	else
	{
		failCount++;
		printf("Failed (deck count)\n");
	}
	
	if(test2.handCount[player] -1 == test1.handCount[player])			// Check hand count
		printf("Passed (hand count)\n");
	else
	{
		failCount++;
		printf("Failed (hand count)\n");
	}
	

	if(test1.hand[player][test2.handCount[player]] != -1)				// Check player hand
		printf("Passed (Adventurer card added to player's hand)\n");
	else
	{
		failCount++;
		printf("Failed (Adventurer card added to player's hand)\n");
	}

	
	if(test2.playedCardCount + 2 == test1.playedCardCount)				// Check if player played card
		printf("Passed (test play Adventurer card)\n");
	else
	{
		failCount++;
		printf("Failed (test play Adventurer card)\n");
	}
	
	
	for (i = 0; i < test1.handCount[0]; i++)							// Count Adventurer in hand
		if(test1.hand[0][i] == adventurer)
			count1++;
		
	for (i = 0; i < test2.handCount[0]; i++)
		if(test2.hand[0][i] == adventurer)
			count2++;
	
	if(count1 == count2 -1)
		printf("Passed (count Adventurer card in hand)\n");
	else
	{
		failCount++;
		printf("Failed (count Adventurer card in hand)\n");
	}
	
	
	if(test2.discardCount[player] == test1.discardCount[player])		// Check if card was discarded
		printf("Passed (discard Adventurer card)\n");	
	else
	{
		failCount++;
		printf("Failed (discard Adventurer card)\n");
	}
	
	// Check if +1 was added
	if(test2.numActions + 2 == test1.numActions)
		printf("Passed (check Adventurer action)\n");
	else
	{
		failCount++;
		printf("Failed (check Adventurer action)\n");
	}
	
	
	if (failCount == 0)
		printf("******    END Card Test 1: ALL PASSED!     ******\n");
	
	else
		printf("******  END Card Test 1: %d TESTS FAILED!  ******\n\n",failCount);

	return 0;
}