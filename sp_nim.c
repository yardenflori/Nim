/*
 * sp_num.c
 *
 *  Created on: 20 באפר׳ 2019
 *      Author: yarden.flori
 */
#include <stdio.h>
#include <stdlib.h>

int CheckForWinner(int *sizeOfHeaps, int isUserTurn) /*check if there is a winner this turn*/
{
	int i;

	for(i=0 ; i<32 ; i++)
	{
		if(sizeOfHeaps[i] != 0)
			return 0;
	}
	/*here we know sizeOfHeaps is array of zeros, so we have a winner*/

	isUserTurn == 1 ? printf("You win!\n") : printf("Computer wins!\n");
	return 1;
}

int UserTurn(int *sizeOfHeaps) /*user turn: he choose index of heap and number of objects to remove*/
{
	int firstTime = 1, index=0, removedObjects=0, temp;
	printf("Your turn: please enter the heap index and the number of removed objects:\n");

	while(index < 1 || index >32 ||  *(sizeOfHeaps+index-1)<removedObjects || removedObjects<=0)
	{
		if(!firstTime) /*don't print it before one input passed*/
		{
			printf("ERROR: Invalid input.\nPlease enter again the heap index and the number of removed objects:\n");
		}

		if((temp = scanf("%d %d", &index, &removedObjects))==EOF)
		{
			exit(0);
		}

		firstTime = 0;

		if(temp!=2) /*user didn't pass 2 integers, error*/
		{
			printf("Error: Invalid input.\n");
			return 0;
		}
	}

	*(sizeOfHeaps+index-1)-=removedObjects; /*valid input, remove the objects from the heap*/
	printf("You take %d objects from heap %d.\n", removedObjects, index);
	return 1;

}

int NimSum (int *sizeOfHeaps)
{
	int i;
	int sum = 0;
	for(i = 0 ; i < 32 ; i++)
	{
		sum^=sizeOfHeaps[i];
	}
	return sum;
}

void ComputerTurn(int *sizeOfHeaps)
{
	int indexOfHeap, objectsToRemove;
	int indexOfWinningHeap = 0;
	int nimSum = NimSum(sizeOfHeaps);
	int i;
	indexOfHeap=0;

	if(nimSum!=0)
	{
		for(i=0; i<32;i++)
		{
			if((nimSum^sizeOfHeaps[i])<sizeOfHeaps[i])
			{
				indexOfWinningHeap = i;
				break;
			}
		}
		indexOfHeap=indexOfWinningHeap;
		objectsToRemove=sizeOfHeaps[indexOfHeap]-(nimSum^sizeOfHeaps[indexOfHeap]);
		sizeOfHeaps[indexOfHeap]-=objectsToRemove;
	}

	else
	{
		for(i=0; i<32;i++)
		{
			if(sizeOfHeaps[i]>0)
			{
				indexOfHeap = i;
				break;
			}
		}
		objectsToRemove=1;
		sizeOfHeaps[indexOfHeap]-=objectsToRemove;
	}

	printf("Computer takes %d objects from heap %d.\n", objectsToRemove, indexOfHeap+1);

}


