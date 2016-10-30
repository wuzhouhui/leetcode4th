int lengthOfLongestSubstring(char *s)
{
	char	count[256] = { 0 };
	int	res = 0;
	int	i, j;

	for (i = j = 0; s[j]; j++) {
		if (++count[s[j]] == 1)
			continue;
		int t = j - i;
		if (t > res)
			res = t;
		while (count[s[i++]]-- == 1)
			;
	}
	j -= i;
	if (j > res)
		res = j;
	return(res);
}
main()
{
	char s[] = "abcabcbb";
	lengthOfLongestSubstring(s);
}
