/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> de;
        vector<int> res;
        for(int i = 0; i < a.size(); i++) {
            while(!de.empty()&& de.back() < a[i]) {
                de.pop_back();
            }
            de.push_back(a[i]);
            if(i-k>= 0 && a[i-k] == de.front()) {
                de.pop_front();
            }
            if(i >= k - 1)
            res.push_back(de.front());
        }
        return res;
    }
};
// @lc code=end

