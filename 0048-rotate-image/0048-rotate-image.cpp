class Solution {
public:
    void ClockwiseRotate90(vector<vector<int>> &v)
    {
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+j < n-1)
                {
                    int i2 = (n-1)-j, j2= (n-1)-i;
                    swap(v[i][j],v[i2][j2]);
                }
            }
        }
        
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n;j++)
            {
                int i1 = (n-1)-i;
                swap(v[i][j],v[i1][j]);
            }
        }
    }
    void rotate(vector<vector<int>>& v) {
        ClockwiseRotate90(v);
    }
};