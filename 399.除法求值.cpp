/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Joint{
private:
    vector<int> fa;
    vector<double> val;
public:
    Joint(int n) : fa(n+1), val(n+1) {
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 1.0;
        }
    } 

    pair<int, double> find(int a) {
         if (a == fa[a]) {
             return make_pair(a, val[a]);
         } else {
             auto p = find(fa[a]);
             int origin = fa[a];
             fa[a] = p.first;
             val[a] = val[a] * val[origin];
             return make_pair(fa[a], val[a]);
         }
    }

    void merge(int a, int b, double v) {
        auto p1 = find(a);
        auto p2 = find(b);
        if (p1.first == p2.first) {
            return;
        }
        int p1f = p1.first;
        fa[p1f] = p2.first;
        val[p1f] = val[b] * v / val[a];
    }

    double query(int a, int b) {
        auto p1 = find(a);
        //cout << "can find " << a << '\n';
        auto p2 = find(b);
        //cout << "can find " << b << '\n';
        if(p1.first != p2.first) {
            return -1.0;
        }
        //double v1 = p1.second;
        //double v2 = p2.second;
        return val[a]/val[b];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> m;
        int len1 = equations.size();
        int k = 1;
        for(int i = 0; i < len1; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            if(m.find(a) == m.end()) {
                m[a] = k++;
            }
            if(m.find(b) == m.end()) {
                m[b] = k++;
            }
        }
        //cout <<"ok1" << endl;
        int msize = m.size();
        Joint sets(msize);
        for(int i =0; i < len1; i++) {
            int a = m[equations[i][0]];
            int b = m[equations[i][1]];
            sets.merge(a, b, values[i]);
        }
        //cout << "ok2" << endl;
        int querys = queries.size();
        vector<double> res(querys);
       // cout << "ok3" << endl;
        for(int i = 0; i < querys; i++) {
            if (m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end()) {
                res[i] = -1.0;
                continue;
            }
            int a = m[queries[i][0]];
            int b = m[queries[i][1]];
            res[i] = sets.query(a, b);
            //cout << i << endl;
        }
        return res;
    }
};
// @lc code=end

