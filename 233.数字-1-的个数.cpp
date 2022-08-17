/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int dp[10][10][2];
    int a[10];
    int cnt;
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        cnt = 0;
        while(n > 0) {
            a[cnt++] = n%10;
            n /= 10;
        }
        reverse(a, a + cnt);
        return dfs(0, 0, true);
    }

    int dfs(int pos, int count, bool limit) {
        if(pos == cnt) {
            return count;
        }
        if(dp[pos][count][limit] != -1) {
            return dp[pos][count][limit];
        }
        int ans = 0;
        for(int i = 0; i <= (limit? a[pos] :9); ++i) {
            if(i == 1) {
                ans += dfs(pos+1, count + 1, limit && a[pos]==i);
            } else {
                ans += dfs(pos+1, count, limit&&a[pos]==i);
            }
        }
        dp[pos][count][limit] = ans;
        return ans; 
    }
};
// @lc code=end

