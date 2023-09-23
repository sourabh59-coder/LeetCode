class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> map;
        int n=words.size();
        if(n==1){
            return n;
        }
        int res=1;
        sort(words.begin(), words.end(), [] (const std::string& first, const std::string& second){ return first.size() < second.size();});
        
        for(int i=0;i<n;i++){    
            for(int k=0;k<words[i].length();k++){
                string a=words[i].substr(0,k)+words[i].substr(k+1);
                if(map.find(a)!=map.end()){
                    map[words[i]]=max(map[words[i]],map[a]+1);  
                }  
                else{
                    map[words[i]]=max(map[words[i]],1);  

                }
            }
            res=max(res,map[words[i]]);
        }
        return res;
    }
};