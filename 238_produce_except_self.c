#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	if (numsSize < 1) {
		*returnSize = 0;
		return(NULL);
	}

	int *res = malloc(numsSize * sizeof(*res));
	int tmp[numsSize];
	int i, prod;

	tmp[0] = 1;
	for (i = 1; i < numsSize; i++)
		tmp[i] = tmp[i - 1] * nums[i - 1];
	for (prod = 1, i = numsSize - 1; i >= 0; i--) {
		res[i] = tmp[i] * prod;
		prod *= nums[i];
	}
	*returnSize = numsSize;
	return(res);
}
main(){}
