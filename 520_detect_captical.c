#include <ctype.h>

#ifndef bool
#define bool int
#endif

bool detectCapitalUse(char *word)
{
	int lowcnt = 0, upcnt = 0;
	int i;

	for (i = 0; word[i]; i++)
		if (islower(word[i]))
			lowcnt++;
		else if (isupper(word[i]))
			upcnt++;
		else
			return(0);
	if (lowcnt == 0 || upcnt == 0)
		return(1);
	if (upcnt == 1 && isupper(word[0]))
		return(1);
	return(0);
}

main(){}
