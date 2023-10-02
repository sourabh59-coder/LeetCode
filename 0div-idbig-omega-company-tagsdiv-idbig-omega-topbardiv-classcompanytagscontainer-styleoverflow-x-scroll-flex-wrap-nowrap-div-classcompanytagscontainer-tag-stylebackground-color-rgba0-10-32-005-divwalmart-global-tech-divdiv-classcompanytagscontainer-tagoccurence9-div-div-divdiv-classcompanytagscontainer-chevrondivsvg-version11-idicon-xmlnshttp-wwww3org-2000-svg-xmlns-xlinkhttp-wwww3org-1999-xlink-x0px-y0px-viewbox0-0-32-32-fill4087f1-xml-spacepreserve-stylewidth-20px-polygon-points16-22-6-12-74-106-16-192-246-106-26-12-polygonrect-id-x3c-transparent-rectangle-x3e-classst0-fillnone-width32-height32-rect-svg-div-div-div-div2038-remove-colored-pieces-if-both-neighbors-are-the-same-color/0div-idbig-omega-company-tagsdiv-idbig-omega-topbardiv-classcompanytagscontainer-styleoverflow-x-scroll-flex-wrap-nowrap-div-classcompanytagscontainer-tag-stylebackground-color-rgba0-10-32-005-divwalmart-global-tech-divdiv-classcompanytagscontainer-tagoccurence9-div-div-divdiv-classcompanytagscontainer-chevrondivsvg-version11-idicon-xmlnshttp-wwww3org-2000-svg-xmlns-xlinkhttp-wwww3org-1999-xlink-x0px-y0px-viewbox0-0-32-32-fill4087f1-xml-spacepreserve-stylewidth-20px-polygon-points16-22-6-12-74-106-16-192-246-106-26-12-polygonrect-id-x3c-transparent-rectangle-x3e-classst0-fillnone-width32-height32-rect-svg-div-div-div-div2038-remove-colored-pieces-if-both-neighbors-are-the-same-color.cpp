class Solution {
public:
    bool winnerOfGame(string s) {
        int a = 0;
        int b = 0;
        bool ans = false;
        s += "C";
        int count = 0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
            }
            else if(s[i]!=s[i+1])
            {
                count++;
                if(count>=3)
                {
                    if(s[i]=='A')
                    {
                        a += (count-2);
                        count = 0;
                    }
                    else
                    {
                        b += (count-2);
                        count = 0;
                    }
                }
                else
                {
                    count = 0;
                }
            }
        }
        // cout<<a<<endl<<b<<endl;
        if(a==b)
        {
            ans = false;
        }
        else if(a>b)
        {
            ans = true;
        }
        return ans;
    }
};