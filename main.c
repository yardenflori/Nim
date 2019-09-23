#include <stdio.h>
#include <stdlib.h>
#include "main_aux.h"
#include "sp_nim.h"
#include "SPBufferset.h"

#define SIZE 32

void foo(char* str) {
char* temp = NULL;
if (str[0] == 'a') {
free(NULL);
} else if (str[0] == 'b') {
while (1) {
}
} else if (str[0] == 'c') {
putchar(*temp);
} else {
putchar(str[3]);
}}

int main()
{
	int arr[4] = { 'a', 'b', 'c', 'd' };
	foo((char*)arr+1);
	return 0;

	int isUserTurn;
	int numberOfHeaps, turnNumber;
	int sizeOfHeaps[32];
	InitZerosToArray(sizeOfHeaps, 32);

	setbuf(stdout, NULL);
	isUserTurn=1;
	turnNumber=0;

	numberOfHeaps = GetNumberOfHeapsFromUser();

	if(numberOfHeaps != 0) /*if numberOfHeaps valid continue*/
	{
		if(SetSizeOfHeaps(numberOfHeaps, sizeOfHeaps)) /*if success set heap sizes continue*/
		{
			while(!CheckForWinner(sizeOfHeaps, !isUserTurn)) /*play until someone win*/
			{
				turnNumber++;
				PrintHeapSizes(sizeOfHeaps, numberOfHeaps, turnNumber);

				if(isUserTurn)
				{
					if(UserTurn(sizeOfHeaps)==0)
					{
						return 0;
					}
				}

				else
				{

					ComputerTurn(sizeOfHeaps);
				}

				isUserTurn=1-isUserTurn;
			}
		}
	}
	return 0;
}
