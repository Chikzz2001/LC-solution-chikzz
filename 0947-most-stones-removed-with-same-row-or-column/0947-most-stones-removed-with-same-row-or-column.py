class Solution:
    class DSU:
        def __init__(self,n):
            self.parent=[]
            self.size=[]
            for i in range(n):
                self.parent.append(i)
                self.size.append(1)
        
        def find(self,x)->int:
            if x==self.parent[x]:
                return x
            else:
                self.parent[x]=self.find(self.parent[x])
                return self.parent[x]
            
        def is_joined(self,a,b)->bool:
            parent_a=self.find(a)
            parent_b=self.find(b)
            if(parent_a==parent_b):
                return True;
            else:
                if(self.size[parent_a]>self.size[parent_b]):
                    self.parent[parent_b]=parent_a
                    self.size[parent_a]+=self.size[parent_b]
                else:
                    self.parent[parent_b]=parent_a
                    self.size[parent_b]+=self.size[parent_a]
                return False
                    

    def removeStones(self, stones: List[List[int]]) -> int:
        n=len(stones)
        dsu=self.DSU(n)
        
        for i in range(n):
            for j in range(i+1,n):
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]):
                    dsu.is_joined(i,j)
        
        for i in range(n):
            dsu.find(i)
        
        unique_sets=set()
        for i in range(n):
            unique_sets.add(dsu.parent[i])
        
        # for i in range(n):
        #     print(dsu.parent[i])

        return n-len(unique_sets)
        