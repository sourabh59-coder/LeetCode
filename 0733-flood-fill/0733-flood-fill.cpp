class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void fun(vector<vector<int>> &image,int i,int j,int n,int m,int inital_color,int color)
    {
        image[i][j] = color;

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(check(x,y,n,m) && image[x][y]==inital_color)
            {
                fun(image,x,y,n,m,inital_color,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)    return image;
        int n = image.size();
        int m = image[0].size();
        int intial_color = image[sr][sc];
        image[sr][sc] = color;
        fun(image,sr,sc,n,m,intial_color,color);
        return image;
    }
};