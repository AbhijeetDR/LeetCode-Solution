class Solution {
public:
    
    int f(int ind, vector<int>& nums, int n, vector<int>&dp){
        if(ind == n-1) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int minjump= 1e8;
        for(int i =1; i <= nums[ind]; i++){
            if(ind+i <= n-1) minjump = min(minjump, f(ind+i, nums, n, dp) + 1);
            else return dp[ind] = minjump;
        }
        
        return dp[ind] = minjump;
        
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = f(0, nums, n, dp);
        return ans;
        
        
        
        
    }
};