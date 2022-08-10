/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.length();
        unordered_map<char, int> sm, tm;
        for (int i = 0; i < t.length(); i++) {
            tm[t[i]]++;
        }
        string res = "";
        int cnt = 0;
        for (int i = 0, j = 0; i < lens; i++) {
            sm[s[i]]++;
            if(sm[s[i]] <= tm[s[i]]) {
                cnt ++;
            }
            while(j<i && sm[s[j]] > tm[s[j]]) {
                sm[s[j]] --;
                j++;
            }
            if(cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size()) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end

