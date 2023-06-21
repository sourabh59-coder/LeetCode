/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void fun(Node* &root)
    {
        if(root==NULL)  return;
        queue<Node* > qe;
        qe.push(root);
        
        while(!qe.empty())
        {
            int size = qe.size();
            
            Node* prev = NULL;
            
            for(int i=0;i<size;i++)
            {
                auto child = qe.front();
                qe.pop();
                
                child->next = prev;
                prev = child;
                
                if(child->right) qe.push(child->right);
                if(child->left)  qe.push(child->left);
            }
        }
    }
    Node* connect(Node* root) {
        Node* ans = root;
        
        fun(root);
        
        return ans;
    }
};