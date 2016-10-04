struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void do_revert(struct TreeNode *root)
{
	if (!root)
		return;
	struct TreeNode *t = root->left;
	root->left = root->right;
	root->right = t;
	do_revert(root->left);
	do_revert(root->right);
}

struct TreeNode *invertTree(struct TreeNode *root)
{
	do_revert(root);
	return(root);
}
main(){}
