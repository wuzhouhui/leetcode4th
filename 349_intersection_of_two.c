#include <stdlib.h>

static int cmpfn(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static int *res, p, maxp;

static void add(int v)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = v;
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
		int *returnSize)
{
	res = NULL;
	maxp = p = 0;
	qsort(nums1, nums1Size, sizeof(*nums1), cmpfn);
	qsort(nums2, nums2Size, sizeof(*nums2), cmpfn);
	while (nums1Size > 0 && nums2Size > 0) {
		if (*nums1 < *nums2) {
			nums1++;
			nums1Size--;
		} else if (*nums1 > *nums2) {
			nums2++;
			nums2Size--;
		} else {
			if (p <= 0 || *nums1 != res[p - 1])
				add(*nums1);
			nums1++, nums2++;
			nums1Size--, nums2Size--;
		}
	}
	*returnSize = p;
	return(res);
}

main(){}
