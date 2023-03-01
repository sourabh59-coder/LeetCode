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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fh = NULL , *ft = NULL;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        if(temp1==NULL)
        {
            return list2;
        }
        if(temp2==NULL)
        {
            return list1;
        }
        
        while(temp1!=NULL && temp2!=NULL)
        {
            int val1 = temp1->val, val2 = temp2->val;
            if(val1>val2)
            {
                if(fh==NULL)
                {
                    fh = temp2;
                    ft = temp2;
                }
                else
                {
                    ft->next = temp2;
                    ft = ft->next;
                }
                temp2 = temp2->next;
            }
            else
            {
                if(fh==NULL)
                {
                    fh = temp1;
                    ft = temp1;
                }
                else
                {
                    ft->next = temp1;
                    ft = ft->next;
                }
                temp1 = temp1->next;
            }
        }
        if(temp1!=NULL)
        {
            ft->next = temp1;
        }
        if(temp2!=NULL)
        {
            ft->next = temp2;
        }
        
        return fh;
    }
};