/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
public:
    int dp[10][10][2];
    int a[10], d[10];
    int cnt, dnt;
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        cnt = 0;
        dnt = digits.size();
        for(int i = 0; i < digits.size(); i ++) {
            d[i] = digits[i][0] - '0';
        }
        while(n > 0) {
            a[cnt++] = n%10;
            n /= 10;
        }
        reverse(a, a + cnt);
        return dfs(0, 0, true);
    }

    int dfs(int pos, int use, bool limit) {
        if(pos == cnt) {
            return use > 0;
        }
        if(dp[pos][use][limit] != -1) {
            return dp[pos][use][limit];
        }
        int ans = 0;
        if (!use) {
            ans += dfs(pos+1, use, false);
        }
        for(int i = 0; i < dnt; i++) {
            if (limit) {
                if(d[i] > a[pos]) {
                continue;
                } 
                else if(d[i] == a[pos]) {
                    ans += dfs(pos + 1, 1, true);
                } else {
                    ans += dfs(pos + 1, 1, false);
                }
            }
            else
                ans += dfs(pos + 1, 1, false);
        }
        dp[pos][use][limit] = ans;
        return ans; 
    }
};
// @lc code=end

