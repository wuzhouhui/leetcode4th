import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {

        LinkedList<List<Integer>> res = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<TreeNode> tqueue = new LinkedList<>();

        if (root != null)
            queue.offer(root);
        while (queue.size() != 0) {
            List<Integer> level = new LinkedList<>();
            while (queue.size() != 0) {
                TreeNode node = queue.poll();
                if (node.left != null)
                    tqueue.offer(node.left);
                if (node.right != null)
                    tqueue.offer(node.right);
                level.add(node.val);
            }
            res.add(level);
            Queue<TreeNode> tmp = queue;
            queue = tqueue;
            tqueue = tmp;
        }
        List<List<Integer>> ret = new LinkedList<>();
        while (res.size() > 0)
            ret.add(res.pollLast());
        return ret;
    }
}
