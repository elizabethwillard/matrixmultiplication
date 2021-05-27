/************************************************************
*   Elizabeth Willard 2/27/2020 ECE331 mmult program        *
*   This is a program to multiply two matrices together     *
*   The sizes of each matrice need to be passed on the      *
*   command line.                                           *
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "mmult.h"


MMULT *calc_mmult(MMULT *a, MMULT *b)
{
	//We dynamically allocate memory to the output struct and its value array
	MMULT *out = (MMULT *)malloc(sizeof(MMULT));
	out->values = (double *)malloc(b->row * a->col *sizeof(double));
	//We give it the final expected dimensions based off of the input matrices
	out->row = a->row;
	out->col = b->col;
	
	//Counters
	int i, j, k;

	//Since we use 1D arrays for our program, we have to algebraically manipulate
	//the array and then store it in a sum value which gets placed in the output
	//value array.
	for(i = 0; i < a->row; i++){
		for(j = 0; j < b->col; j++){
			double sum = 0;
			for(k = 0; k < a->col; k++){
				sum = sum + a->values[i * a->col + k] * b->values[k * b->col + j];
				out->values[i * b->col + j] = sum;
			}
		}		
	}
	//This prints out the array and returns a pointer to the struct to main
	for (i = 0; i < out->row * out->col; i++){
		if (i % out->col == 0){
			printf("\n");
		}
		printf("%lf ", out->values[i]);	
	}
	return(out);
	destroy_mmult(out);
}


void destroy_mmult(MMULT *s){
	free(s->values);
	free(s);
}
