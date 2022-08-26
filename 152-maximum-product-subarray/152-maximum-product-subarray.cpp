class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        
        //1 3 -2 6 -1 2 -1
        //dp[maxi][mini]
        
        vector<vector<int>> dp(n, vector<int> (2, 1));
        dp[0][0] = dp[0][1] = v[0];
        int ans = v[0];
        for(int i= 1; i <n;i++){
            dp[i][0] = max({v[i] * dp[i-1][0], v[i] * dp[i-1][1], v[i]});
            dp[i][1] = min({v[i]*dp[i-1][0], v[i] * dp[i-1][1], v[i]});
            ans = max(ans, dp[i][0]);
        }
        
        return ans;
    }
}; 