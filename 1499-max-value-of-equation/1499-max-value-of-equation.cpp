class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& v, int k) {
        priority_queue<pair<int,int>> qe;
        int ans = INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            while(!qe.empty() &&v[i][0]-qe.top().second > k)
            {
                qe.pop();
            }
            
            if(!qe.empty())
            {
                ans = max(ans,v[i][0]+v[i][1]+qe.top().first);
            }
            
            qe.push({v[i][1]-v[i][0],v[i][0]});
        }
        
        return ans;
    }
};