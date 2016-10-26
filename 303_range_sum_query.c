#include <stdlib.h>

struct NumArray {
	int	*sum;
	void	*data;
};

struct NumArray *NumArrayCreate(int *nums, int numsSize)
{
	int	i;
	struct NumArray *res = malloc(sizeof(*res));

	res->data = calloc(numsSize + 1, sizeof(*nums));
	res->sum = (int *)res->data + 1;
	for (i = 0; i < numsSize; i++)
		res->sum[i] = res->sum[i - 1] + nums[i];
	return(res);
}

int sumRange(struct NumArray *numArray, int i, int j)
{
	return(numArray->sum[j] - numArray->sum[i - 1]);
}

void NumArrayFree(struct NumArray *numArray)
{
	free(numArray->data);
	free(numArray);
}
main(){}
