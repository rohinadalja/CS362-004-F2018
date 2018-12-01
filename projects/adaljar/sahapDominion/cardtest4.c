/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Card Test 4 - Village Card
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
    int player=0;
	struct gameState test1, test2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &test1);

	printf("\n******  START Card Test 4: Village Card  ******\n\n");

	memcpy(&test2, &test1, sizeof(struct gameState));
	cardEffect(village, choice1, choice2, choice3, &test1, handpos, &bonus);

	player = whoseTurn(&test2);
	
	if(test1.hand[player][test2.handCount[player] -1] != -1) 	// Check player hand
		printf("Passed (Village card added to the player's hand)\n");
	else
	{
		failCount++;
		printf("Failed (adding Village card to player's hand)\n");
	}

	
	if(test2.playedCardCount +1 == test1.playedCardCount) 		// Check if Village was played
		printf("Passed (player played Village card)\n");
	else
	{
		failCount++;
		printf("Failed (player did not play Village card)\n");
	}
		
		
	if(test2.discardCount[player] == test1.discardCount[player]) // Check if card was discarded
		printf("Passed (Village card was discarded)\n");	
	else
	{
		failCount++;
		printf("Failed (Village card was not discarded)\n");
	}
	
	
	if(test2.numActions +2 == test1.numActions)					// Check action was added
		printf("Passed (Village card action test)\n");
	else
	{
		failCount++;
		printf("Failed (Village card action test)\n");
	}
	

	if (failCount == 0)
		printf("******    END Card Test 4: ALL PASSED!     ******\n");
	
	else
		printf("******  END Card Test 4: %d TESTS FAILED!  ******\n\n",failCount);

	return 0;
}