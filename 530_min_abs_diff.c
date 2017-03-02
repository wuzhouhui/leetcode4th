#include <limits.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static do_get(struct TreeNode *root, int **prev, int *min)
{
	if (root == 0)
		return;
	do_get(root->left, prev, min);
	if (*prev) {
		int t = root->val - **prev;
		if (t < *min)
			*min = t;
	}
	*prev = &root->val;
	do_get(root->right, prev, min);
}

int getMinimumDifference(struct TreeNode *root)
{
	int min = INT_MAX;
	int *prev = 0;
	do_get(root, &prev, &min);
	return(min);
}

main(){}
