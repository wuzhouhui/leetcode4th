bool isBadVersion(int);

int firstBadVersion(int n)
{
	int l = 0;
	while (l + 1 != n) {
		int m = l + (n - l) / 2;
		if (isBadVersion(m))
			n = m;
		else
			l = m;
	}
	return(n);
}
