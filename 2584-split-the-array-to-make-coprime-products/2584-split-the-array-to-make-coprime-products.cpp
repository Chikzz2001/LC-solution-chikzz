class Solution {
    vector<bool>sieve;
    void primeSieve(int n){sieve[0]=sieve[1]=0;for (int i=2;i*i<n;i++){if(sieve[i]){for(int j=i*i;j<n;j+=i)sieve[j]=0;}}}
public:
    int findValidSplit(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        sieve=vector<bool>(maxx+1,1);
        primeSieve(maxx+1);
        int n=nums.size();
        unordered_map<int,int>p,s;
        
        for(int i=n-1;i>=0;i--) {
            for(int j=1;j<=sqrt(nums[i]);j++) {
                
                if(nums[i]%j==0) {
                    if(sieve[j]) {
                        s[j]++;
                    }
                    if(sieve[nums[i]/j]) {
                        s[nums[i]/j]++;
                    }
                }
            }
        }
        
        for(int i=0;i<n-1;i++) {
            bool f1=1,f2=1;
            for(int j=1;j<=sqrt(nums[i]);j++) {
                if(nums[i]%j==0) {
                    if(sieve[j]) {
                            p[j]++;
                            s[j]--;
                            if(s[j])f1=0;
                        else{s.erase(j);p.erase(j);}
                        
                    }
                    if(sieve[nums[i]/j]) {
                            p[nums[i]/j]++;
                            s[nums[i]/j]--;
                            if(s[nums[i]/j])f2=0;
                        else{s.erase(nums[i]/j);p.erase(nums[i]/j);}
                        
                    }
                }
            }
            
            bool f=1;
            if(f1||f2) {
                for(auto &[x,y]:p) {
                if(s.count(x)){f=0;break;}
            }
                for(auto &[x,y]:s) {
                    if(p.count(x)){f=0;break;}
                }
            }
            if((f1|f2)&f)return i;
        }
        return -1;
    }
};
