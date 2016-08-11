int trap(int *height, int heightSize)
{
	if (heightSize <= 2)
		return(0);
	int left[heightSize], right[heightSize];
	int i, t, res;

	left[0] = right[heightSize - 1] = 0;
	t = height[0];
	for (i = 1; i < heightSize; i++) {
		left[i] = t;
		if (height[i] > t)
			t = height[i];
	}
	t = height[heightSize - 1];
	for (i = heightSize - 2; i >= 0; i--) {
		right[i] = t;
		if (height[i] > t)
			t = height[i];
	}
	res = 0;
	for (i = 1; i < heightSize; i++) {
		t = (left[i] < right[i] ? left[i] : right[i]);
		if ((t -= height[i]) > 0)
			res += t;
	}
	return(res);
}

main(){}
