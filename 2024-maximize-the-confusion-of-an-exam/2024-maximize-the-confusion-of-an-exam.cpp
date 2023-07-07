class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans = 0;
        int cnt = 0;
        int i=0,j=0;
        int n = s.length();
        int k1 = k;
        
        while(i!=n && j!=n)
        {
            if(s[j]=='T')
            {
                cnt++;
                j++;
            }
            else
            {
                if(k==0)
                {
                    while(s[i]!='F')
                    {
                        cnt--;
                        i++;
                    }
                    i++;
                    cnt--;
                    k++;
                }
                cnt++;
                k--;
                j++;
            }
            ans = max(ans,cnt);
        }
        
        i = 0,j = 0;
        cnt = 0;
        int ans1 = 0;
        
        while(i!=n && j!=n)
        {
            if(s[j]=='F')
            {
                cnt++;
                j++;
            }
            else
            {
                if(k1==0)
                {
                    while(s[i]!='T')
                    {
                        cnt--;
                        i++;
                    }
                    i++;
                    cnt--;
                    k1++;
                }
                cnt++;
                k1--;
                j++;
            }
            ans1 = max(ans1,cnt);
        }
        
        
        return max(ans,ans1);
    }
};