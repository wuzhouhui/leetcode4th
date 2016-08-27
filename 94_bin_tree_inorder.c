#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int *res, p, maxp;

static void addans(int v)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = v;
}

static void inorder(const struct TreeNode *root)
{
	if (root == 0)
		return;
	inorder(root->left);
	addans(root->val);
	inorder(root->right);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	maxp = p = 0;
	res = 0;
	inorder(root);
	*returnSize = p;
	return(res);
}

main(){}
