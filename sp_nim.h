/*
 * sp_nim.h
 *
 *  Created on: 24 באפר׳ 2019
 *      Author: yarden.flori
 */

#ifndef SP_NIM_H_
#define SP_NIM_H_

int CheckForWinner(int *sizeOfHeaps, int userTurn);
int UserTurn(int *sizeOfHeaps);
int NimSum (int *sizeOfHeaps);
void ComputerTurn(int *sizeOfHeaps);

#endif /* SP_NIM_H_ */
