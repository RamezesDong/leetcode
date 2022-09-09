class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k >= arr.size()) return arr;
        if(k==0) return {};
        return partition(arr, 0, arr.size()-1, k);
    }

    void swap(vector<int>& a, int l, int r) {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
    }

    vector<int> partition(vector<int>& arr, int l, int r, int k) {
        int p = arr[l];
        int i = l, j = r + 1;
        while(i < j) {
            while(arr[++i] < p) {
                if(i == r) break;
            }
            while(arr[--j] >= p) {
                if(j == l) break;
            }
            if(i >= j) break;
            swap(arr, i ,j);
        }
        swap(arr, l, j);
        if(j + 1 > k) {
            return partition(arr, l, j - 1, k);
        }
        if(j + 1 < k) {
            return partition(arr, j + 1, r, k);
        }
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};