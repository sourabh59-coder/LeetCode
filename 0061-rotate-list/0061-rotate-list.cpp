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
        ListNode* ans;
        if(head==NULL || head->next==NULL || k==0)  return head;
        
        int cnt = 1;
        ListNode* temp = head;
        while(temp->next!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        k = k%cnt;
        if(k==0)      return head;
        temp->next = head;
        
        
        k = cnt-k;
        
        while(head!=NULL)
        {
            k--;
            if(k==0)
            {
                ans = head->next;
                head->next = NULL;
                return ans;
            }
            head = head->next;
        }
        
        return head;
    }
};