class Node{
public:
    Node* list[26];
    bool flag;

    Node()
    {
        for(int i=0;i<26;i++)   list[i] = NULL;
        flag = false;
    }

    bool containKey(char ch)
    {
        return (list[ch-'a']!=NULL);
    }

    void put(char ch,Node* new_node)
    {
        list[ch-'a'] = new_node;
    }

    Node* get(char ch)
    {
        return list[ch-'a'];
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag = true;
    }

    bool empty()
    {
        for(auto it: list)  if(it!=NULL)    return false;
        return true;
    }

    void notEnd()
    {
        flag = false;
    }
};


class Trie{
public:
    Node* root;

    Trie()
    {
        root = new Node();
    }    

    void insert(string word)
    {
        Node* temp = root;

        for(auto it : word)
        {
            if(!temp->containKey(it))
            {
                Node* new_node = new Node();
                temp->put(it,new_node);
            }
            temp = temp->get(it);
        }

        temp->setEnd();
    }

    bool search(string word)
    {
        Node* temp = root;

        for(auto it: word)
        {
            if(!temp->containKey(it))   return false;
            temp = temp->get(it);
        }

        return (temp->isEnd());
    }

    bool prefix(string word)
    {
        Node* temp = root;

        for(auto it: word)
        {
            if(!temp->containKey(it))   return false;
            temp = temp->get(it);
        }

        return true;
    }

    
};


class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(vector<vector<char>> &board,int i,int j,string &temp,vector<string> &ans,Node* root,vector<vector<int>> &vis)
    {
        int n = board.size();
        int m = board[0].size();
        if (root == nullptr) return;

        if(root->isEnd())
        {
            ans.push_back(temp);
            root->notEnd();
        }

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(check(x,y,n,m) && !vis[x][y] && root->containKey(board[x][y]))
            {
                vis[x][y] = 1;
                temp.push_back(board[x][y]);
                dfs(board,x,y,temp,ans,root->get(board[x][y]),vis);
                vis[x][y] = 0;
                temp.pop_back();
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie obj;
        for(auto it: words)
        {
            obj.insert(it);
        }

        int n = board.size();
        int m = board[0].size();

        string temp = "";
        vector<string> ans;

        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obj.root->containKey(board[i][j]))
                {
                    vis[i][j] = 1;
                    temp.push_back(board[i][j]);
                    dfs(board,i,j,temp,ans,obj.root->get(board[i][j]),vis);
                    temp.pop_back();
                    vis[i][j] = 0;
                }
            }
        }

        return ans;
    }
};