/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* ,int> mp;
        ListNode* a = headA;
        while(a)
        {
            mp[a]++;
            a = a->next;
        }
        ListNode* b = headB;
        while(b)
        {
            if(mp.find(b)!=mp.end())
            {
                return b;
            }
            b = b->next;
        }
        
        return NULL;
    }
};