import java.util.*;

class TreeNode {
	int	val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		LinkedList<List<Integer>> res = new LinkedList<>();
		if (root == null)
			return res;
		LinkedList<TreeNode> next = new LinkedList<>();
		LinkedList<TreeNode> alevel = new LinkedList<>();
		boolean dir = true;
		alevel.add(root);
		while (alevel.size() != 0) {
			LinkedList<Integer> t = new LinkedList<>();
			while (alevel.size() != 0) {
				TreeNode node = alevel.pop();
				t.offer(node.val);
				if (dir == true) {
					if (node.left != null)
						next.push(node.left);
					if (node.right != null)
						next.push(node.right);
				} else {
					if (node.right != null)
						next.push(node.right);
					if (node.left != null)
						next.push(node.left);
				}
			}
			dir = !dir;
			if (t.size() != 0)
				res.offer(t);
			LinkedList<TreeNode> tmp = alevel;
			alevel = next;
			next = tmp;
		}
		return res;
	}
}
