int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize <= 1)
		return(0);

	int sum = 0;
	int i, j;

	for (i = 0; i < pricesSize; ) {
		for (j = i + 1; j < pricesSize; j++)
			if (prices[j] >= prices[j - 1])
				continue;
			else
				break;
		sum += prices[j - 1] - prices[i];
		i = j;
	}

	return(sum);
}
main()
{
	int arr[] = { 1, 4, 2, };
	return(maxProfit(arr, 3));
}
