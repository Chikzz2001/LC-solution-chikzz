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
    vector<int> nextLargerNodes(ListNode* head) {
        
        stack<int>stack;
        vector<int>res;
        
        ListNode* prev=NULL,*curr=head,*next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        head=prev;
    
        while(head)
        {
            while(!stack.empty()&&stack.top()<=head->val)
                stack.pop();
            
            if(stack.empty())res.push_back(0);
            else
                res.push_back(stack.top());
            stack.push(head->val);
            head=head->next;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};