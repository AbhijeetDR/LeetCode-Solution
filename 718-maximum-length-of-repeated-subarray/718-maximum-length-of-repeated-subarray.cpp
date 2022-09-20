class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans =0 ;
        vector<int>dp(m+1, 0);
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 1; j--){
                if(nums1[i-1] == nums2[j-1]){
                    dp[j] = dp[j-1] + 1;
                    ans = max(dp[j], ans);
                }
                else{
                    dp[j] = 0;
                }
            }
        }
        return ans;
    }
};