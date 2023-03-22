class Solution {
public:
    int min(int a,int b)
    {
        if(a<b)
        {
            return a;
        }
        return b;
    }
    vector<int> smallestRange(vector<vector<int>>& v) {
        vector<int> ch(v.size(),0);
        int a,b;
        int val = INT_MAX;
        set<pair<int,int>> st;
        int len = INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            len = min(len,v[i].size());
            st.insert({v[i][0],i});
        }
        a = st.begin()->first;
        b = (st.rbegin())->first;
        val = min(b-a,val);
        while(true)
        {
            int ind = st.begin()->second;
            ch[ind]++;
            if(ch[ind]==v[ind].size())
            {
                break;
            }
            st.erase(st.begin());
            st.insert({v[ind][ch[ind]],ind});
            int c = st.begin()->first;
            int d = (st.rbegin())->first;
            if(d-c<val)
            {
                val = d-c;
                a = c;
                b = d;
            }
        }
        
        return {a,b};
    }
};