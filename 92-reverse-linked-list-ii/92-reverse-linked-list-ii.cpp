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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left==right)return head;
        left--;right--;
        
        right-=left;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* p=dummy,*start=head;
        
        while(left--)
        {p=start;start=start->next;}
        
        ListNode* prev=start,*curr=start->next,*next;
        
        while(curr&&right--)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        start->next=next;
        p->next=prev;
        
        return dummy->next;
    }
};