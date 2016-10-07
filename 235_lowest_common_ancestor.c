#define MAX_DEPTH 64

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void do_path(struct TreeNode *root, struct TreeNode *node,
		struct TreeNode **path, int depth)
{
	if (!root)
		return;
	path[depth] = root;
	if (root->val == node->val)
		return;
	else if (node->val < root->val)
		do_path(root->left, node, path, depth + 1);
	else
		do_path(root->right, node, path, depth + 1);
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
		struct TreeNode *p, struct TreeNode *q)
{
	struct TreeNode *ppath[MAX_DEPTH] = { 0 };
	struct TreeNode *qpath[MAX_DEPTH] = { 0 };
	int	i;

	do_path(root, p, ppath, 0);
	do_path(root, q, qpath, 0);
	for (i = 0; ppath[i] && ppath[i] == qpath[i]; i++)
		;
	return(ppath[i - 1]);
}
main()
{
	struct TreeNode n1 = { 1, 0, 0, };
	struct TreeNode n2 = { 2, &n1, 0, };
	struct TreeNode q = { 2, 0, 0, };
	struct TreeNode p = { 1, 0, 0, };
	lowestCommonAncestor(&n2, &p, &q);
}
