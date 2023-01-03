bool check_if_sorted(string str)
{
    // Function call to is_sorted with binary predicate ignore_case
    return is_sorted(str.begin(), str.end());
}
class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int ans = 0;
        for(int i=0;i<s[0].size();i++)
        {
            string s1 = "";
            for(int j=0;j<s.size();j++)
            {
                s1 += s[j][i];
            }
            if(!check_if_sorted(s1))
            {
                ans++;
            }
        }
        return ans;
    }
};