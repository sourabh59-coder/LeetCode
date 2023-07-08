//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++)
        {
            int val = arr[i];
            int l = i+1;
            int r = (n-1);
            
            while(l<r)
            {
                int sum = val+arr[l]+arr[r];
                if(sum==0)
                {
                    return true;
                }
                else if(sum>0)
                {
                    r--;
                }
                else if(sum<0)
                {
                    l++;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends