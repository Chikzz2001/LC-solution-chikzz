# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return []
        queue=Queue(maxsize=0)
        queue.put(root)
        res=[]
        while(queue.qsize()>0):
            size=queue.qsize()
            a=[]
            while size>0:
                curr=queue.get()
                a.append(curr.val)
                if curr.left!=None:
                    queue.put(curr.left)
                if curr.right!=None:
                    queue.put(curr.right)
                size=size-1
            res.append(a)
        return res
                
                
            
            
            
        