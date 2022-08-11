/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    int next[100005][26];
    int cnt;
    bool exist[100005];
public:
    Trie() {
        memset(next, 0, sizeof(next));
        memset(exist, false, sizeof(exist));
        cnt = 1;
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

