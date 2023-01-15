class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        s += '1';
        int mod = 1000000007;
        long long cnt = 0;
        char prev = s[0];
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==prev)
            {
                cnt++;
            }
            else
            {
                long long val = ((cnt)*(cnt+1)/2)%mod;
                ans += (val%mod);
                cnt = 1;
                prev = s[i];
            }
        }
        return ans;
    }
};