#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
		int inorderSize)
{
	if (preorderSize <= 0)
		return(0);
	struct TreeNode *root = malloc(sizeof(*root));
	root->val = preorder[0];
	for (inorderSize = 0; inorder[inorderSize] != root->val; inorderSize++)
		;
	root->left = buildTree(preorder + 1, inorderSize, inorder, inorderSize);
	root->right = buildTree(preorder + 1 + inorderSize, preorderSize - inorderSize
			- 1, inorder + inorderSize + 1, preorderSize - inorderSize - 1);
	return(root);
}

main(){}
