static void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

static void siftup(int *heap, int n)
{
	int p;
	while (1) {
		p = n / 2;
		if (p <= 0 || heap[p] <= heap[n])
			break;
		swap(&heap[p], &heap[n]);
		n = p;
	}
}

static void siftdown(int *heap, int n)
{
	int p = 1, c;
	while (1) {
		c = p * 2;
		if (c > n)
			break;
		if (c + 1 <= n && heap[c + 1] < heap[c])
			c++;
		if (heap[c] >= heap[p])
			break;
		swap(&heap[p], &heap[c]);
		p = c;
	}
}

int findKthLargest(int *nums, int numsSize, int k)
{
	int heap[numsSize + 1], heapcurlen = 0;
	int i;

	for (i = 0; i < numsSize; i++) {
		if (heapcurlen < k) {
			heap[++heapcurlen] = nums[i];
			siftup(heap, heapcurlen);
		} else if (nums[i] >= heap[1]) {
			heap[1] = nums[i];
			siftdown(heap, heapcurlen);
		}
	}

	return(heap[1]);
}

int main(void)
{
	int arr[] = { 5, 2, 4, 1, 3, 6, 0, };
	findKthLargest(arr, sizeof(arr) / sizeof(arr[0]), 4);
	return(0);
}
