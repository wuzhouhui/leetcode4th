#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int *res = malloc(sizeof(*res) << 1);
	int low, high;

	*returnSize = 2;
	low = -1;
	high = numsSize;
	while (low + 1 != high) {
		int mid = (low + high) / 2;
		if (nums[mid] < target)
			low = mid;
		else
			high = mid;
	}

	if (high == numsSize || nums[high] != target) {
		res[0] = res[1] = -1;
		return(res);
	}

	res[0] = high;
	low = -1;
	high = numsSize;
	while (low + 1 != high) {
		int mid = (low + high) / 2;
		if (nums[mid] > target)
			high = mid;
		else
			low = mid;
	}
	res[1] = low;
	return(res);
}
main(){}
