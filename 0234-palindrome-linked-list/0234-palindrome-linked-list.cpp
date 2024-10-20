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
    ListNode* reverseLL(ListNode* head)
    {
        if(!head ||  !head->next)   return head;

        ListNode* prev = NULL;
        ListNode* ptr = head;

        while(ptr!=NULL)
        {
            ListNode* next_ptr = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next_ptr;
        }

        return prev;
    }
    ListNode* middleLL(ListNode* head)
    {
        if(!head || !head->next)    return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = middleLL(head);
        p2 = reverseLL(p2);

        while(p1 && p2)
        {
            if(p1->val!=p2->val)
            {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }


        return true;
    }
};