#ifndef bool
#define bool int
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_valid(const struct TreeNode *root, int *max, int *min)
{
	if (root == 0)
		return(1);

	int tmax, tmin;

	*max = *min = root->val;
	if (root->left) {
		if (do_valid(root->left, &tmax, &tmin) == 0)
			return(0);
		if (tmax >= root->val)
			return(0);
		if (tmax > *max)
			*max = tmax;
		if (tmin < *min)
			*min = tmin;
	}
	if (root->right) {
		if (do_valid(root->right, &tmax, &tmin) == 0)
			return(0);
		if (tmin <= root->val)
			return(0);
		if (tmax > *max)
			*max = tmax;
		if (tmin < *min)
			*min = tmin;
	}
	return(1);
}

bool isValidBST(struct TreeNode *root)
{
	int max, min;
	return(do_valid(root, &max, &min));
}

main(){}
