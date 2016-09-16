static void reverse(char *s, int l, int r)
{
	while (l < r) {
		char c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++, r--;
	}
}

void reverseWords(char *s)
{
	int i, j, prev;

	for (i = j = prev = 0; s[i]; i++) {
		if (s[i] == ' ') {
			if (prev == 0 || prev == ' ')
				continue;
			s[j++] = ' ';
			prev = ' ';
		} else {
			s[j++] = s[i];
			prev = s[i];
		}
	}
	if (j > 0 && s[j - 1] == ' ')
		j--;
	s[j] = 0;
	reverse(s, 0, j - 1);
	for (i = 0; s[i]; ) {
		int start = i++;
		while (s[i] && s[i] != ' ')
			i++;
		reverse(s, start, i - 1);
		if (s[i] == ' ')
			i++;
	}
}
int main(void)
{
	char arr[] = " a  b  ";
	reverseWords(arr);
}
