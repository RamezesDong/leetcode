/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        int l = s.length();
        boolean[][] dp = new boolean[l][l];
        int maxStart = 0;
        int maxEnd = 0;
        int maxs = 1;
        if (l == 0 || l == 1) {
            return s;
        }
        for (int r = 1; r < l; r++) {
            for (int i = 0; i < r; i++) {
                if (s.charAt(i) == s.charAt(r) && (r - i <= 2 || dp[i + 1][r - 1])) {
                    dp[i][r] = true;
                    if (r - i + 1 > maxs) {
                        maxs = r - i + 1;
                        maxStart = i;
                        maxEnd = r;
                    }
                }
            }
        }
        return s.substring(maxStart, maxEnd + 1);
    }
}
// @lc code=end

