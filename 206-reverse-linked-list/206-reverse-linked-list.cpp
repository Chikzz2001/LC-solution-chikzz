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
    ListNode* res;
    void reverse(ListNode* head)
    {
        if(!head->next)
        {
            res=head;
            return;
        }
        
        reverse(head->next);
        
        ListNode* next=head->next;
        next->next=head;
        head->next=NULL;
    }
public:
    ListNode* reverseList(ListNode* head) {
 
         if(!head||!head->next)return head;
        // ListNode* prev=NULL,*curr=head,*next=NULL;
        // while(curr)
        // {
        //     next=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=next;
        // }
        // return prev;
        
        reverse(head);
        return res;
    }
};