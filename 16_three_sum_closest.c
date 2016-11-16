#include <stdlib.h>

static int cmpfun(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	qsort(nums, numsSize, sizeof(nums[0]), cmpfun);

	int mindiff = -1;
	int sum = 0;
	int i, j, k;

	for (i = 0; i < numsSize; i++) {
		for (j = i + 1, k = numsSize - 1; j < k; ) {
			int t = nums[i] + nums[j] + nums[k];
			long long diff = llabs(t - target);
			if (diff < mindiff || mindiff < 0) {
				mindiff = diff;
				sum = t;
			}
			if (t == target)
				break;
			else if (t > target)
				k--;
			else
				j++;
		}
	}
	return(sum);
}
main(){}
