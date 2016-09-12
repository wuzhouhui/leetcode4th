int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize <= 1)
		return(0);
	int max = 0, i, curmax;

	curmax = prices[pricesSize - 1];
	for (i = pricesSize - 2; i >= 0; i--) {
		int t = curmax - prices[i];
		if (t > max)
			max = t;
		if (prices[i] > curmax)
			curmax = prices[i];
	}
	return(max);
}
main(){}
