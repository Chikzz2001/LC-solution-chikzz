class Solution {
    int MOD=1000000007;
    public int numWays(String[] words, String target) {
        int N=words[0].length(),M=target.length();
        long dp[][]=new long[N+1][M+1];
        long v[][]=new long[N+1][26];
        
        for(int i=0;i<N;i++) {
            for(String x:words) {
                v[i][x.charAt(i)-'a']++;
            }
        }
        
        for(int i=0;i<=M;i++)dp[N][i]=0;
        for(int i=0;i<=N;i++)dp[i][M]=1;
        
        for(int i=N-1;i>=0;i--) {
            for(int j=M-1;j>=0;j--) {
                dp[i][j]=(dp[i+1][j]%MOD+(v[i][target.charAt(j)-'a']%MOD*dp[i+1][j+1]%MOD)%MOD)%MOD;
            }
        }
        
        return (int)dp[0][0];
    }
}