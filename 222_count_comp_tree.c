struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int countNodes(struct TreeNode *root)
{
	if (!root)
		return(0);

	int lh, rh;
	struct TreeNode *p;

	for (lh = 0, p = root; p; p = p->left)
		lh++;
	for (rh = 0, p = root; p; p = p->right)
		rh++;
	if (lh == rh)
		return((1 << lh) - 1);
	return(countNodes(root->left) + countNodes(root->right) + 1);
}
main(){}
