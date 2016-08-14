#include <stdlib.h>
#include <string.h>

static char ***res, board[64][64], occupy[64];
static int p, maxp;

static void addans(int n)
{
	int i, j;

	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(n * sizeof(**res));
	for (i = 0; i < n; i++) {
		res[p][i] = calloc((n + 1), sizeof(***res));
		for (j = 0; j < n; j++)
			if (board[i][j])
				res[p][i][j] = 'Q';
			else
				res[p][i][j] = '.';
	}
	p++;
}

static int valid(int n, int r, int c)
{
	int	i, j;

	for (i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return(0);
	for (i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
		if (board[i][j])
			return(0);
	return(1);
}

static void do_queen(int n, int depth)
{
	if (depth >= n) {
		addans(n);
		return;
	}

	int	i;

	for (i = 0; i < n; i++) {
		if (occupy[i])
			continue;
		occupy[i] = 1;
		board[depth][i] = 1;
		if (valid(n, depth, i))
			do_queen(n, depth + 1);
		board[depth][i] = 0;
		occupy[i] = 0;
	}
}

char ***solveNQueens(int n, int *returnSize)
{
	if (n <= 0) {
		*returnSize = 0;
		return(NULL);
	}
	maxp = p = 0;
	res = 0;
	memset(board, 0, sizeof(board));
	memset(occupy, 0, sizeof(occupy));
	do_queen(n, 0);
	*returnSize = p;
	return(res);
}

int main(void)
{
	int n;
	char ***res = solveNQueens(2, &n);
	return(0);
}
