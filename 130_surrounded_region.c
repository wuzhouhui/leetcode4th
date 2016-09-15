static void do_solve(char **board, int boardRowSize, int boardColSize,
		int row, int col)
{
	if (row <= 0 || row >= boardRowSize - 1 || col <= 0 ||
			col >= boardColSize - 1)
		return;
	if (board[row][col] != 'O')
		return;
	board[row][col] = 1;
	do_solve(board, boardRowSize, boardColSize, row - 1, col);
	do_solve(board, boardRowSize, boardColSize, row + 1, col);
	do_solve(board, boardRowSize, boardColSize, row, col - 1);
	do_solve(board, boardRowSize, boardColSize, row, col + 1);
}

void solve(char **board, int boardRowSize, int boardColSize)
{
	if (boardRowSize <= 1 || boardColSize <= 1)
		return;

	int i, j;

	for (i = 0; i < boardColSize; i++) {
		if (board[0][i] == 'O') {
			board[0][i] = 1;
			do_solve(board, boardRowSize, boardColSize, 1, i);
		}
		if (board[boardRowSize - 1][i] == 'O') {
			board[boardRowSize - 1][i] = 1;
			do_solve(board, boardRowSize, boardColSize,
					boardRowSize - 2, i);
		}
	}

	for (i = 0; i < boardRowSize; i++) {
		if (board[i][0] == 'O') {
			board[i][0] = 1;
			do_solve(board, boardRowSize, boardColSize, i, 1);
		}
		if (board[i][boardColSize - 1] == 'O') {
			board[i][boardColSize - 1] = 1;
			do_solve(board, boardRowSize, boardColSize, i,
					boardColSize - 2);
		}
	}

	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			else if (board[i][j] == 1)
				board[i][j] = 'O';
		}
	}
}

main(){}
