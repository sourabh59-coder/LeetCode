//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int fun(int v[],int ind,int k,vector<vector<int>> &dp)
    // {
    //     if(k==0)
    //     {
    //         return 1;
    //     }
        
    //     if(ind==0)
    //     {
    //         if(v[0]==k)
    //         {
    //             return 1;
    //         }
    //         else
    //         {
    //             return 0;
    //         }
    //     }
        
    //     if(dp[ind][k]!=-1)
    //     {
    //         return dp[ind][k];
    //     }
        
    //     int NotTake = fun(v,ind-1,k,dp);
        
    //     int Take = 0;
        
    //     if(k>=v[ind])
    //     {
    //         Take = fun(v,ind-1,k-v[ind],dp);
    //     }
        
    //     return dp[ind][k] = (Take|NotTake);
    // }
    int equalPartition(int n, int v[])
    {
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += v[i];
        }
        if(sum%2!=0)
        {
            return 0;
        }
        int val = sum/2;
        vector<vector<int>> dp(n,vector<int> ((val)+1,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        if(v[0]<=val)
        {
            dp[0][v[0]] = 1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=val;j++)
            {
                int NotTake = dp[i-1][j];
                
                int Take = 0;
                
                if(j>=v[i])
                {
                    Take = dp[i-1][j-v[i]];
                }
                
                dp[i][j] = NotTake | Take;
            }
        }
        // return fun(v,n-1,val,dp);
        return dp[n-1][val];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends