/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 0;
        int maxv = 0;
        for(int i = 1; i < s.size(); i ++) {
            if(s[i] == '(') {
                continue;
            } else {
                if(s[i-1] == '(') {
                    dp[i] = 2;
                    if(i-2 > 0) {
                        dp[i] += dp[i-2];
                    }
                } else {
                    if(i-dp[i-1] - 1>=0 && s[i-dp[i-1] - 1] == '(') {
                        dp[i] = dp[i-1] + 2;
                        if(i - dp[i-1] - 2 > 0) {
                            dp[i] += dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
            maxv = max(maxv, dp[i]);
        }  
        return maxv;
    }
};
// @lc code=end

