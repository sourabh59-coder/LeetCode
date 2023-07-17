class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> v1,v2;
        while(l1!=NULL)
        {
            v1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            v2.push(l2->val);
            l2 = l2->next;
        }
        
        stack<int> ans;
        int carry = 0;
        while(carry!=0 || !v1.empty() || !v2.empty())
        {
            int k1 = 0;
            int k2 = 0;
            
            if(!v1.empty())
            {
                k1 = v1.top();
                v1.pop();
            }
            
            if(!v2.empty())
            {
                k2 = v2.top();
                v2.pop();
            }
            
            int sum = k1+k2+carry;
            
            ans.push(sum%10);
            carry = sum/10;
        }
        
        ListNode* head = new ListNode(ans.top());
        ans.pop();
        ListNode* ptr = head;
        
        while(!ans.empty())
        {
            ListNode* temp = new ListNode(ans.top());
            ans.pop();
            ptr->next = temp;
            ptr = ptr->next;
        }
        
        return head;
    }
};