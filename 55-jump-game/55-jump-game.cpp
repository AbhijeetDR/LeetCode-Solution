class Solution {
public:
    
    bool f(int ind, vector<int>&jump, int n, vector<int>& dp){
        if(ind == n-1) return 1;
        if(dp[ind] != -1) return dp[ind];
        bool ok = false;
        for(int i = 1; i <= jump[ind]; i++){
            ok = ok || f(ind+i, jump, n, dp);
        }
        return dp[ind] = ok;
    }
    
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        // vector<int> dp(n, -1);
        // bool ans = f(0, nums, n, dp);
        // return ans;
        
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        
        for(int ind = n-2; ind >= 0; ind--){
            bool ok = false;
            for(int j = 1; j <= nums[ind]; j++){
                ok = ok || dp[ind+j];
                if(ok){
                    dp[ind] = ok;
                    break;
                }
            }
            if(!ok) dp[ind] = ok;
        }
        return dp[0];
    }
};