char findTheDifference(char *s, char *t)
{
	int letters[26] = { 0 };
	int	i;

	for (i = 0; s[i]; i++) {
		letters[s[i] - 'a']++;
		letters[t[i] - 'a']--;
	}
	letters[t[i] - 'a']--;
	for (i = 0; i < 26; i++)
		if (letters[i])
			return(i + 'a');
	return(0);
}

int main(void)
{
	findTheDifference("abcd", "abcde");
}
