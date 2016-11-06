import java.util.*;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            Character t = null;
            switch (c) {
                case ')':
                    t = '(';
                    break;
                case ']':
                    t = '[';
                    break;
                case '}':
                    t = '{';
                    break;
                default:
                    stack.push(c);
                    break;
            }
            if (t == null)
                continue;
            if (stack.empty() || stack.pop() != t)
                return false;
        }
        if (!stack.empty())
            return false;
        else
            return true;
    }
}
