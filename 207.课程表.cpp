/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<int> vis;
    bool cycle;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses, 0);
        cycle = true;
        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            m[b].push_back(a);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]&&!dfs(i)) {
                cycle = false;
                break;
            }
        }
        return cycle;
    }

    bool dfs(int u) {
        vis[u] = -1;
        for(auto x : m[u]) {
            if(vis[x] == -1) {
                return false;
            }
            if(vis[x] == 0 &&!dfs(x)) {
                return false;
            }
        }
        vis[u] = 1;
        return true;
    }
};
// @lc code=end

