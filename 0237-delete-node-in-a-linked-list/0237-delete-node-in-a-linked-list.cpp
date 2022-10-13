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
    void deleteNode(ListNode* node) 
    {
        int val=node->next->val;
        
        ListNode* del=node->next;
        node->next=del->next;
        
        node->val=val;
    }
};