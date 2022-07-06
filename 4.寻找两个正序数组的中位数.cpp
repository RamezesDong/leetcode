/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = (n1 + n2 + 1)/2;
        int right = (n1 + n2 + 2)/2;
        return (findMedianSortedArraysHelp(nums1, nums2, 0, n1 - 1, 0, n2 - 1, left) + findMedianSortedArraysHelp(nums1, nums2, 0, n1 - 1, 0, n2 - 1, right)) * 0.5; 
    }
    
    double findMedianSortedArraysHelp(vector<int>& nums1, vector<int>& nums2, 
    int s1, int e1, int s2, int e2, int k) {
        int len1 = e1 - s1 + 1;
        int len2 = e2 - s2 + 1;
        if (len1 > len2) {
            // 确保 nums1 长度始终比较小
            return findMedianSortedArraysHelp(nums2, nums1, s2, e2, s1, e1, k);
        }
        if (len1 == 0) {
            return nums2[s2 + k - 1];
        }
        if (k == 1) {
            return min(nums1[s1], nums2[s2]);
        }
        int i = s1 + min(len1, k/2) - 1;
        int j = s2 + min(len2, k/2) - 1;
        if(nums1[i] >= nums2[j]) {
            return findMedianSortedArraysHelp(nums1, nums2, s1, e1, j + 1, e2, k - min(len2, k/2));
        } else {
            return findMedianSortedArraysHelp(nums1, nums2, i+1, e1, s2, e2, k - min(len1, k/2));
        }
    }
};
// @lc code=end

