#ifndef bool
#define bool int
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_sym(const struct TreeNode *lroot,
		const struct TreeNode *rroot)
{
	if (lroot == 0 && rroot == 0)
		return(1);
	if (lroot == 0 || rroot == 0)
		return(0);
	if (lroot->val != rroot->val)
		return(0);
	return(do_sym(lroot->left, rroot->right) &&
			do_sym(lroot->right, rroot->left));
}

bool isSymmetric(struct TreeNode *root)
{
	return(do_sym(root, root));
}

main(){}
