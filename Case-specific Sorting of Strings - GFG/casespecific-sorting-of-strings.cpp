//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string ans = "";
        string lower = "";
        string upper = "";
        
        for(int i=0;i<n;i++)
        {
            if(isupper(str[i]))
            {
                upper += str[i];
            }
            else
            {
                lower += str[i];
            }
        }
        
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        
        int u = 0;
        int l = 0;
        
        for(int i=0;i<n;i++)
        {
            if(isupper(str[i]))
            {
                str[i] = upper[u++];
            }
            else
            {
                str[i] = lower[l++];
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends