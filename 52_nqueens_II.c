#include <stdlib.h>
#include <string.h>

static char board[64][64], occupy[64];
static int res;

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
		res++;
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

int totalNQueens(int n)
{
	if (n <= 0)
		return(0);
	res = 0;
	memset(board, 0, sizeof(board));
	memset(occupy, 0, sizeof(occupy));
	do_queen(n, 0);
	return(res);
}

int main(void)
{
	return(0);
}
