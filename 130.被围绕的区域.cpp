/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Disjoint{
private:
    vector<int> fa;
    vector<int> ranks;
public: 
    Disjoint(int n):fa(n+2),ranks(n+2){
    for (int i = 0; i <= n; i++)
        {
            fa[i] = i;
            ranks[i] = 1;
        }
        fa[n+1] = n+1;
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
        }
        else {
            fa[y] = x;
        }
        if (ranks[x] == ranks[y] && x!=y)
        {
            ranks[y] ++;
        }   
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int len = board.size();
        int len2 = board[0].size();
        Disjoint joint(len*len2);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                //cout << board[i][j] << endl;
                if (board[i][j] == 'O')
                {
                    //cout << "i j is " << i << " " << j << '\n';
                    if (i==0 || i == len -1 || j == 0 || j == len2-1)
                    {
                        joint.merge(i*len2 + j, len*len2 + 1);
                    }
                    if(i - 1 >= 0 && board[i-1][j] == 'O')
                    {
                        joint.merge(i*len2 + j, (i-1)*len2 + j);
                    }
                    if (j-1 >= 0 && board[i][j-1] == 'O')
                    {
                        joint.merge(i*len2 +j, i*len2 + j-1);
                    }
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            for(int j = 0; j < len2; j++) {
                if (board[i][j]=='O'&& joint.find(i*len2 + j) != joint.find(len*len2+1))
                {
                    board[i][j] = 'X';
                }
            }
        }   
    }
};
// @lc code=end

