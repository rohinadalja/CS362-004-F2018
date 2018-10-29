/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Unit Test 4 for Checking Correct Player Turn
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
	struct gameState test1;
	struct gameState test2;
	test1.whoseTurn = 1;
	test2.whoseTurn = 2;
	int failCount = 0;

	printf("\n******  START Unit Test 4: Card Cost Function  ******\n");
	
	if(whoseTurn(&test1) == 1)
		printf("Passed Test #1\n");
	else
	{
		printf("Failed Test #1\n");
		failCount++;
	}
	
	
	if(whoseTurn(&test2) == 2)
		printf("Passed Test #2\n");
	else
	{
		printf("Failed Test #2\n");
		failCount++;
	}

	struct gameState test3;
	test3.whoseTurn = 3;

	if(whoseTurn(&test3) == 3)
		printf("Passed Test #3\n");
	else
	{
		printf("Failed Test #3\n");
		failCount++;
	}

	if (failCount == 0)
		printf("\n******    END Unit Test 4: ALL PASSED!     ******\n");
	else
		printf("\n******  END Unit Test 4: %d TESTS FAILED!  ******\n\n",failCount);

	return 0;

}