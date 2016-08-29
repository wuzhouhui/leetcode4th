#ifndef bool
#define bool int
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == 0 && q == 0)
		return(1);
	if (p == 0 || q == 0)
		return(0);
	if (p->val != q->val)
		return(0);
	if (!isSameTree(p->left, q->left) ||
			!isSameTree(p->right, q->right))
		return(0);
	return(1);
}

main(){}
