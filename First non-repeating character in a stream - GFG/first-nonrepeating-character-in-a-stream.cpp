//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		 string FirstNonRepeating(string A){
      
            unordered_map<char,int> count;
            string ans;
            queue<char> q;
            for(int i=0;i<A.length();i++)
            {
                char element=A[i];
                count[element]++;
                if(count[element]==1)
                q.push(element);
                
                while(!q.empty()&&count[q.front()]>1)
                {
                    q.pop();
                }
                if(q.empty())
                ans.push_back('#');
                else
                ans.push_back(q.front());
               
            }
            return ans;
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends