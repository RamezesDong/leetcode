/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<int> deg;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        deg.resize(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            m[b].push_back(a);
            deg[a] ++;
        }
        deque<int> q;
        for(int i = 0; i < numCourses; i++) {
            if (deg[i] == 0) {
                q.push_back(i);
            }
        }
        while(!q.empty()) {
            int t = q.front();
            ans.push_back(t);
            q.pop_front();
            for(auto x : m[t]) {
                deg[x]--;
                if(deg[x] == 0) {
                    q.push_back(x);
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        } else {
            vector<int> nuve;
            return nuve;
        }
    }
};
// @lc code=end

