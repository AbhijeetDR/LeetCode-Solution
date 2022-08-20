class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> v1, v2;
        for(int i = 0; i < n; i++){
            if(i == 0) {
                v1.push_back(nums[i]);
                continue;
            }
            if(i == n-1) {
                v2.push_back(nums[i]);
                continue;
            }
            
            v1.push_back(nums[i]);
            v2.push_back(nums[i]);
        }
        
        vector<int> dp1(n, 0), dp2(n, 0);
        
        dp1[0] = v1[0];
        dp1[1] = max(v1[0], v1[1]);
        
        dp2[0] = v2[0];
        dp2[1] = max(v2[0], v2[1]);
        
        for(int i = 2; i < n-1; i++){
            dp1[i] = max(dp1[i-1], dp1[i-2] + v1[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + v2[i]);
        }
        
        return max(dp1[n-2], dp2[n-2]);
        
    }
};