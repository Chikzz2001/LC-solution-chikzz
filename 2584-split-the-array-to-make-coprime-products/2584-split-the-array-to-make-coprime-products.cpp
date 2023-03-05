#define ll long long
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
            bool f=1;
            for(int j=1;j<=sqrt(nums[i]);j++) {
                if(nums[i]%j==0) {
                    if(sieve[j]) {
                            p[j]++;
                            s[j]--;
                            if(s[j])f=0;
                        else{s.erase(j);p.erase(j);}
                        
                    }
                    if(sieve[nums[i]/j]) {
                            p[nums[i]/j]++;
                            s[nums[i]/j]--;
                            if(s[nums[i]/j])f=0;
                        else{s.erase(nums[i]/j);p.erase(nums[i]/j);}
                        
                    }
                }
            }
            
            if(f) {
                for(auto &[x,y]:p) {
                if(s.count(x)){f=0;break;}
            }
                for(auto &[x,y]:s) {
                    if(p.count(x)){f=0;break;}
                }
            }
            
            // if(!f)continue;
            // if(p.size())
            if(f)return i;
        }
        return -1;
    }
};

/*
[4,7,8,15,3,5]
2 14 14 14*3*5 

[557663,280817,472963,156253,273349,884803,756869,763183,557663,964357,821411,887849,891133,453379,464279,574373,852749,15031,156253,360169,526159,410203,6101,954851,860599,802573,971693,279173,134243,187367,896953,665011,277747,439441,225683,555143,496303,290317,652033,713311,230107,770047,308323,319607,772907,627217,119311,922463,119311,641131,922463,404773,728417,948281,612373,857707,990589,12739,9127,857963,53113,956003,363397,768613,47981,466027,981569,41597,87149,55021,600883,111953,119083,471871,125641,922463,562577,269069,806999,981073,857707,831587,149351,996461,432457,10903,921091,119083,72671,843289,567323,317003,802129,612373]
*/