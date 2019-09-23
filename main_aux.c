/*
 * main_aux.c
 *
 *  Created on: 20 באפר׳ 2019
 *      Author: yarden.flori
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int GetNumberOfHeapsFromUser() /*get from user number of heaps*/
{
	int numberOfHeaps=0;

	printf("Enter the number of heaps:\n");

	scanf("%d", &numberOfHeaps);

	if (numberOfHeaps < 1 || numberOfHeaps > 32) /* number of heaps must be between 1 to 32*/
	{
		printf("Error: the number of heaps must be between 1 and 32.\n"); /*if not, error*/
		return 0;
	}

		return numberOfHeaps; /*else, valid input*/
}

int SetSizeOfHeaps(int numberOfHeaps, int *sizeOfHeaps) /*user sets the heaps sizes*/
{
	int size = 0, i;
	printf("Enter the heap sizes:\n");
	for(i=1; i <= numberOfHeaps; i++) /*run number of heaps times*/
	{
		scanf("%d", &size);
		if(size < 1)
		{
			printf("Error: the size of heap %d should be positive.\n", i); /*if scanf failed, or input<1, error*/
			return 0;
		}

		*sizeOfHeaps=size; /*valid input, set heap size*/
		sizeOfHeaps++;
		size = 0;
	}

	return 1;

}

void PrintHeapSizes(int *sizeOfHeaps,int numberOfHeaps,int turnNumber) /*print heap sizes*/
{
	int i;
	printf("In turn %d heap sizes are:", turnNumber);
	for(i=1; i<=numberOfHeaps; i++)
	{
		printf(" h%d=%d", i, *sizeOfHeaps);
		sizeOfHeaps++;
	}
	printf(".\n");
}

void InitZerosToArray(int *array, int size)
{
	int i;
	for(i=0; i<size ; i++)
	{
		array[i]=0;
	}
}
