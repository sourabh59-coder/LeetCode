class Node{
    public:
        Node* list[2];
        bool flag;

        Node()
        {
            for(int i=0;i<2;i++)    list[i] = NULL;
            flag = false;
        }

        bool containKey(int ind)
        {
            return (list[ind]!=NULL);
        }

        Node* get(int ind)
        {
            return list[ind];
        }

        void put(int ind,Node* new_node)
        {
            list[ind] = new_node;
        }


        void setEnd()
        {
            flag = true;
        }

        bool isEnd()
        {
            return flag;
        }

};

class Tries{
    public:
        Node* root;

        Tries()
        {
            root = new Node();
        }

        void Insert(int n)
        {
            Node* temp = root;

            for(int i=31;i>=0;i--)
            {
                int mask = (1<<i);
                int val;
                if((mask&n)==0) val = 0;
                else            val = 1;

                if(!temp->containKey(val))
                {
                    temp->put(val,new Node());
                }
                temp = temp->get(val);
            }
        }

        int XorHelper(int n)
        {
            Node* temp = root;
            int ans = 0;

            for(int i=31;i>=0;i--)
            {
                int mask = (1<<i);
                int val;
                if((mask&n)==0) val = 0;
                else            val = 1;

                if(temp->containKey(1-val))
                {
                    ans += mask;
                    temp = temp->get(1-val);
                }
                else
                {
                    temp = temp->get(val);
                }
            }
            return ans;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<pair<int,pair<int,int>>> qe;
        for(int i=0;i<q.size();i++)
        {
            int x = q[i][0];
            int m = q[i][1];

            qe.push_back({m,{x,i}});
        }
        sort(qe.begin(),qe.end());
        Tries obj;
        int start = 0;

        vector<int> ans(qe.size(),0);

        for(int i=0;i<qe.size();i++)
        {
            int m = qe[i].first;
            int x = qe[i].second.first;
            int ind = qe[i].second.second;

            while(start<n && v[start]<=m)
            {
                obj.Insert(v[start]);
                start++;
            }

            if (start == 0)  
                ans[ind] = -1;
            else
                ans[ind] = obj.XorHelper(x);
        }

        return ans;
    }
};