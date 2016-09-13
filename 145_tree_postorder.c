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

static void do_postorder(const struct TreeNode *root)
{
	if (root == NULL)
		return;
	do_postorder(root->left);
	do_postorder(root->right);
	add(root->val);
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
	res = NULL;
	reslen = maxreslen = 0;
	do_postorder(root);
	*returnSize = reslen;
	return(res);
}
main(){}
