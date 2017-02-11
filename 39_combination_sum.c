#include <stdlib.h>
#include <string.h>

static int **res, *col, p, maxp;
static int *buf, buflen;

static int cmpfn(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void addbuf(int d, int pos)
{
	if (pos >= buflen) {
		buflen += 8;
		buf = realloc(buf, buflen * sizeof(*buf));
	}
	buf[pos] = d;
}

static void addans(int len)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
		col = realloc(col, maxp * sizeof(*col));
	}
	col[p] = len;
	res[p] = malloc(len * sizeof(**res));
	memcpy(res[p], buf, len * sizeof(*buf));
	p++;
}

static void do_comb(int *candidates, int candidatesSize, int start,
		int cursum, int target, int bufpos)
{
	int t;

	if (start >= candidatesSize)
		return;

	for (t = 0; ; t = candidates[start]) {
		cursum += t;
		if (t)
			addbuf(candidates[start], bufpos++);
		if (cursum < target)
			do_comb(candidates, candidatesSize, start + 1, cursum,
					target, bufpos);
		else if (cursum == target)
			addans(bufpos);
		else
			break;
	}
}

int **combinationSum(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	res = NULL;
	buf = col = NULL;
	p = maxp = buflen = 0;
	qsort(candidates, candidatesSize, sizeof(candidates[0]), cmpfn);
	do_comb(candidates, candidatesSize, 0, 0, target, 0);
	*columnSizes = col;
	*returnSize = p;
	if (buf)
		free(buf);
	return(res);
}

int main(void)
{
	int a[] = { 7, 3, 2, };
	int **res, *col, n;
	res = combinationSum(a, 3, 18, &col, &n);
}
