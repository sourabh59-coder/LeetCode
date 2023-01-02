class Solution {
public:
    bool detectCapitalUse(string s) {
        if(s.length()==1)
        {
            return true;
        }
        
        bool flag = isupper(s[0]);
        
        if(flag)
        {
            bool flag = true;
            bool flag1 = true;
            for(int i=1;i<s.length();i++)
            {
                if(isupper(s[i]))
                {
                    flag1 = false;
                }
                else
                {
                    flag = false;
                }
            }
            
            return (flag||flag1);
        }
        else
        {
            bool flag = true;
            for(int i=1;i<s.length();i++)
            {
                if(isupper(s[i]))
                {
                    flag = false;
                    break;
                }
            }
            
            return flag;
        }
        
        return true;
    }
};