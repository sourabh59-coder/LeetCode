/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        
        vector<int> v;
        
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        v.erase(v.end()-n);
        
        if(v.empty())
        {
            return NULL;
        }
        
        ListNode* ptr = new ListNode(v[0]);
        ListNode* tem = ptr;
        
        for(int i=1;i<v.size();i++)
        {
            ListNode* ptr1 = new ListNode(v[i]);
            tem->next = ptr1;
            tem = tem->next;
        }
        
        return ptr;
    }
};