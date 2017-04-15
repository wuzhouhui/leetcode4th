void do_rev(char *s, int i, int j)
{
	while (i < j) {
		int c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++, j--;
	}
}

char *reverseStr(char *s, int k)
{
	int i, j, n = k * 2;

	for (i = 0; s[i]; ) {
		for (j = 0; j < n && s[i + j]; j++)
			;
		if (j < k)
			do_rev(s, i, i + j - 1);
		else
			do_rev(s, i, i + k - 1);
		i += j;
	}
	return(s);
}
main(void)
{
}
