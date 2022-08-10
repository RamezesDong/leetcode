/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for(int i = 1; i <= amount; i++) {
            dp[i] = 0x3f3f3f3f;
            for(auto c : coins) {
                if (i - c < 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i-c] + 1);
             }
        }
        if (dp[amount] == 0x3f3f3f3f) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};
// @lc code=end

