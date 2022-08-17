/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int lt = -1, rt = len, i = 0;
        while(i < rt) {
            if(nums[i] == 0) {
                lt ++;
                swap(nums, lt , i);
                i++;
            } else if (nums[i]==1) {
                i++;
            } else {
                rt --;
                swap(nums, rt, i);
            }
        }
    }
    void swap(vector<int>& nums, int a, int b) {
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
};
// @lc code=end

