bool comparator(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>> v;
        
        for(int i=0 ; i<mat.size(); i++)
        {
            int count = 0;
            for(int j=0 ; j<mat[0].size() ; j++)
            {
                if(mat[i][j] == 1)
                    count++;
                else if(mat[i][j] == 0)
                    break;
            }
            
            v.push_back({i, count});
        }
        
        sort(v.begin(), v.end(), comparator);
        
        vector<int> ans;
        
        
        for(int i=0 ; i<k; i++)
        {
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};