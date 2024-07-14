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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)  st.insert(nums[i]);
        while(head!=NULL)
        {
            if(st.count(head->val)==0)  
            {
                ListNode* temp = new ListNode(head->val);
                ptr->next = temp;
                ptr = ptr->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};