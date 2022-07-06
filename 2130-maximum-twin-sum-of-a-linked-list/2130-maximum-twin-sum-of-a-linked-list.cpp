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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=head,*fast=head;
        while(fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* res=slow->next;
        slow->next=NULL;
        return res;
    }
    ListNode* reverse(ListNode* head)
    {
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
    int pairSum(ListNode* head) 
    {
        ListNode* middle=findMiddle(head);
        
        middle=reverse(middle);
        
        int maxx=0;
        while(head)
        {
            maxx=max(maxx,head->val+middle->val);
            head=head->next;
            middle=middle->next;
        }
        return maxx;
    }
};