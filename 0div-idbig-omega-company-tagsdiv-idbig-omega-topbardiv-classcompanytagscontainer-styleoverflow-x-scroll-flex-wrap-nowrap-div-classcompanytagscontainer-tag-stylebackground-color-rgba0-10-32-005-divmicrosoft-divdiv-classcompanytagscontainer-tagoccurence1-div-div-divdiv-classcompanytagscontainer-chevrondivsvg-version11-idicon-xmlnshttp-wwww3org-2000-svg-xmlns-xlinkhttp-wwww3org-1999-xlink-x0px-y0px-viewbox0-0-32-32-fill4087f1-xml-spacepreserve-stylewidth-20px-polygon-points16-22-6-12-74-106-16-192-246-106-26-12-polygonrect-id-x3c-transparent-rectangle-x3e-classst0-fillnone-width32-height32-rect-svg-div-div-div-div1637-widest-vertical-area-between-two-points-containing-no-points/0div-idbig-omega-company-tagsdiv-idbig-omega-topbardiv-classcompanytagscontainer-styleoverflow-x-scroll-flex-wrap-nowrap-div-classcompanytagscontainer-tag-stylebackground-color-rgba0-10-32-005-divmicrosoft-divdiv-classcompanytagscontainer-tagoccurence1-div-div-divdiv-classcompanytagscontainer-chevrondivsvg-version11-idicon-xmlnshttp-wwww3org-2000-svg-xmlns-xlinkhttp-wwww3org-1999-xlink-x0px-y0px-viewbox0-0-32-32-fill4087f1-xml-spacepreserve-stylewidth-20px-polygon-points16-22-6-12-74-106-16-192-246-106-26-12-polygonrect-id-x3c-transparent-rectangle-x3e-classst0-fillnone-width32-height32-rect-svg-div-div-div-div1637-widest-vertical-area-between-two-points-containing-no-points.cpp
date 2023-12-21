class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> ans;
        int maxi=0;
        int sndMax=0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points[0].size();j++)
            {
                ans.push_back(points[i][0]);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=ans.size()-1;i>=1;i--)
        {
            maxi=max(maxi,ans[i]-ans[i-1]);
        }
        return maxi;
    }
};