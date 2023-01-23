class Solution {
public:
    void fun(vector<vector<char>> &v,int i,int j)
    {
        int m = v.size();
        int n = v[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(v[i][j]!='1')
        {
            return;
        }
        
        v[i][j] = '2';
        fun(v,i+1,j);
        fun(v,i-1,j);
        fun(v,i,j+1);
        fun(v,i,j-1);
    }
    int numIslands(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='1')
                {
                    cnt++;
                    fun(v,i,j);
                }
            }
        }
        return cnt;
    }
};