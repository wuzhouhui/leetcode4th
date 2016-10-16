int hIndex(int *citations, int citationsSize)
{
	int l = -1, r = citationsSize;

	while (l + 1 != r) {
		int m = (l + r) / 2;
		if (citations[m] < citationsSize - m)
			l = m;
		else
			r = m;
	}
	if (r == citationsSize || citations[r] < citationsSize - r)
		return(0);
	else
		return(citationsSize - r);
}
main(){}
