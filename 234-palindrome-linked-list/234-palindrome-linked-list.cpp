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
    ListNode* findmiddle(ListNode* head)
    {
        ListNode* slow=head,*fast=head;
        
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return !fast->next?slow:slow->next;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(!head||!head->next)return head;
        ListNode* prev=NULL,*curr=head,*next;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head||!head->next)return 1;
        
        ListNode* middle=findmiddle(head);
        middle=reverse(middle);
        
        cout<<middle->val;
        while(middle)
        {
            if(middle->val!=head->val)return 0;
            middle=middle->next;
            head=head->next;
        }
        return 1;
    }
};