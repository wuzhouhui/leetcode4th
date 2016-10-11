#include <string.h>

#ifndef bool
#define bool int
#endif

bool isAnagram(char *s, char *t)
{
	int scnt[26] = { 0 };
	int tcnt[26] = { 0 };

	while (*s)
		scnt[*s++ - 'a']++;
	while (*t)
		tcnt[*t++ - 'a']++;
	return(!memcmp(scnt, tcnt, sizeof(scnt)));
}
main(){}
