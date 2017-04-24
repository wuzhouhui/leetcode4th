#include <stdlib.h>

static int cmpfn(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return(-1);
	else if (*(int *)a == *(int *)b)
		return(0);
	return(1);
}

int arrayPairSum(int *nums, int numsSize)
{
	int i, res = 0;

	qsort(nums, numsSize, sizeof(nums[0]), cmpfn);
	for (i = 0; i < (numsSize >> 1); i++)
		res += nums[i << 1];
	return(res);
}

main(){}
