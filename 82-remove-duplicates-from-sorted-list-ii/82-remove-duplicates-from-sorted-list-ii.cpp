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
    ListNode* deleteDuplicates(ListNode* head) {
        while(!head||!head->next)return head;
        
        ListNode* dummy=new ListNode(-101,head);
        ListNode* prev=dummy,*traverse=head;
        
        while(traverse)
        {
            if(traverse->next&&traverse->val==traverse->next->val)
            {
                int repeat=traverse->val;
                while(traverse&&traverse->val==repeat)
                    traverse=traverse->next;
            }
            else
            {
                prev->next=traverse;
                traverse=traverse->next;
                prev=prev->next;
            }
        }
        prev->next=NULL;
        
        return prev==dummy?NULL:dummy->next;
    }
};