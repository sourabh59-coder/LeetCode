class Solution {
public:
    void fun(vector<vector<int>> &v1,vector<vector<int>> &v2,int i,int j,bool &temp)
    {
        int m = v2.size();
        int n = v2[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(v2[i][j]!=1)
        {
            return;
        }
        
        if(v1[i][j]!=1)
        {
            temp = false;
        }
        
        v2[i][j] = 2;
        
        fun(v1,v2,i+1,j,temp);
        fun(v1,v2,i-1,j,temp);
        fun(v1,v2,i,j+1,temp);
        fun(v1,v2,i,j-1,temp);
    }
    int countSubIslands(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int ans = 0;
        
        int m = v2.size();
        int n = v2[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v2[i][j]==1 && v1[i][j]==1)
                {
                    bool temp = true;
                    fun(v1,v2,i,j,temp);
                    if(temp)
                    {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};