# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return []
        queue=[]
        queue.append(root)
        res=[]
        while(len(queue)>0):
            size=len(queue)
            a=[]
            while size>0:
                curr=queue.pop(0)
                a.append(curr.val)
                if curr.left!=None:
                    queue.append(curr.left)
                if curr.right!=None:
                    queue.append(curr.right)
                size=size-1
            res.append(a)
        return res
                
                
            
            
            
        