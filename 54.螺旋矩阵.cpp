/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        if(matrix.empty()) return res;
        int l = 0, r = m - 1, t = 0, b = n - 1;
        while(1) {
            for(int i = l; i <= r; i++) {
                res.push_back(matrix[t][i]);
            }
            if(++t > b) break;
            for(int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            if(--r < l) break;
            for(int i = r; i >= l; --i) {
                res.push_back(matrix[b][i]);
            }
            if(--b < t) break;
            for(int i = b; i >= t; --i) {
                res.push_back(matrix[i][l]);
            }
            if(++l > r) break;
        }
        return res;
    }
};
// @lc code=end

