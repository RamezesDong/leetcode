/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<int> deg;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) {
            return { 0 };
        }
        deg.resize(n, 0);
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            m[a].push_back(b), m[b].push_back(a);
            deg[a]++, deg[b]++;
        }
        vector<int> res;
        queue<int> q;
        //unordered_map<int, vector<int>> m2;
        //int minx = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
           if(deg[i] == 1) {
               q.push(i);
           }
        }
        while(!q.empty()) {
            int si = q.size();
            if(n == si) break;
            n -= si;
            while (si --) {
                int x = q.front();
                q.pop();
                for(auto tox : m[x]) {
                    deg[tox]--;
                    if(deg[tox] == 1) {
                        q.push(tox);
                    }
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

