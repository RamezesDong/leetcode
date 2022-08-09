/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int lens = nums.size();
        for(int i = 0; i < lens; i++) {
            while (nums[i] >= 1 && nums[i] <= lens && nums[nums[i]-1] != nums[i]) {
                swap(nums, i, nums[i] -1);
            }
        }
        int res = -1;
        for (int i = 0; i < lens; i++)
        {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return lens + 1;
    }

    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};
// @lc code=end

