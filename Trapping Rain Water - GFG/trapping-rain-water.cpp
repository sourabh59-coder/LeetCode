//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> vl(n,0);
        vector<int> vr(n,0);
        
        for(int i=0;i<n;i++)
        {
            vl[i] = arr[i];
            vr[i] = arr[i];
        }
        
        for(int i=1;i<n;i++)
        {
            vl[i] = max(vl[i],vl[i-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            vr[i] = max(vr[i],vr[i+1]);
        }
        
        long long ans = 0;
        for(int i=1;i<n-1;i++)
        {
            int val = min(vr[i],vl[i]);
            ans += val-arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends