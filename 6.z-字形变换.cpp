/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1) {
            return s;
        }
        string res = "";
        int k = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i ++) {
            int x = i;
            if (i == 0 || i == numRows - 1) {
                while(x < len) {
                    res += s[x];
                    x += k;
                }
            } else {
                while (x < len)
                {
                    res += s[x];
                    x += k;
                    x -= 2*i;
                    if (x < len) {
                        //cout<< x<< endl;
                        res += s[x];
                    }
                    x += 2*i;
                }
                
            }
        }
        return res;
    }
};
// @lc code=end

