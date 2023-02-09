class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& v,vector<vector<int>>& q) {
        int cnt = 0;
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            if(isVowel(v[i][0]) && isVowel(v[i][v[i].size()-1]))
            {
                cnt++;
            }
            ans.push_back(cnt);
        }
        vector<int> fin;
        for(int i=0;i<q.size();i++)
        {
            int l = q[i][0];
            int r = q[i][1];
            
            int val = ans[r];
            
            if(l-1>=0)
            {
                val-=ans[l-1];
            }
            fin.push_back(val);
        }
        return fin;
    }
};