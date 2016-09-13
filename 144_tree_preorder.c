#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int *res, reslen, maxreslen;

static void add(int v)
{
	if (reslen >= maxreslen) {
		maxreslen += 8;
		res = realloc(res, maxreslen * sizeof(*res));
	}
	res[reslen++] = v;
}

static void do_preorder(const struct TreeNode *root)
{
	if (root == NULL)
		return;
	add(root->val);
	do_preorder(root->left);
	do_preorder(root->right);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
	res = NULL;
	reslen = maxreslen = 0;
	do_preorder(root);
	*returnSize = reslen;
	return(res);
}
main(){}
