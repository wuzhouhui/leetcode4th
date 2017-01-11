#include <stdlib.h>

int *countBits(int num, int *returnSize)
{
	int *res = calloc(num + 1, sizeof(*res));
	int i;

	for (i = 1; i <= num; i++)
		res[i] = res[i >> 1] + (i & 1);
	*returnSize = num + 1;
	return(res);
}
main(){}
