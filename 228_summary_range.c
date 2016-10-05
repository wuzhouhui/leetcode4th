#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char **res;
static int p, maxp;

static void addrange(int start, int end)
{
	static char buf[64];

	if (start == end)
		sprintf(buf, "%d", start);
	else
		sprintf(buf, "%d->%d", start, end);
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = strdup(buf);
}

char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
	int i;

	res = NULL;
	p = maxp = 0;
	for (i = 0; i < numsSize; ) {
		int start = nums[i++];
		while (i < numsSize && nums[i] == nums[i - 1] + 1)
			i++;
		int end = nums[i - 1];
		addrange(start, end);
	}

	*returnSize = p;
	return(res);
}
main(){}
