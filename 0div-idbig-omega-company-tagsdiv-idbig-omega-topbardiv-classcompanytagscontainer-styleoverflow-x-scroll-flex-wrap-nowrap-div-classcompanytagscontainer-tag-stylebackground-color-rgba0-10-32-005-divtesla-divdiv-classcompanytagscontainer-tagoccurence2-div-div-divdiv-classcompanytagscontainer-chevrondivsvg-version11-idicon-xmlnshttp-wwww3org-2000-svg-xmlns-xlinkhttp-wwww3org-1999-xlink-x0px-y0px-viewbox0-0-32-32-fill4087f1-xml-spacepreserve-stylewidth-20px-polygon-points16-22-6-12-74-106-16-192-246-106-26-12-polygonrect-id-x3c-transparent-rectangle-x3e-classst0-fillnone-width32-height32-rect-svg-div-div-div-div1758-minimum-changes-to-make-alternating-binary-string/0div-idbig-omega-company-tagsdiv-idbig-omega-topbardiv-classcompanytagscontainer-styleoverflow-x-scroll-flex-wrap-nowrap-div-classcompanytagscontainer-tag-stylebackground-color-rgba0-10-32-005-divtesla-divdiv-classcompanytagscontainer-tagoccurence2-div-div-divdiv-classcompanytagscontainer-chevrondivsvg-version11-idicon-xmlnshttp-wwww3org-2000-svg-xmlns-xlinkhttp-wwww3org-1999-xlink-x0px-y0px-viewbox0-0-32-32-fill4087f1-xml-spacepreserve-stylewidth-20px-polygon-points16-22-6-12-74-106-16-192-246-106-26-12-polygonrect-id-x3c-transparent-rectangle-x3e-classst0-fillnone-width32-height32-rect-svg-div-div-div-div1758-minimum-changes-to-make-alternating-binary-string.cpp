class Solution {
public:
    int starting_from_One(string s)
    {
        int Count=0;
        for(int i=0;i<s.length();i++)
        {
            if(i%2==0)
            {
                if(s[i]!='1')
                {
                    Count++;
                    s[i]='1';
                }
            }
            else
            {
                if(s[i]!='0')
                {
                    Count++;
                    s[i]='0';
                }
            }
        }
        return Count;
    }
    int starting_from_Zero(string s)
    {
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(i%2==0)
            {
                if(s[i]!='0')
                {
                    count++;
                    s[i]='0';
                }
            }
            else
            {
                if(s[i]!='1')
                {
                    count++;
                    s[i]='1';
                }
            }
        }
        return count;
    }
    int minOperations(string s) 
    {
        int minOperation_Count=0;
        minOperation_Count=min(starting_from_One(s),starting_from_Zero(s));
        return minOperation_Count;
    }
};