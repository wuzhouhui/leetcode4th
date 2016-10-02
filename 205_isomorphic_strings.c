#include <string.h>

#ifndef bool
#define bool int
#endif

bool isIsomorphic(char *s, char *t)
{
	char map[256] = { 0 };
	int i;

	for (i = 0; s[i]; i++) {
		if (map[s[i]]) {
			if (map[s[i]] != t[i])
				return(0);
		} else {
			map[s[i]] = t[i];
		}
	}

	memset(map, 0, sizeof(map));
	for (i = 0; t[i]; i++) {
		if (map[t[i]]) {
			if (map[t[i]] != s[i])
				return(0);
		} else {
			map[t[i]] = s[i];
		}
	}

	return(1);
}
main(){}
