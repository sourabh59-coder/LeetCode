//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        long long int sum=0;

        sort(a,a+n);// ascending order

        sort(b,b+n);// ascending order

        int i=0; // initialise to start element to the first index

        int j=n-1;// make it reverse by  starting from end

        while(i<n){

            sum+=a[i]*b[j];// logic

            i++;

            j--;

        }

        return sum;

    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends