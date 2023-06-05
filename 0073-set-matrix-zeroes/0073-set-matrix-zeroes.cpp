class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        bool x=false, y=false;
        for(int i=0;i<n;i++)
        {
            if(v[i][0]==0)
            {
                x = true;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(v[0][j]==0)
            {
                y = true;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                {
                    v[0][j] = 0;
                    v[i][0] = 0;
                }
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(v[i][0] == 0)
            {
                for(int j=0;j<m;j++)
                {
                    v[i][j] = 0;
                }
            }
        }
        
        for(int j=1;j<m;j++)
        {
            if(v[0][j]==0)
            {
                for(int i=0;i<n;i++)
                {
                    v[i][j] = 0;
                }
            }
        }
        
        if(x)
        {
            for(int i=0;i<n;i++)
            {
                v[i][0] = 0;
            }
        }
        if(y)
        {
            for(int j=0;j<m;j++)
            {
                v[0][j] = 0;
            }
        }
    }
};