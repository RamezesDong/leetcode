/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String res = "";
        int sz = strs.length;
        char c = '.';
        int l = 0;
        boolean flag = true;
        while(flag) {
            for (int i = 0; i < sz; i++) {
                if (strs[i].length() > l && (c == '.' || strs[i].charAt(l) == c)) {
                    if (c == '.') {
                        c = strs[i].charAt(l);
                    }
                    if (i == sz - 1) {
                        res = res + c;
                        c = '.';
                        l ++;
                    }
                } else {
                    flag = false;
                    break;
                }
            }
        }
        return res;
    }
}
// @lc code=end

