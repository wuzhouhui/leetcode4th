import java.util.*;

class UndirectedGraphNode {
	int	label;
	List<UndirectedGraphNode> neighbors;
	UndirectedGraphNode(int x) {
		label = x;
		neighbors = new ArrayList<UndirectedGraphNode>();
	}
}

class Solution {
	private HashMap<UndirectedGraphNode, UndirectedGraphNode> cloned;

	private UndirectedGraphNode do_clone(UndirectedGraphNode node) {
		if (node == null)
			return null;
		if (cloned.containsKey(node))
			return cloned.get(node);
		UndirectedGraphNode cnode = new UndirectedGraphNode(node.label);
		cloned.put(node, cnode);
		for (UndirectedGraphNode n : node.neighbors)
			cnode.neighbors.add(do_clone(n));
		return cnode;
	}

	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
		cloned = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
		return do_clone(node);
	}
}
