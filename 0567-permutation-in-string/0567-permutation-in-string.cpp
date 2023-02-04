class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        multiset<int> st1,st2;
        if(s1.length()>s2.length())
        {
            return false;
        }
        for(int i=0;i<s1.length();i++)
        {
            st1.insert(s1[i]);
            st2.insert(s2[i]);
        }
        
        
        
        if(st1==st2)
        {
            return true;
        }
        
        for(int i=s1.length();i<s2.length();i++)
        {
            st2.erase(st2.find(s2[i-s1.length()]));
            st2.insert(s2[i]);
            
            if(st1==st2)
            {
                return true;
            }
        }
        
        return false;
    }
};