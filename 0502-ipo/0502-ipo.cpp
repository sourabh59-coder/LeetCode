class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int ans = 0;
        int wIntial = w;
        vector<pair<int,int>> v;
        for(int i=0;i<p.size();i++)
        {
            v.push_back({c[i],p[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>> qe;
        int i = 0;
        while(k--)
        {
            while(v[i].first<=w && i!=v.size())
            {
                qe.push({v[i].second,v[i].first});
                i++;
            }
            
            if(!qe.empty())
            {
                // int val = (qe.top().first)-(qe.top().second);
                int prof = qe.top().first;
                ans += qe.top().first;
                qe.pop();
                w += prof;
            }
            else
            {
                break;
            }
        }
        
        return ans+wIntial;
    }
};