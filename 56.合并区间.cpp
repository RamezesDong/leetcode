/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int l,r;
        for (int i = 0;i < n;i++) {
            if(i == 0) {
                l = intervals[i][0];
                r = intervals[i][1];
            }
            if(intervals[i][0] <= r) {
                if (intervals[i][1] > r) {
                    r = intervals[i][1];
                }
            } else {
                vector<int> a;
                a.push_back(l);
                a.push_back(r);
                result.push_back(a);
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        vector<int> a;
        a.push_back(l);
        a.push_back(r);
        result.push_back(a);
        return result;
    }
};
// @lc code=end

