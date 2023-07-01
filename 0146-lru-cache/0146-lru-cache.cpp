class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key,int _val)
            {
                key = _key;
                val = _val;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    unordered_map<int,node* > mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }
    
    void deleteNode(node* deletenode)
    {
        node* delprev = deletenode->prev;
        node* delnext = deletenode->next;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    int get(int _key) {
        if(mp.find(_key)!=mp.end())
        {
            node* res = mp[_key];
            int val = res->val;
            mp.erase(_key);
            deleteNode(res);
            addnode(res);
            mp[_key] = head->next;
            return val;
        }
        
        
        return -1;
    }
    
    void put(int _key, int value) {
        if(mp.find(_key)!=mp.end())
        {
            node* ptr = mp[_key];
            mp.erase(_key);
            deleteNode(ptr);
        }
        if(cap==mp.size())
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addnode(new node(_key,value));
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */