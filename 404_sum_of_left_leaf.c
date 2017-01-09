struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int res = 0;

static void do_sum(const struct TreeNode *root, const struct TreeNode *par)
{
	if (!root)
		return;
	if (!root->left && !root->right && par && par->left == root)
		res += root->val;
	do_sum(root->left, root);
	do_sum(root->right, root);
}

int sumOfLeftLeaves(struct TreeNode *root)
{
	res = 0;
	do_sum(root, 0);
	return(res);
}

main(){}
