#include <stdlib.h>

struct validx {
	int val, idx;
};

static int cmpfun(const void *a, const void *b)
{
	return(((struct validx *)a)->val - ((struct validx *)b)->val);
}

int *twoSum(int *nums, int numsSize, int target)
{
	int	i, j;
	struct validx validx[numsSize];

	for (i = 0; i < numsSize; i++) {
		validx[i].val = nums[i];
		validx[i].idx = i;
	}

	qsort(validx, numsSize, sizeof(validx[0]), cmpfun);
	i = 0;
	j = numsSize - 1;
	while (i < j) {
		numsSize = validx[i].val + validx[j].val;
		if (numsSize == target) {
			int *res = malloc(sizeof(*res) << 1);
			res[0] = validx[i].idx;
			res[1] = validx[j].idx;
			return(res);
		} else if (numsSize < target)
			i++;
		else
			j--;
	}
	return(0);
}
main(){}
