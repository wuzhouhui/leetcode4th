import java.util.*;

class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		List<List<String>> res = new LinkedList<>();
		HashMap<String, List<String>> map = 
			new HashMap<String, List<String>>();

		for (int i = 0; i < strs.length; i++) {
			char[] chars = strs[i].toCharArray();
			Arrays.sort(chars);
			String sorted = new String(chars);
			if (map.get(sorted) == null) {
				List<String> list =
					new LinkedList<String>();
				list.add(strs[i]);
				map.put(sorted, list);
			} else {
				map.get(sorted).add(strs[i]);
			}
		}
		for (List<String> l : map.values())
				res.add(l);
		return(res);
	}
}
