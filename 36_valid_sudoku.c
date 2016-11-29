#include <string.h>

#ifndef bool
#define bool int
#endif

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	int i, j, m, n;
	int count[9];

	for (i = 0; i < 9; i++) {
		memset(count, 0, sizeof(count));
		for (j = 0; j < 9; j++)
			if (board[i][j] == '.')
				continue;
			else if (board[i][j] < '1' || board[i][j] > '9')
				return(0);
			else if (++count[board[i][j] - '1'] > 1)
				return(0);
	}

	for (i = 0; i < 9; i++) {
		memset(count, 0, sizeof(count));
		for (j = 0; j < 9; j++)
			if (board[j][i] == '.')
				continue;
			else if (board[j][i] < '1' || board[j][i] > '9')
				return(0);
			else if (++count[board[j][i] - '1'] > 1)
				return(0);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			memset(count, 0, sizeof(count));
			for (m = 3 * i; m < 3 * i + 3; m++)
				for (n = 3 * j; n < 3 * j + 3; n++)
					if (board[m][n] == '.')
						continue;
					else if (++count[board[m][n] - '1'] > 1)
						return(0);
		}
	}

	return(1);
}
main(){}
