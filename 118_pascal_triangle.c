#include <stdlib.h>

int **generate(int numRows, int **columnSizes)
{
	if (numRows <= 0) {
		*columnSizes = 0;
		return(0);
	}

	int **res = malloc(numRows * sizeof(*res));
	int *col = malloc(numRows * sizeof(*col));
	int i, j;

	for (i = 1; i <= numRows; i++) {
		res[i - 1] = malloc(i * sizeof(**res));
		col[i - 1] = i;
		for (j = 1; j <= i; j++) {
			if (j == 1 || j == i)
				res[i - 1][j - 1] = 1;
			else
				res[i - 1][j - 1] = res[i - 2][j - 2] +
					res[i - 2][j - 1];
		}
	}
	*columnSizes = col;
	return(res);
}
main(){}
