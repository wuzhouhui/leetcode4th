#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *getHint(char *secret, char *guess)
{
	char buf[128] = { 0 };
	int l = strlen(secret);
	int i, j, bulls = 0, cows = 0;

	for (i = 0; i < l; i++)
		if (secret[i] != guess[i])
			continue;
		else {
			bulls++;
			secret[i] = guess[i] = 0;
		}
	for (i = 0; i < l; i++) {
		if (secret[i] == 0)
			continue;
		for (j = 0; j < l; j++) {
			if (guess[j] == 0 || secret[i] != guess[j])
				continue;
			cows++;
			secret[i] = guess[j] = 0;
			break;
		}
	}

	sprintf(buf, "%dA%dB", bulls, cows);
	return(strdup(buf));
}
main(){}
