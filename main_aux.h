/*
 * main_aux.h
 *
 *  Created on: 22 באפר׳ 2019
 *      Author: yarden.flori
 */

#ifndef MAIN_AUX_H_
#define MAIN_AUX_H_

int GetNumberOfHeapsFromUser();
int SetSizeOfHeaps(int numberOfHeaps, int *sizeOfHeaps);
void PrintHeapSizes(int *sizeOfHeaps,int numberOfHeaps,int turnNumber);
void InitZerosToArray(int *array, int size);

#endif /* MAIN_AUX_H_ */
