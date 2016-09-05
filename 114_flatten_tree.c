struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *prev;

static void do_flat(struct TreeNode *root)
{
	if (root == 0) {
		prev->right = 0;
		return;
	};
	struct TreeNode *l = root->left;
	struct TreeNode *r = root->right;
	prev->right = root;
	root->left = 0;
	prev = root;
	do_flat(l);
	do_flat(r);
}

void flatten(struct TreeNode *root)
{
	if (root == 0)
		return;
	struct TreeNode *l = root->left;
	struct TreeNode *r = root->right;
	root->left = 0;
	prev = root;
	do_flat(l);
	do_flat(r);
}
main(){}
