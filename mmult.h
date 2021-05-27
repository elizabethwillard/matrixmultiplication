//Elizabeth Willard 2/26/2020
//

#ifndef MMULT_H
#define MMULT_H

typedef struct mmult_struct {
	int row, col;
	double *values;

}MMULT;

MMULT *calc_mmult(MMULT *a, MMULT *b);

void destroy_mmult(MMULT *s);

#endif

