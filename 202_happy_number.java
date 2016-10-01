import java.util.*;

class Solution {
    public static int square[] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };

    private int happy(int n) {
        int res = 0;
        while (n != 0) {
            res += square[n % 10];
            n /= 10;
        }
        return res;
    }

    public boolean isHappy(int n) {
        HashSet<Integer> set = new HashSet<>();
        while (n != 1) {
            n = happy(n);
            if (set.contains(n))
                return false;
            set.add(n);
        }
        return true;
    }
}
