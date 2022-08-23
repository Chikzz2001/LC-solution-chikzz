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
//     ListNode* merge2LL(ListNode* l1,ListNode* l2)
//     {
//         ListNode* dummy=new ListNode(0);
//         ListNode* temp=dummy;
        
//         while(l1&&l2)
//         {
//             if(l1->val<l2->val)
//             {
//                 temp->next=l1;
//                 l1=l1->next;
//             }
//             else
//             {
//                 temp->next=l2;
//                 l2=l2->next;
//             }
//             temp=temp->next;
//         }
        
//         if(l1)temp->next=l1;
//         if(l2)temp->next=l2;
        
//         return dummy->next;
//     }
//     ListNode* merge(vector<ListNode*>& lists,int s,int e)
//     {
//         if(s>e)
//             return NULL;
//         if(s==e)return lists[s];
        
//         int m=s+(e-s)/2;
//         ListNode* l=merge(lists,s,m);
//         ListNode* r=merge(lists,m+1,e);
        
//         ListNode* res=merge2LL(l,r);
//         return res;
//     }
    
    struct comp
    {
        bool operator()(const ListNode* l1,const ListNode* l2)
        {
            return l1->val>l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,comp>pQ;
        ListNode* dummy=new ListNode(0);
        
        for(auto &l:lists)
        {
            if(l)
            pQ.push(l);
        }
        
        ListNode* temp=dummy;
        
        while(!pQ.empty())
        {
            ListNode* curr=pQ.top();
            pQ.pop();
            temp->next=curr;
            temp=temp->next;
            curr=curr->next;
            if(curr)
                pQ.push(curr);
        }
        return dummy->next;
        //return merge(lists,0,lists.size()-1);
    }
};