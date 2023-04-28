class Solution {
    public int numSimilarGroups(String[] strs) 
    {
        int n=strs.length;
        
        int parent[]=new int[n];
        for(int i=0;i<n;i++)
        parent[i]=i;
        
        
        for(int i=0;i<n;i++)
        {
            String s1=strs[i];
            
            for(int j=i+1;j<n;j++)
            {
                String s2=strs[j];
                
                if(!isSimilar(s1,s2))
                continue;
                
                int p1=findParent(i,parent);
                int p2=findParent(j,parent);
                
                parent[p1]=p2;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        ans=parent[i]==i?ans+1:ans;
        
        return ans;
    }
    
    public boolean isSimilar(String s1,String s2)
    {
        if(s1.equals(s2))
        return true;
        
        int diff=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s2.charAt(i)!=s1.charAt(i))
            diff++;
        }
        
        return diff<=2;
    }
    
    public int findParent(int i,int parent[])
    {
        if(parent[i]==i)
        return i;
        
        int p=findParent(parent[i],parent);
        parent[i]=p;
        
        return p;
    }
}