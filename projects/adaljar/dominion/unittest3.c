/********************************************************************
* Name: Rohin Adalja
* Date: October 27th, 2018
* Desc: Dominion Assignment 3: Unit Test 3 for the getCost function
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
	int failCount = 0, i = 0;
 	printf("\n******  START Unit Test 3: Card Cost Function  ******\n");
	
	for (i = 0; i < 27; i++)
	{
		if(i == 0)		
		{
			if (getCost(i) == 0)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 1)	
		{
			if (getCost(i) == 2)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 2)	
		{
			if (getCost(i) == 5)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 3)	
		{
			if (getCost(i) == 8)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 4)	
		{
			if (getCost(i) == 0)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 5)	
		{
			if (getCost(i) == 3)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 6)	
		{
			if (getCost(i) == 6)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 7)	
		{
			if (getCost(i) == 6)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 8)	
		{
			if (getCost(i) == 5)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 9)	
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 10)	
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 11)	
		{
			if (getCost(i) == 5)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 12)	
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 13)
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 14)	
		{
			if (getCost(i) == 3)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 15)	
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 16)	
		{
			if (getCost(i) == 3)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 17)	
		{
			if (getCost(i) == 5)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 18)	
		{
			if (getCost(i) == 3)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 19)	
		{
			if (getCost(i) == 5)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 20)	
		{
			if (getCost(i) == 3)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 21)	
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 22)	
		{
			if (getCost(i) == 2)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 23)	
		{
			if (getCost(i) == 5)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 24)
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 25)	
		{
			if (getCost(i) == 4)
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
		else if (i == 26)
		{
			if (getCost(i) == 4)	
				printf("Passed Test (Card %d)\n", i+1);
			else
			{
				printf("Failed Test (Card %d)\n", i+1);
				failCount++;
			}
		}
	}
	 
	if (failCount == 0)
		printf("\n******    END Unit Test 3: ALL PASSED!     ******\n");
	else
		printf("\n******  END Unit Test 3: %d TESTS FAILED!  ******\n\n",failCount);	

	return 0;
}

