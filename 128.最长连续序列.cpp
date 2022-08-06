/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Disjoint{
private:
    vector<int> fa;
    vector<int> ranks;
    vector<int> size;
    int maxv;
public: 
    Disjoint(int n):fa(n+1),ranks(n+1), size(n+1){
        maxv = 1;
    }

    void init(int n) {
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            ranks[i] = 1;
            size[i] = 1;
        }
    }

   int find(int x) {
        if (x == fa[x])
        {
            return fa[x];
        } else {
            fa[x] = find(fa[x]);
            return fa[x];
        }
        
    }

    void merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y)
        {
            return;
        }
        //cout << "Merge" << a  << " " << b << '\n';
        if (ranks[x] <= ranks[y])
        {
            fa[x] = y;
            size[y] += size[x];
          //  cout << "size y is "<< size[y] << '\n';
            if (size[y] > maxv)
            {
                maxv = size[y];
            }
        }
        else {
            fa[y] = x;
            size[x] += size[y];
            //cout << "size x is "<< size[x] << '\n';
            if (size[x] > maxv)
            {
                maxv = size[x];
            }
        }
        if (ranks[x] == ranks[y] && x!=y)
        {
            ranks[y] ++;
        }   
    }

    int getMax() {
        return maxv;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
        {
            return len;
        }
        
        unordered_map<int, int> m;
        Disjoint joint(len);
        joint.init(len);
        for (int i = 1; i <= len; i++)
        {
            int v = nums[i-1];
            if (m.count(v))
            {
                continue;
            }
            if (m.count(v-1))
            {
                joint.merge(m[v-1], i);
            }
            if (m.count(v+1))
            {
                joint.merge(m[v+1], i);
            }
            m[v] = i;
        }
        return joint.getMax();
    }

 
};
// @lc code=end

