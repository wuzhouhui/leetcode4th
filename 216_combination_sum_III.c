#include <stdlib.h>
#include <string.h>

static int **res, *col, p, maxp;

static void addans(int k, int *buf)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
		col = realloc(col, maxp * sizeof(*col));
	}
	col[p] = k;
	res[p] = malloc(k * sizeof(**res));
	memcpy(res[p], buf, k * sizeof(*buf));
	p++;
}

static void do_sum(int k, int tgt, int sum, int start, int dep, int *buf)
{
	int i;

	if (dep >= k || start > 9) {
		if (dep >= k && sum == tgt)
			addans(k, buf);
		return;
	}

	for (i = start; i < 10; i++) {
		int t = sum + i;
		if (t > tgt)
			break;
		buf[dep] = i;
		do_sum(k, tgt, t, i + 1, dep + 1, buf);
	}
}

int **combinationSum3(int k, int n, int **columnSizes, int *returnSize)
{
	int buf[k];

	res = 0;
	col = 0;
	p = maxp = 0;
	do_sum(k, n, 0, 1, 0, buf);
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

main()
{
	int *col, n;
	combinationSum3(3, 7, &col, &n);
}
