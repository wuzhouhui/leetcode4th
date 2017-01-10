int firstUniqChar(char *s)
{
	struct {
		int pos;
		int cnt;
	} letters[256];
	int res, i;

	for (i = 0; i < 256; i++) {
		letters[i].pos = -1;
		letters[i].cnt = 0;
	}
	for (i = 0; s[i]; i++) {
		letters[s[i]].cnt++;
		if (letters[s[i]].pos < 0)
			letters[s[i]].pos = i;
	}
	for (res = -1, i = 0; i < 256; i++) {
		if (letters[i].cnt != 1)
			continue;
		if (res < 0 || letters[i].pos < res)
			res = letters[i].pos;
	}
	return(res);
}

main(){}
