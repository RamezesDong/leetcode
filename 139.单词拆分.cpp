/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Trie {
private:
    int next[10005][26];
    int cnt;
    bool exist[10005];
    int failMen[305];
public:
    Trie() {
        memset(next, 0, sizeof(next));
        memset(exist, false, sizeof(exist));
        cnt = 1;
        memset(failMen, 0 ,305);
    }
    
    void insert(string word) {
        int cur = 1;
        for(auto c : word) {
            if(!next[cur][c-'a']) {
                next[cur][c-'a'] = ++cnt;
            }
            cur = next[cur][c-'a'];
        }
        exist[cur] = true;
    }
    
    bool search(string word) {
        int cur = 1;
        for(auto c : word) {
            if(!next[cur][c-'a']) {
                return false;
            }
            cur = next[cur][c-'a'];
        }
        return exist[cur];
    }
    
    bool startsWith(string prefix) {
        int cur = 1;
        for(auto c : prefix) {
            if(!next[cur][c-'a']) {
                return false;
            }
            cur = next[cur][c-'a'];
        }
        return true;
    }
    
    bool dfs(string& s, int start) {
        if(failMen[start] == 1) return false;
        if(start == s.size()) {
            return true;
        }
        int cur = 1;
        for(int i = start; i < s.size(); i++) {
            if(!next[cur][s[i]-'a']) {
                break;
            } else {
                cur = next[cur][s[i]-'a'];
                if(exist[cur] && dfs(s, i+1)) {
                    return true;
                }
            }
        }
        failMen[start] = 1;
        return false;
    }
};
class Solution {
private:
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(int i = 0; i < wordDict.size(); i++) {
            t.insert(wordDict[i]);
        }
        return t.dfs(s, 0);
    }


};
// @lc code=end

