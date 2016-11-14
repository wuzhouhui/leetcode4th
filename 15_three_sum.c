#include <stdlib.h>

static int **res, p, maxp;

static int cmpfun(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void addone(int a, int b, int c)
{
	int i;

	for (i = 0; i < p; i++)
		if (res[i][0] == a && res[i][1] == b && res[i][2] == c)
			return;
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(3 * sizeof(**res));
	res[p][0] = a;
	res[p][1] = b;
	res[p][2] = c;
	p++;
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	int i, j, k;

	res = NULL;
	maxp = p = 0;
	qsort(nums, numsSize, sizeof(nums[0]), cmpfun);
	for (i = 0; i < numsSize - 2; i++) {
		for (j = i + 1, k = numsSize - 1; j < k; ) {
			int t = nums[i] + nums[j] + nums[k];
			if (t == 0) {
				addone(nums[i], nums[j], nums[k]);
				j++;
			} else if (t < 0)
				j++;
			else
				k--;
		}
	}
	*returnSize = p;
	return(res);
}
main(){}
