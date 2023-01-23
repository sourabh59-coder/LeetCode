class Solution {
public:
    void fun(vector<vector<int>> &v,int i,int j,int col,int prev)
    {
        int n = v.size();
        int m = v[0].size();
        if(i<0 || i>=n)
        {
            return;
        }
        if(j<0 || j>=m)
        {
            return;
        }
        if(v[i][j]!=prev)
        {
            return;
        }
        
        v[i][j] = col;
        fun(v,i+1,j,col,prev);
        fun(v,i-1,j,col,prev);
        fun(v,i,j+1,col,prev);
        fun(v,i,j-1,col,prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCol = image[sr][sc];
        
        if(iniCol!=color)
        {
            fun(image,sr,sc,color,image[sr][sc]);
        }
        
        return image;
    }
};