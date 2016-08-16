#include <stdlib.h>

int **generateMatrix(int n)
{
	if (n <= 0)
		return(NULL);

	int **res;
	int up, left, down, right, i;


	res = malloc(n * sizeof(*res));
	for (i = 0; i < n; i++)
		res[i] = malloc(n * sizeof(**res));

	up = left = 0;
	down = right = n - 1;
	n = 1;
	while (up < down) {
		for (i = left; i < right; i++)
			res[up][i] = n++;
		for (i = up; i < down; i++)
			res[i][right] = n++;
		for (i = right; i > left; i--)
			res[down][i] = n++;
		for (i = down; i > up; i--)
			res[i][left] = n++;
		up++, left++, right--, down--;
	}
	if (up == down)
		res[up][up] = n++;
	return(res);
}

main(){}
