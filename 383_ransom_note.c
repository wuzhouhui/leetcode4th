#include <string.h>

#ifndef bool
#define bool int
#endif

bool canConstruct(char *ransomNote, char *magazine)
{
	int cnt[2][256], i;

	memset(cnt, 0, sizeof(cnt));
	while (*ransomNote)
		cnt[0][*ransomNote++]++;
	while (*magazine)
		cnt[1][*magazine++]++;
	for (i = 0; i < 256; i++)
		if (cnt[1][i] < cnt[0][i])
			return(0);
	return(1);
}
main(){}
