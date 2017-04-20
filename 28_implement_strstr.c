/*
 * TODO
 * kmp
 */

int strStr(char *haystack, char *needle)
{
	if (needle[0] == 0)
		return(0);

	int i, j;

	for (i = 0; haystack[i]; i++) {
		for (j = 0; needle[j] && haystack[i + j]; j++)
			if (haystack[i + j] != needle[j])
				break;
		if (needle[j] == 0)
			return(i);
	}

	return(-1);
}

main(){}
