#include <string.h>

char *reverseString(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (i < j) {
		int c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++, j--;
	}
	return(s);
}

main(){}
