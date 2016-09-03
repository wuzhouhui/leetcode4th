struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
	if (root == 0)
		return(0);
	int l = minDepth(root->left);
	int r = minDepth(root->right);
	if (((root->left != 0) ^ (root->right != 0)) == 0)
		return(l < r ? ++l : ++r);
	else
		return(l != 0 ? ++l : ++r);
}

main(){}
