#include <stdlib.h>

int *singleNumber(int *nums, int numsSize, int *returnSize)
{
	int *res = calloc(2, sizeof(*res));
	int i, t, bit;

	for (t = i = 0; i < numsSize; i++)
		t ^= nums[i];
	for (bit = 1; (t & bit) == 0; bit <<= 1)
		;
	for (i = 0; i < numsSize; i++)
		if (nums[i] & bit)
			res[0] ^= nums[i];
		else
			res[1] ^= nums[i];
	*returnSize = 2;
	return(res);
}
main(){}
