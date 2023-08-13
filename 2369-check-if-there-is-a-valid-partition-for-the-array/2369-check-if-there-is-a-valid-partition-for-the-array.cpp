class Solution {
public:
    bool f=false;
    int dp[100005];
    void fun(vector<int>&v , int ind) {
          if(ind==v.size()-2)  {
              if(v[ind]==v[ind+1]) f=true;
          }
          if(dp[ind]!=-1) return ;
          if(ind==v.size()-3) {
              if(v[ind]==v[ind+1] && v[ind]==v[ind+2]) f= true;
              if(v[ind]==v[ind+1]-1 && v[ind+1]==v[ind+2]-1) f= true;
          }

           if(ind<v.size()-2)  {
              if(v[ind]==v[ind+1]) fun(v,ind+2);
          }
          if(ind<v.size()-3) {
              if(v[ind]==v[ind+1] && v[ind]==v[ind+2]) fun(v,ind+3);
              if(v[ind]==v[ind+1]-1 && v[ind+1]==v[ind+2]-1) fun(v,ind+3);
          }
        dp[ind]=f;
         
    }
    bool validPartition(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        if(v.size()==2) {
            if(v[0]==v[1]) return true;
            return false;
        }
         fun(v,0);
        return f;
    }
};