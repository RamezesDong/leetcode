/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int len = s.size();
        vector<int> pre(len + 1);
        pre[0] = 0;
        for(int i = 1; i <= len; i++) {
            pre[i] += pre[i-1] + s[i-1] - '0';
        }
        int res = 0;
        for(int i = 1; i <= len - 1; i++) {
            int s = i - pre[i] + pre[len] - pre[i];
            res = max(res, s);
        }
        return res;
    }
};
// @lc code=end

