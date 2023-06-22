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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* cntv = head;
        
        while(cntv!=NULL)
        {
            cnt++;
            cntv = cntv->next;
        }
        
        int val = (cnt/2)+1;
        
        ListNode* ans = head;
        
        while(head!=NULL)
        {
            if(val==0)  break;
            val--;
            ans = head;
            head = head->next;
        }
        return ans;
    }
};