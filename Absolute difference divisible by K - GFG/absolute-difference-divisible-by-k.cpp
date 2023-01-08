//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int v[], int k) {
        int ans = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int rem = v[i]%k;
            mp[rem]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int c = it->second-1;
            ans += (c)*(c+1)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends