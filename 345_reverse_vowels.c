#include <string.h>
#include <ctype.h>

static int isvowel(char c)
{
	c = tolower(c);
	return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char *reverseVowels(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (i < j) {
		while (i < j && !isvowel(s[i]))
			i++;
		while (i < j && !isvowel(s[j]))
			j--;
		if (i >= j)
			break;
		int c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++, j--;
	}
	return(s);
}

main(){}
