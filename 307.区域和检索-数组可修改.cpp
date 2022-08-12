/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
private:
    vector<int> a;
    int n;
public:
    inline int lowbit(int x) {
        return x & (-x);
    }

    NumArray(vector<int>& nums) {
        int nsize = nums.size();
        a.resize(nsize + 1, 0);
        n = nsize;
        for(int i = 0; i < nsize; i++) {
            update(i, nums[i]);
        }

    }
    
    void update(int index, int val) {
        val = val - sumRange(index, index);
        index = index + 1;
        while(index <= n) {
            a[index] += val;
            index += lowbit(index);
        }
    }
    
    int sumRange(int left, int right) {
        int res1 = 0;
        right = right + 1;
        while(right >= 1) {
            res1 += a[right];
            right -= lowbit(right);
        }
        int res2 = 0;
        while(left >= 1) {
            res2 += a[left];
            left -= lowbit(left);
        }
        return res1 - res2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

