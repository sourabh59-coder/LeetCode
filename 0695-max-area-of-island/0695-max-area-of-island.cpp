class Solution {
public:
    void fun(vector<vector<int>> &v,int i,int j,int &cnt)
    {
        int m = v.size();
        int n = v[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(v[i][j]!=1)
        {
            return;
        }
        
        cnt++;
        v[i][j] = 2;
        fun(v,i+1,j,cnt);
        fun(v,i,j+1,cnt);
        fun(v,i-1,j,cnt);
        fun(v,i,j-1,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int ans = 0;
        int m = v.size();
        int n = v[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    int cnt = 0;
                    fun(v,i,j,cnt);
                    ans = max(cnt,ans);
                }
            }
        }
        return ans;
    }
};