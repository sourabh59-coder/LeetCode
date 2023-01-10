//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        priority_queue<int> qe;
        
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            qe.push(it->second);
        }
        
        int ans = 0;
        while(k--)
        {
            int val = qe.top()-1;
            qe.pop();
            qe.push(val);
        }
        
        while(!qe.empty())
        {
            ans += (qe.top()*qe.top());
            qe.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends