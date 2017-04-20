class Solution extends GuessGame {
	public int guessNumber(int n) {
		int low = 1;
		while (true) {
			int m = low + (n - low) / 2;
			int r = super.guess(m);
			if (r == 0)
				return m;
			if (r > 0)
				low = m + 1;
			else
				up = m - 1;
		}
	}
}
