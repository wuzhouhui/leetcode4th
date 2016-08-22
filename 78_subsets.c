#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int **res, *col;
int next;

static void addans(const int *buf, int len)
{
	if (len <= 0) {
		res[next] = 0;
		col[next++] = 0;
		return;
	}
	res[next] = malloc(len * sizeof(*buf));
	memcpy(res[next], buf, len * sizeof(*buf));
	col[next++] = len;
}

int **subsets(int *nums, int numsSize, int **columnSizes, int *returnSize)
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

	res = malloc(tot * sizeof(*res));
	col = malloc(tot * sizeof(*col));
	next = 0;
	for (set = 0; set < tot; set++) {
		bufp = 0;
		for (i = 0; i < numsSize; i++)
			if (set & (1 << i))
				buf[bufp++] = nums[i];
		addans(buf, bufp);
	}
	*columnSizes = col;
	*returnSize = next;
	return(res);
}

main(void)
{
	int arr[] = { 1, };
	int *col, n;
	int **res = subsets(arr, 1, &col, &n);
}
