class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        list<pair<int,int>> qe;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            if(qe.empty())
            {
                qe.push_back({v[i],i});
            }
            else
            {
                while(qe.back().first<v[i] && !qe.empty())
                {
                    qe.pop_back();
                }
                qe.push_back({v[i],i});
            }
            
            // ans.push_back(qe.front().first);
        }
        
        ans.push_back(qe.front().first);
        
        for(int i=0;i<v.size()-k;i++)
        {
            if(qe.front().second==i)
            {
                qe.pop_front();
            }
            int j = i+k;
            if(qe.empty())
            {
                qe.push_back({v[j],j});
            }
            else
            {
                while(qe.back().first<v[j] && !qe.empty())
                {
                    qe.pop_back();
                }
                qe.push_back({v[j],j});
            }
            
            ans.push_back(qe.front().first);
        }
        
        return ans;
    }
};