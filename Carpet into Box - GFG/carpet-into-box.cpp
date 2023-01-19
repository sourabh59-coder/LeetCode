//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int fun(int a,int b)
    {
        if(b>=a)    return 0;
        else    return (1+fun(a/2,b));
    }
    int carpetBox(int A, int B, int C, int D){
        int ans = min(fun(A,C)+fun(B,D),fun(A,D)+fun(B,C));
        
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends