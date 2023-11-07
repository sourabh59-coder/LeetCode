class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
              int n  =dist.size();
    if(n==1) return 1;
    vector<int>time(n);
    for(int i=0;i<n;i++){
        time[i] = (dist[i])/speed[i] +( dist[i]%speed[i]!=0?1:0);
    }
    sort(time.begin() , time.end());
    int ans = 1;
    int mins = 1;
    for(int i=1;i<time.size();i++){
        time[i] -= mins;
        if(time[i]>0){
          ans++;
          mins++;
        }else break;
    }
    return ans;
    }
};