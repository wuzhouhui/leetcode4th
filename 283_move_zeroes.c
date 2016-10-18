#include <string.h>

void moveZeroes(int *nums, int numsSize)
{
	int i, j;

	for (i = 0, j = -1; i < numsSize; i++) {
		if (nums[i] == 0)
			continue;
		else
			nums[++j] = nums[i];
	}
	j++;
	memset(nums + j, 0, (numsSize - j) * sizeof(int));
}
main(){}
