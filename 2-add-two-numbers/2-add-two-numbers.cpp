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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy=new ListNode(0);
        dummy->next=l1;
        ListNode* temp;
        temp=dummy;
        
        ListNode* prev;
        int carry=0;
        while(l1&&l2)
        {
            temp=temp->next;
            prev=temp;
            int sum=l1->val+l2->val+carry;
            temp->val=sum%10;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1){temp->next=l1;temp=l1;}
        while(l1)
        {
            prev=temp;
            int sum=l1->val+carry;
            temp->val=sum%10;
            carry=sum/10;
            l1=l1->next;
            temp=temp->next;
        }
        
        if(l2){temp->next=l2;temp=l2;}
        while(l2)
        {
            prev=temp;
            int sum=l2->val+carry;
            temp->val=sum%10;
            carry=sum/10;
            l2=l2->next;
            temp=temp->next;
        }
        
        if(carry)prev->next=new ListNode(carry);
        
        return dummy->next; 
    }
};