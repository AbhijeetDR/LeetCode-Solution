class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i] = max money till i houses
        int n = nums.size();
        if(n == 1) return nums[0];
        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        
        int p2 = nums[0], p1 =max(p2, nums[1]);
        int cur = max(p1, p2);
        for(int i = 2; i < n; i++){
            // dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            cur = max(p1, p2 + nums[i]);
            p2 = p1;
            p1 = cur;
        }
        return cur;
        
    }
};