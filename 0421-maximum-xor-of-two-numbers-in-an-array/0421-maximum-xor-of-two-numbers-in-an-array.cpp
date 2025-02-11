class Node{
    public:
        Node* list[2];
        bool flag = false;

        bool containKey(int ind)
        {
            return (list[ind]!=NULL);
        }

        void put(int ind,Node* new_node)
        {
            list[ind] = new_node;
        }

        Node* get(int ind)
        {
            return list[ind];
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
                int val;
                if((1<<i)&n)    val = 1;
                else            val = 0;
                if(!temp->containKey(val))
                {
                    temp->put(val,new Node());
                }
                temp = temp->get(val);
            }
            temp->setEnd();
        }

        int XorHelper(int n)
        {
            Node* temp = root;
            int ans = 0;
            for(int i=31;i>=0;i--)
            {
                int mask = (1<<i);
                int val;
                if((mask & n) == 0) val = 1;
                else    val = 0;
                // int val = 1 - ( mask & n );
                if(temp->containKey(val))
                {
                    ans += mask;
                    temp = temp->get(val);
                }
                else
                {
                    temp = temp->get(1-val);
                }
            }
            return ans;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tries obj;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            obj.Insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int val = obj.XorHelper(nums[i]);
            ans = max(ans,val);
        }
        return ans;
    }
};