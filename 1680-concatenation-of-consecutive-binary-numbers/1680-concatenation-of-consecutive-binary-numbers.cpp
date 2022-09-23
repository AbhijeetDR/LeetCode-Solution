class Solution {
    
public:
    long long int mod;
    Solution(){
        mod =(int)(1e9 + 7);
    }
    
    long long int binpow(long long int a, long long int b){
        if(b == 0) return 1;
        if(b == 1) return a;
        int res = binpow(a, b/2);
        if(b%2){
            return (res*(res*a)%mod)%mod;
        }
        return (res*res)%mod;
    }
    
    int concatenatedBinary(int n) {
        // vector<long long int> dp(n+1);
        long long int prev = 1, cur = 0;
        for(int i= 2; i <= n; i++){
            cur = ((prev*binpow(2, log2(i) + 1))%mod + i)%mod;
            prev = cur;
        }
        return prev;
    }
};