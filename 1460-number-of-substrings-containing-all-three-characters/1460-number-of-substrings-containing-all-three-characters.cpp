class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> v(3,-1);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'] = i;
            ans += 1 + min(v[0],min(v[1],v[2]));
        }   
        return ans;
    }
};