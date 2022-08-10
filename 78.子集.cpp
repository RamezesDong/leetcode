/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int s = nums.size();
        vector<vector<int>> res;
        vector<int> p;
        dfs(res, nums, p, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> p,int now) {
        res.push_back(p);
        for (int i = now; i < nums.size(); i++) {
            p.push_back(nums[i]);
            dfs(res, nums, p, i + 1);
            p.pop_back();
        }
    }
};
// @lc code=end

