struct validx {
	int	val;
	int	idx;
};

#ifndef bool
#define bool int
#endif

static int cmpfun(const void *a, const void *b)
{
	const struct validx *p1 = a;
	const struct validx *p2 = b;
	if (p1->val != p2->val)
		return(p1->val - p2->val);
	else
		return(p1->idx - p2->idx);
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
	if (numsSize <= 1)
		return(0);

	struct validx arr[numsSize];
	int	i;

	for (i = 0; i < numsSize; i++) {
		arr[i].val = nums[i];
		arr[i].idx = i;
	}
	qsort(arr, numsSize, sizeof(arr[0]), cmpfun);

	for (i = 0; i < numsSize; ) {
		struct validx prev = arr[i++];
		for (; i < numsSize && arr[i].val == prev.val; i++) {
			if (arr[i].idx - prev.idx <= k)
				return(1);
			else
				prev = arr[i];
		}
	}

	return(0);
}
main(){}
