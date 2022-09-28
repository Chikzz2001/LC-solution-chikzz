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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //use dummy nodes to handle edge cases
        ListNode* prev=head,*last=head,*dummy=new ListNode(0),*t=dummy;
        dummy->next=head;
        
        while(n--)
            last=last->next;
    
        while(last)
        {
            t=prev;
            prev=prev->next;
            last=last->next;
        }
    
        t->next=prev->next;
        
        return dummy->next;
    }
};