#include <stdlib.h>

static int p, maxp, *res;

static void add(int a)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = a;
}

static void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int *findDuplicates(int *nums, int numsSize, int *returnSize)
{
	if (numsSize <= 0) {
		*returnSize = 0;
		return(NULL);
	}

	int i;

	res = NULL;
	maxp = p = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] == i + 1)
			continue;
		while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
			swap(&nums[i], &nums[nums[i] - 1]);
	}
	for (i = 0; i < numsSize; i++)
		if (nums[i] != i + 1)
			add(nums[i]);
	*returnSize = p;
	return(res);
}

int main(void)
{
}
