class Solution {
public:
    vector<int> applyOperations(vector<int>& v) {
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])
            {
                v[i] = v[i]*2;
                v[i+1] = 0;
                i++;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
            {
                ans.push_back(v[i]);
            }
        }
        
        while(ans.size()!=v.size())
        {
            ans.push_back(0);
        }
        
        return ans;
    }
};