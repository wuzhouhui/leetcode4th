struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_find(const struct TreeNode *root, int *res, int *k)
{
	if (!root)
		return(0);
	if (do_find(root->left, res, k))
		return(1);
	if (--*k == 0) {
		*res = root->val;
		return(1);
	}
	return(do_find(root->right, res, k));
}

int kthSmallest(struct TreeNode *root, int k)
{
	int res;
	do_find(root, &res, &k);
	return(res);
}
main(){}
