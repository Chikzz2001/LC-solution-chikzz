/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        //original1-->copy1-->original2-->copy2....
        
        Node* temp,*traverse=head;
        
        while(traverse)
        {
            Node* copy_node=new Node(traverse->val);
            Node* temp=traverse->next;
            traverse->next=copy_node;
            copy_node->next=temp;
            traverse=temp;
        }
       
        traverse=head;
        
        while(traverse)
        {
            traverse->next->random=traverse->random?traverse->random->next:NULL;
            traverse=traverse->next->next;
        }
        
        Node* dummy=new Node(0);
        Node* t=dummy;
        traverse=head;
        
        while(traverse)
        {
            Node* next=traverse->next->next;
            t->next=traverse->next;
            t=t->next;
            traverse->next=next;
            traverse=next;
        }
        
        return dummy->next;
    }
};