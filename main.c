/************************************************************
*   Elizabeth Willard 2/27/2020 ECE331 mmult program        *
*   This is a program to multiply two matrices together     *
*   The sizes of each matrice need to be passed on the      *
*   command line.                                           *
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "mmult.h"
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

//The main file will handle error checking and all command line arguments.
int main(int argc, char*argv[])
{
	//Initializing input structs and allocating memory for them
	MMULT *a, *b;
	a = (MMULT *)malloc(sizeof(MMULT));
	b = (MMULT *)malloc(sizeof(MMULT));
		
	int i;
	//This is the only argc case that will work, you need four arguments on the cmd line
	if(argc == 5){
		for(i = 1; i < 5; i++){
			if(!(atoi(argv[i]))){
				printf("You need to use whole numbers only!\n");
				exit(EXIT_FAILURE);		
			}
			if(atoi(argv[i]) < 1) {
				printf("You can only enter in positive numbers!\n");
				exit(EXIT_FAILURE);
			}
		}
		a->row = atoi(argv[1]);
		a->col = atoi(argv[2]);
		b->row = atoi(argv[3]);
		b->col = atoi(argv[4]);
		
		//This error checking makes sure the two input matrices are compatible 
		if(a->col != b->row){
			printf("These matrice arguments do not agree! axb bxc\n");
			exit(EXIT_FAILURE);
		}

		//We need to allocate memory to the values because they are dynamic arrays
		a->values = (double *)malloc(a->row * a->col * sizeof(double));
		b->values = (double *)malloc(b->row * b->col * sizeof(double));
		
		//We want to seed rand so it changes each time the program is executed
		//srand(time(NULL));
		
		//We are storing random values in each input matrice
		for(i = 0; i < a->row * a->col; i++){
			a->values[i] = rand() % 5;
		}
	
		for(i = 0; i < b->row * b->col; i++){
			b->values[i] = rand() % 5 ;
		}
		for (i = 0; i < a->row * a->col; i++){
			if (i % a->col == 0){
				printf("\n");
			}

		printf("%lf ", a->values[i]);	
		}
		printf("\n");
		for (i = 0; i < b->row * b->col; i++){
			if (i % b->col == 0){
				printf("\n");
			}

		printf("%lf ", b->values[i]);	
		}
		struct timespec start, finish;
		printf("\n");
		//This prints the runtime of the program
		clock_gettime(CLOCK_REALTIME, &start);
		calc_mmult(a, b);
		clock_gettime(CLOCK_REALTIME, &finish);
		long seconds = finish.tv_sec - start.tv_sec;
		long ns = finish.tv_nsec - start.tv_nsec;
		printf("\n total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000);
		printf("\n");
		
	}
	else if(argc < 5){
		printf("You have too few arguments!\n");
		exit(EXIT_FAILURE);
	}
	else if(argc > 5){
		printf("You have too many arguments!\n");
		exit(EXIT_FAILURE);
	}
	//Deallocates memory 
	destroy_mmult(a);
	destroy_mmult(b);

}
