class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        else
        {
            long rem,temp= x;
            long int sum = 0;
            while(x>0)
            {
                rem = x%10;
                sum = (sum*10) + rem;
                x = x/10;
            }
            if(sum == temp)
            {
                return true;
            }
            else
            {
                return false;
            }
        }    
    }
};