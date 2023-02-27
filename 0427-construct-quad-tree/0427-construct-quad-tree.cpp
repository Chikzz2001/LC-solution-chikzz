/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* construct(vector<vector<int>>& grid,int ti,int tj,int n) {
        if(!n) {
            Node* node=new Node(grid[ti][tj],1);
            return node;
        }
        
        int c1=0;
        for(int i=ti;i<=ti+n;i++) {
            for(int j=tj;j<=tj+n;j++) {
                c1+=(grid[i][j]==1);
            }
        }
       
        if(c1==(n+1)*(n+1))return new Node(1,1);
        else if(c1==0)return new Node(0,1);
        else {
            Node* tl,*tr,*bl,*br;
            tl=construct(grid,ti,tj,n>>1);
            tr=construct(grid,ti,tj+n/2+1,n>>1);
            bl=construct(grid,ti+n/2+1,tj,n>>1);
            br=construct(grid,ti+n/2+1,tj+n/2+1,n>>1);
            Node* node=new Node(1,0,tl,tr,bl,br);
            return  node;
        }
        return NULL;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int ti=0,tj=0,n=grid.size()-1;
        return construct(grid,ti,tj,n);
    }
};