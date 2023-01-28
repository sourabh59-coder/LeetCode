//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void fun(vector<vector<int>> &image,int i,int j,int col,int c)
    {
        int m = image.size();
        int n = image[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(image[i][j]!=c)
        {
            return;
        }
        
        image[i][j] = col;
        
        fun(image,i+1,j,col,c);
        fun(image,i-1,j,col,c);
        fun(image,i,j+1,col,c);
        fun(image,i,j-1,col,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c = image[sr][sc];
        if(c!=newColor)
        {
            fun(image,sr,sc,newColor,c);
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends