class Node{
    public:
        Node* list[26];
        bool flag = false;

        bool containKey(char ch)
        {
            return (list[ch-'a']!=NULL);
        }

        Node* get(char ch)
        {
            return list[ch-'a'];
        }

        void put(char ch,Node* new_node)
        {
            list[ch-'a'] = new_node;
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
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(!temp->containKey(ch))
            {
                temp->put(ch,new Node());
            }
            temp = temp->get(ch);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(!temp->containKey(ch))
            {
                return false;
            }
            temp = temp->get(ch);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.size();i++)
        {
            char ch = prefix[i];
            if(!temp->containKey(ch))
            {
                return false;
            }
            temp = temp->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */