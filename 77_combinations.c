#include <stdlib.h>
#include <string.h>

static int **res, *col;
static int p, maxp;

static void addans(const int *buf, int l)
{
	if (p >= maxp) {
		maxp += 8;
		col = realloc(col, maxp * sizeof(*col));
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(l * sizeof(*buf));
	memcpy(res[p], buf, l * sizeof(*buf));
	col[p++] = l;
}

static void do_comb(int n, int k, int start, int dep, int *buf)
{
	if (dep >= k) {
		addans(buf, k);
		return;
	}
	for (; start <= n && n - start + 1 >= k - dep; start++) {
		buf[dep] = start;
		do_comb(n, k, start + 1, dep + 1, buf);
	}
}

int **combine(int n, int k, int **columnsizes, int *returnSize)
{
	if (n < 1 || k < 1) {
		*columnsizes = 0;
		*returnSize = 0;
		return(0);
	}

	int *buf = malloc(k * sizeof(*buf));
	maxp = p = 0;
	res = 0;
	col = 0;
	do_comb(n, k, 1, 0, buf);
	*columnsizes = col;
	*returnSize = p;
	free(buf);
	return(res);
}

int main(void)
{
	int *col, n;
	int **res = combine(4, 2, &col, &n);
	return(0);
}
