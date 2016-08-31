#ifndef bool
#define bool int
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_balan(const struct TreeNode *root, int *h)
{
	if (root == 0) {
		*h = 0;
		return(1);
	}
	int l, r;
	if (!do_balan(root->left, &l))
		return(0);
	if (!do_balan(root->right, &r))
		return(0);
	if (l - r < -1 || l - r > 1)
		return(0);
	*h = l > r ? ++l : ++r;
	return(1);
}

bool isBalanced(struct TreeNode *root)
{
	int h;
	return(do_balan(root, &h));
}

main(){}
