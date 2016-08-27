#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int **res, *col;
static int p, maxp;

static void addans(const int *buf, int len)
{
	int i;

	for (i = 0; i < p; i++) {
		if (col[i] != len)
			continue;
		if (!memcmp(res[i], buf, len * sizeof(*buf)))
			return;
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
		col = realloc(col, maxp * sizeof(*col));
	}
	if (len <= 0) {
		res[p] = 0;
		col[p++] = 0;
		return;
	}
	res[p] = malloc(len * sizeof(*buf));
	memcpy(res[p], buf, len * sizeof(*buf));
	col[p++] = len;
}

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int **subsetsWithDup(int *nums, int numsSize, int **columnSizes,
		int *returnSize)
{
	if (numsSize <= 0) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	int buf[numsSize], bufp;
	int tot = 1 << numsSize;
	uint32_t set;
	int i;

	res = 0;
	col = 0;
	maxp = p = 0;
	qsort(nums, numsSize, sizeof(*nums), cmp);
	for (set = 0; set < tot; set++) {
		bufp = 0;
		for (i = 0; i < numsSize; i++)
			if (set & (1 << i))
				buf[bufp++] = nums[i];
		addans(buf, bufp);
	}
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

main(void)
{
	int arr[] = { 1, };
	int *col, n;
	int **res = subsetsWithDup(arr, 1, &col, &n);
}
