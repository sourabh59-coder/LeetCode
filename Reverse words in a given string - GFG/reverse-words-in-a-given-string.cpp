//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        s += '.';
        stack<string> st;
        string s1 = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='.')
            {
                s1 += s[i];
            }
            else
            {
                st.push(s1);
                s1 = "";
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            ans += '.';
            st.pop();
        }
        
        ans.erase(ans.begin()+ans.size()-1);
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends