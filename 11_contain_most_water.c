int maxArea(int *height, int heightSize)
{
	if (heightSize <= 1)
		return(0);

	int res = 0, left = 0;

	heightSize--;
	while (left < heightSize) {
		int t;
		if (height[left] < height[heightSize]) {
			t = height[left] * (heightSize - left);
			left++;
		} else {
			t = height[heightSize] * (heightSize - left);
			heightSize--;
		}
		if (t > res)
			res = t;
	}

	return(res);
}

main(){}
