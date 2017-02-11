#include <stdlib.h>
#include <string.h>

static int **res, *col, p, maxp;
static int *buf, bufp, buflen;

static int cmpfn(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void addbuf(int d)
{
	if (bufp >= buflen) {
		buflen += 8;
		buf = realloc(buf, buflen * sizeof(*buf));
	}
	buf[bufp++] = d;
}

static void addans(void)
{
	int i;

	for (i = 0; i < p; i++)
		if (!memcmp(res[i], buf, bufp * sizeof(*buf)))
			return;
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
		col = realloc(col, maxp * sizeof(*col));
	}
	col[p] = bufp;
	res[p] = malloc(bufp * sizeof(**res));
	memcpy(res[p], buf, bufp * sizeof(*buf));
	p++;
}

static void do_comb(int *candidates, int candidatesSize, int start,
		int cursum, int target)
{
	if (start >= candidatesSize || cursum > target)
		return;

	if (cursum + candidates[start] <= target) {
		cursum += candidates[start];
		addbuf(candidates[start]);
		if (cursum == target)
			addans();
		else
			do_comb(candidates, candidatesSize, start + 1,
					cursum, target);
		bufp--;
		cursum -= candidates[start];
	}
	do_comb(candidates, candidatesSize, start + 1, cursum, target);
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	res = NULL;
	buf = col = NULL;
	p = maxp = bufp = buflen = 0;
	qsort(candidates, candidatesSize, sizeof(candidates[0]), cmpfn);
	do_comb(candidates, candidatesSize, 0, 0, target);
	*columnSizes = col;
	*returnSize = p;
	if (buf)
		free(buf);
	return(res);
}

int main(void)
{
}
