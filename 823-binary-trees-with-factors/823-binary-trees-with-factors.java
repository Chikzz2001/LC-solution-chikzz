class Solution 
{
    int mod=(int)Math.pow(10,9)+7;
    
    public int numFactoredBinaryTrees(int[] arr) 
    {
        int n=arr.length;
        long ans=0;
        
        Arrays.sort(arr);
        
        long count[]=new long[n];
        count[0]=1;ans++;
        
        for(int i=1;i<n;i++)
        {
            count[i]=1;
            Map<Integer,Integer> map=new HashMap<>();
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    map.put(arr[j],j);
                    
                    if(map.containsKey(arr[i]/arr[j]))
                    {
                        long x=count[j]%mod;
                        long y=count[map.get(arr[i]/arr[j])]%mod;
                        
                        long prod=(x*y)%mod;
                        count[i]=((count[i]%mod)+(prod%mod))%mod;
                        
                        if(arr[i]/arr[j]!=arr[j])
                        count[i]=((count[i]%mod)+(prod%mod))%mod;
                    }
                }
            }
            ans=((ans%mod)+(count[i]%mod))%mod;
        }
        
        return (int)(ans%mod);
        
    }
}