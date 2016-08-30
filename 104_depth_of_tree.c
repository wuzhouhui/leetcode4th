struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
	if (root == 0)
		return(0);
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return(l > r ? ++l : ++r);
}

main(){}
