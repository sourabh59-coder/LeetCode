//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        // b -> 1
        // a -> 1
        // l -> 2
        // o -> 2
        // n -> 1
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++)
        {
            int val = s[i]-'a';
            v[val]++;
        }
        int ans = INT_MAX;
        ans = min(ans,v['b'-'a']);
        ans = min(ans,v[0]);
        ans = min(ans,v['l'-'a']/2);
        ans = min(ans,v['o'-'a']/2);
        ans = min(ans,v['n'-'a']);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends