class Solution {
public:
    string largestGoodInteger(string num) {
        string s="";
        for(char i='9';i>='0';i--)
        {   string x=to_string(i-'0');
            s=x+x+x;
            if(num.find(s)!=string::npos)
                return s;
        }
        return "";
    }
};