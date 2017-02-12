#ifndef bool
#define bool int
#endif

bool isPerfectSquare(int num)
{
	if (num == 1)
		return(1);
	int low = 1, high = num;
	while (low < high) {
		long int mid = (high - low) / 2 + low;
		unsigned long long t = mid * mid;
		if (t == num)
			return(1);
		else if (t < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if ((unsigned long long)low * low == num ||
			(unsigned long long)high * high == num)
		return(1);
	else
		return(0);
}
int main()
{
	return(isPerfectSquare(104976));
}
