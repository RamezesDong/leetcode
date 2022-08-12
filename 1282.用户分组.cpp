/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> m;
        // map <下标， <可存， 已存>> 设为两个map更好写代码!! 这个方法不好，还是直接把同大小元素存一起
        for(int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            m[size].emplace_back(i);
        }
        for(auto&[size, ve] : m ) {
            int co = ve.size()/size;
            for(int i = 0; i < co; i++) {
                vector<int> addv;
                int start = i * size;
                for(int j = 0; j < size; j ++) {
                    addv.push_back(ve[start++]);
                }
                res.push_back(addv);
            }
        }
        return res;
    }
};
// @lc code=end

