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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        
        if(l1->val > l2->val)
        {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        ListNode* ans = l1;
        ListNode* prev = l1;
        l1 = l1->next;
        
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                if(l1->val <= l2->val)
                {
                    prev->next = l1;
                    prev = l1;
                    l1 = l1->next;
                }
                else
                {
                    prev->next = l2;
                    prev = l2;
                    l2 = l2->next;
                }
            }
            else if(l2)
            {
                prev->next = l2;
                l2 = NULL;
            }
            else
            {
                prev->next = l1;
                l1 = NULL;
            }
        }
        
        return ans;
    }
};