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
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode* dummy=new ListNode(-5001);
        dummy->next=head;
        ListNode* curr=dummy->next,*prev=dummy;
        
        while(curr)
        {
            if(curr->val>=prev->val)
            {
                curr=curr->next;
                prev=prev->next;
            }
            else
            {
                ListNode* node=curr;
                prev->next=curr->next;
                ListNode* temp=dummy;
                while(temp)
                {
                    if(temp->next&&temp->next->val>node->val)break;
                    temp=temp->next;
                }
                ListNode* next=temp->next;
                temp->next=node;
                node->next=next;
                curr=prev->next;
            }
        }
        return dummy->next;
    }
};