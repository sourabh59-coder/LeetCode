bool comp(vector<int> &a,vector<int> &b)
{
    return  (a[1]<b[1]);
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int ans = 0;
        if(v.size()==0) return 0;
        
        sort(v.begin(),v.end(),comp);
        
        int n = v.size();
        
        int prev = v[0][1];
        
        for(int i=0;i<n;i++)
        {
            if(prev>v[i][0])
            {
                ans++;
            }
            else
            {
                prev = v[i][1];
            }
        }
        ans--;
        return ans;
    }
};