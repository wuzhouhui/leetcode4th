struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int res;

static int do_tilt(const struct TreeNode *root)
{
	if (!root)
		return(0);
	int lsum = do_tilt(root->left);
	int rsum = do_tilt(root->right);
	if (lsum > rsum)
		res += lsum - rsum;
	else
		res += rsum - lsum;
	return(lsum + rsum + root->val);
}

int findTilt(struct TreeNode *root)
{
	res = 0;
	do_tilt(root);
	return(res);
}

main(){}
