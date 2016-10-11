import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new LinkedList<>();
        for (int i = 0; i < input.length(); i++) {
            if (Character.isDigit(input.charAt(i)))
                continue;
            List<Integer> left = diffWaysToCompute(input.substring(0, i));
            List<Integer> right = diffWaysToCompute(input.substring(i + 1));
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    switch (input.charAt(i)) {
                        case '+':
                            res.add(left.get(j) + right.get(k));
                            break;
                        case '-':
                            res.add(left.get(j) - right.get(k));
                            break;
                        case '*':
                            res.add(left.get(j) * right.get(k));
                            break;
                    }
                }
            }
        }
        if (res.size() == 0)
            res.add(Integer.parseInt(input));
        return res;
    }
}
