//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

using ll = long long;
class Solution{
    public:
    ll max(ll a,ll b){
        if(a>b)
            return a;
        return b;
    }
    long long maxSubarraySum(int arr[], int n){
        ll sum=0,best=INT_MIN;
        for(int i=0;i<n;i++){
            sum=max(arr[i],arr[i]+sum);
            best=max(best,sum);
        }
        return best;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends