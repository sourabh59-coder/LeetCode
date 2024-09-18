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
    Node* connect(Node* root) {
        Node* ans = root;
        if(root==NULL)  return ans;
        queue<Node*> qe;
        qe.push(root);

        while(!qe.empty())
        {
            int si = qe.size();
            Node* prev = NULL;

            for(int sp=0;sp<si;sp++)
            {
                auto it = qe.front();
                qe.pop();

                if(prev!=NULL)  prev->next = it;

                if(it->left)    qe.push(it->left);
                if(it->right)   qe.push(it->right);
                it->next = NULL;
                prev = it;
            }
        }

        return ans;
    }
};