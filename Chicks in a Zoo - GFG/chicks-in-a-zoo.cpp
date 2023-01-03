//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    long long int dp[n];

     dp[0]=1;

     dp[1]=3;

     for(int i=2;i<=n;i++){

         if(i<=5){

             dp[i]=dp[i-1]+(dp[i-1]*2);

         }

         else if(i==6){

             dp[i]=dp[i-1]-dp[i-6];

             dp[i]=dp[i]+(dp[i]*2);

         }

         else{

            dp[i]=(dp[i-1]-(2*dp[i-6]/3))*3;

         }

         

     }

     return dp[n-1];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends