#ifndef bool
#define bool int
#endif

bool checkRecord(char *s)
{
	int i, acnt = 0;

	for (i = 0; s[i]; i++) {
		if (s[i] == 'A') {
			if (++acnt > 1)
				return(0);
			else
				continue;
		}
		if (s[i] != 'L')
			continue;
		if (i > 1 && s[i - 1] == 'L' && s[i - 2] == 'L')
			return(0);
	}

	return(1);
}

main(){}
