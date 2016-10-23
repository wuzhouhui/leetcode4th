static inline int neighbor(int **board, int r, int c, int row, int col)
{
	int res = 0, i, j;

	for (i = r - 1; i <= r + 1; i++)
		for (j = c - 1; j <= c + 1; j++)
			if (i == r && j == c)
				continue;
			else if (i < 0 || i >= row || j < 0 || j >= col)
				continue;
			else
				res += board[i][j] & 1;
	return(res);
}

void gameOfLife(int **board, int boardRowSize, int boardColSize)
{
	int i, j;

	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			int t = neighbor(board, i, j, boardRowSize,
					boardColSize);
			if (board[i][j]) {
				if (t < 2 || t > 3)
					continue;
				else
					board[i][j] |= 2;
			} else if (t == 3)
				board[i][j] |= 2;
		}
	}

	for (i = 0; i < boardRowSize; i++)
		for (j = 0; j < boardColSize; j++)
			board[i][j] >>= 1;
}
main(){}
