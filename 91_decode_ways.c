#include <string.h>

int numDecodings(char *s)
{
	if (s == 0 || *s == 0)
		return(0);

	int len = strlen(s), i;
	int dp[len];

	for (i = 0; s[i]; i++) {
		if (i > 1) {
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2')
					dp[i] = dp[i - 2];
				else
					return(0);
			} else {
				if (s[i - 1] == '1')
					dp[i] = dp[i - 2] + dp[i - 1];
				else if (s[i - 1] == '2' && s[i] >= '1' &&
						s[i] <= '6')
					dp[i] = dp[i - 2] + dp[i - 1];
				else
					dp[i] = dp[i - 1];
			}
		} else if (i == 1) {
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2')
					dp[i] = 1;
				else
					return(0);
			} else {
				if (s[i - 1] == '1')
					dp[i] = 2;
				else if (s[i - 1] == '2' && s[i] >= '1' &&
						s[i] <= '6')
					dp[i] = 2;
				else
					dp[i] = 1;
			}
		} else {
			if (s[i] == '0')
				return(0);
			else
				dp[i] = 1;
		}
	}
	return(dp[len - 1]);
}

int main(void)
{
	return(numDecodings("123"));
}
