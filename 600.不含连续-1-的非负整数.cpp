/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
class Solution {
public:
    int dp[32][2][2];
    int a[32];
    int cnt;
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        cnt = 0;
        while(n > 0) {
            a[cnt++] = n%2;
            n /= 2;
        }
        reverse(a, a + cnt);
        return dfs(0, 0, true);
    }

    int dfs(int pos, int last, bool limit) {
        if(pos == cnt) {
            return 1;
        }
        if(dp[pos][last][limit] != -1) {
            return dp[pos][last][limit];
        }
        int ans = 0;
        for(int i = 0; i <= (limit? a[pos] : 1); ++i) {
            if(i == 1 && last == 1) {
                continue;
            } 
            ans += dfs(pos+1, i, limit&&a[pos]==i);
        }
        dp[pos][last][limit] = ans;
        return ans; 
    }
};
// @lc code=end

