import java.util.*;

class TreeNode {
	int	val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	public List<Integer> largestValues(TreeNode root) {
		LinkedList<Integer> res = new LinkedList<>();

		if (root == null)
			return res;

		LinkedList<TreeNode> parent = new LinkedList<>();
		LinkedList<TreeNode> child = new LinkedList<>();
		int	max = 0;

		parent.offer(root);
		while (parent.size() != 0) {
			max = parent.peek().val;
			while (parent.size() != 0) {
				TreeNode node = parent.poll();
				if (node.val> max)
					max = node.val;
				if (node.left != null)
					child.offer(node.left);
				if (node.right != null)
					child.offer(node.right);
			}
			LinkedList<TreeNode> t = parent;
			parent = child;
			child = t;
			res.offer(max);
		}
		return res;
	}
}
