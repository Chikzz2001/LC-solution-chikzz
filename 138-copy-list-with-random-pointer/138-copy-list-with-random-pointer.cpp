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
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return NULL;
        
        Node* temp=head;
        while(temp)
        {
            Node* next=temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=next;
            temp=temp->next->next;
        }
        
        Node* newhead=head->next;
        temp=head;
        
        while(temp)
        {
            temp->next->random=temp->random?temp->random->next:NULL;
            temp=temp->next->next;
        }
        
        Node* temp1=head,*temp2=head->next;
        while(temp1)
        {
            temp1->next=temp1->next?temp1->next->next:NULL;
            temp2->next=temp1->next?temp1->next->next:NULL;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return newhead;
    }
};

/*

7-->13-->11-->10-->1-->NULL

*/