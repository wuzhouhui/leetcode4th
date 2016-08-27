#include <string.h>

void merge(int *nums1, int m, int *nums2, int n)
{
	int buf[m + n];
	int i, j, k;
	for (k = i = j = 0; i < m && j < n; ) {
		if (nums1[i] < nums2[j])
			buf[k++] = nums1[i++];
		else
			buf[k++] = nums2[j++];
	}
	memcpy(&buf[k], &nums1[i], (m - i) * sizeof(nums1[0]));
	memcpy(&buf[k], &nums2[j], (n - j) * sizeof(nums2[0]));
	memcpy(nums1, buf, (m + n) * sizeof(nums1[0]));
}
main(){}
