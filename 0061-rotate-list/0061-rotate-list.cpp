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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)  return head;
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }

        k = k%cnt;
        if(k==0)   return head;

        int change = cnt - k -1;
        temp = head;

        while(change--)
        {
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        ListNode* ptr = ans;
        while(ptr->next!=NULL)  ptr = ptr->next;
        ptr->next = head;
        return ans;
    }
};