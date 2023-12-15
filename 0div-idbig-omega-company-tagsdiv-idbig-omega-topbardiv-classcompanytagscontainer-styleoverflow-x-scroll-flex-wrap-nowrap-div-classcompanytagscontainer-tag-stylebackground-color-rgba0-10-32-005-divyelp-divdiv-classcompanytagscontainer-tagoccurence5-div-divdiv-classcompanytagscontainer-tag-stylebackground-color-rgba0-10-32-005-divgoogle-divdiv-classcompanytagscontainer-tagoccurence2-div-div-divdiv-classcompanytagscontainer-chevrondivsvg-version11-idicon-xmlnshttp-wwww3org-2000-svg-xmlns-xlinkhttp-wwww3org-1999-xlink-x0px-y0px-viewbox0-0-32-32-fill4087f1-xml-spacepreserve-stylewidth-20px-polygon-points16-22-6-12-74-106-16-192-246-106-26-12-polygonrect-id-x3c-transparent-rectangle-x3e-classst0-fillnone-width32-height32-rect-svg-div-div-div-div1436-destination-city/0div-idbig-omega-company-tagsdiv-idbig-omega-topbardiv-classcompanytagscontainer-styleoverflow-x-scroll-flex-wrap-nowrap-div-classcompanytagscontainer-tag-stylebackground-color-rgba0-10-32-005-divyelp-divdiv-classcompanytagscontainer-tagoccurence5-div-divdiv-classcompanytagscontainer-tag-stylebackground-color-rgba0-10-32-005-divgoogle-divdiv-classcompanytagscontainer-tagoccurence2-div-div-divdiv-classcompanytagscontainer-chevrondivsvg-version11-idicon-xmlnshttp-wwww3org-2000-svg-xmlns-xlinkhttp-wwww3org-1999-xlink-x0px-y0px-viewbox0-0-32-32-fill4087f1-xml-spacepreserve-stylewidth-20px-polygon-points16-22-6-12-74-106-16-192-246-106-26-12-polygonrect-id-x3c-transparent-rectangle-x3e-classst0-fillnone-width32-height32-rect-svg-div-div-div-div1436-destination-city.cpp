class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans="";
        int n=paths.size();
        if(n==1) return paths[0][1];
        int i=0;
        bool flag=true;
        int it=0;
        while(flag==true){
            
            for(int j=0;j<n;j++){
                flag=false;
                if(paths[j][0]==paths[i][1]){
                    i=j;
                    j=n;
                    flag=true;
                }
            }
              
            if(paths[it][1]==paths[i][0]){
                   it=i;
               }
        } 
        return paths[it][1];
    }
};