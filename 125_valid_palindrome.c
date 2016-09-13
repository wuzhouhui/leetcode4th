#include <ctype.h>

#ifndef bool
#define bool int
#endif

bool isPalindrome(char *s)
{
	if (s == 0)
		return(1);

	int i, j;

	for (i = j = 0; s[i]; i++) {
		if (isalnum(s[i]))
			s[j++] = tolower(s[i]);
	}

	i = 0;
	j--;
	while (i < j)
		if (s[i++] != s[j--])
			return(0);
	return(1);
}
main(){}
