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
    int f(ListNode *head)
    {
        int c=0;
        while(head)
        {
            c++;
            head = head->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = new ListNode(0);
        start->next = head;
        int count = f(head);
        ListNode *pre = start, *curr= start, *nex = start;
        
        while(count>=k)
        {
            curr = pre->next;
            nex = curr->next;
            
            for(int i=1;i<k;i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count -= k;
        }
        return start->next;
    }
};
