void do_rev(char *s, int i, int j)
{
	while (i < j) {
		int c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++, j--;
	}
}

char *reverseWords(char *s)
{
	int i, j;

	for (i = 0; s[i]; ) {
		for (j = i; s[j] && s[j] != ' '; j++)
			;
		do_rev(s, i, j - 1);
		if (s[j] == 0)
			break;
		i = j + 1;
	}
	return(s);
}
main(){}
