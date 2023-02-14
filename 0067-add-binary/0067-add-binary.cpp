class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        
        int n = a.length();
        int m = b.length();
        int carry = 0;
        while(n!=0 || m!=0 || carry!=0)
        {
            int k1 = 0;
            int k2 = 0;
            if(n!=0)
            {
                k1 = a[n-1]-'0';
                n--;
            }    
            if(m!=0)
            {
                k2 = b[m-1]-'0';
                m--;
            }
            
            int sum = carry+k1+k2;
            
            if(sum==0)
            {
                ans += '0';
                carry = 0;
            }
            else if(sum==1)
            {
                ans += '1';
                carry = 0;
            }
            else if(sum==2)
            {
                ans += '0';
                carry = 1;
            }
            else if(sum==3)
            {
                ans += '1';
                carry = 1;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};