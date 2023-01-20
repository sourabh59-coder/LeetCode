//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans = 0;
        int p = 0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='-' && i==0)
            {
                ans = (-1)*ans;
                return ans;
            }
            if(s[i]>='0' && s[i]<='9')
            {
                int val = s[i]-'0';
                ans += val*pow(10,p);
                p++;
            }
            else
            {
                return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends