#ifndef bool
#define bool int
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum)
{
	if (root == 0)
		return(0);
	sum -= root->val;
	if (root->left == 0 && root->right == 0 && sum == 0)
		return(1);
	return(hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
}
main(){}
