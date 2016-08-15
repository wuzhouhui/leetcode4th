#include <string.h>

int lengthOfLastWord(char *s)
{
	if (s == NULL || s[0] == 0)
		return(0);
	int i = strlen(s) - 1, last;

	while (i >= 0 && s[i] == ' ')
		i--;
	if (i < 0)
		return(0);
	last = i--;
	while (i >= 0 && s[i] != ' ')
		i--;
	return(last - i);
}
main(){}
