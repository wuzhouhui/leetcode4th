#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder,
		int postorderSize)
{
	if (inorderSize <= 0)
		return(0);
	struct TreeNode *root = malloc(sizeof(*root));
	root->val = postorder[postorderSize - 1];
	for (inorderSize = 0; inorder[inorderSize] != root->val; inorderSize++)
		;
	root->left = buildTree(inorder, inorderSize, postorder, inorderSize);
	root->right = buildTree(inorder + inorderSize + 1, postorderSize - inorderSize
			- 1, postorder + inorderSize, postorderSize - inorderSize - 1);
	return(root);
}

main(){}
