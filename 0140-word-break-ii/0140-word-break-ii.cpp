class Node{
public:
    Node* list[26];
    bool flag ;

    Node()
    {
        for(int i=0;i<26;i++)   list[i] = NULL;
        flag = false;
    }    

    bool containKey(char ch)
    {
        return (list[ch-'a']!=NULL);
    }

    void set(char ch,Node* new_node)
    {
        list[ch-'a'] = new_node;
    }

    Node* get(char ch)
    {
        return list[ch-'a'];
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


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;

        for(auto it: word)
        {
            if(!temp->containKey(it))
            {
                Node* new_node = new Node();
                temp->set(it,new_node);
            }
            temp = temp->get(it);
        }

        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto it:word)
        {
            if(!temp->containKey(it))
            {
                return false;
            }

            temp = temp->get(it);
        }

        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto it:prefix)
        {
            if(!temp->containKey(it))
            {
                return false;
            }

            temp = temp->get(it);
        }

        return true;
    }

    void fun(string s,int ind,int n,Node* temp,string &ds,vector<string> &ans)
    {
        if(ind==n-1)
        {
            if(temp->containKey(s[ind]) && temp->get(s[ind])->isEnd()){
                ds.push_back(s[ind]);
                ans.push_back(ds);
                ds.pop_back();
            }
            return;
        }

        char ch = s[ind];

        if(temp->containKey(ch))
        {
            temp = temp->get(ch);
            ds.push_back(ch);
            if(temp->isEnd())
            {
                ds.push_back(' ');
                fun(s,ind+1,n,root,ds,ans);
                ds.pop_back();
            }   
            fun(s,ind+1,n,temp,ds,ans);
            ds.pop_back();
        }
    }

    void helper(string s,vector<string> &ans) {
        int n = s.length();
        string ds = "";
        string push_str = "";
        fun(s, 0, n, root,ds, ans);
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie obj;
        for(auto it: wordDict)
        {
            obj.insert(it);
        }
        vector<string> ans;
        obj.helper(s,ans);
        return ans;
    }
};