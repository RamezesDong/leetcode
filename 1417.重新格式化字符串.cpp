/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        string s1,s2,ans;
        for(auto i:s){
            if(i>='0'&&i<='9') s1+=i;
            else s2+=i;
        }
        int len1=s1.size();
        int len2=s2.size();
        if(abs(len1-len2)<2){
            if(len1>len2){
                for(int i=0,j=0;i<len1||j<len2;i++,j++){
                    if(i<len1) ans+=s1[i];
                    if(j<len2) ans+=s2[j];
                }
            }
            else{
                for(int i=0,j=0;i<len1||j<len2;i++,j++){
                    if(j<len2) ans+=s2[j];
                    if(i<len1) ans+=s1[i];
                }
            }
            return ans;
        }
        return ans;
    }
     
};
// @lc code=end

