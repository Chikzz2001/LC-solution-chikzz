/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*,Node*>cloned;
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        if(cloned.count(node))return cloned[node];
        cloned[node]=new Node(node->val,{});
        for(auto nbr:node->neighbors)
        {
            cloned[node]->neighbors.push_back(cloneGraph(nbr));
        }
        //cloned[node]=clone;
        return cloned[node];
    }
};