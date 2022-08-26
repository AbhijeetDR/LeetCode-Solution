class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        
        //1 3 -2 6 -1 2 -1
        //dp[maxi][mini]
        int cur_max = 0;
        int cur_min = 0;
        int pre_max =v[0];
        int pre_min =v[0];
        // vector<vector<int>> dp(n, vector<int> (2, 1));
        // dp[0][0] = dp[0][1] = v[0];
        int ans = v[0];
        for(int i= 1; i <n;i++){
            // dp[i][0] = max({v[i] * dp[i-1][0], v[i] * dp[i-1][1], v[i]});
            cur_max = max({v[i] * pre_max, v[i] * pre_min, v[i]});
            // dp[i][1] = min({v[i]*dp[i-1][0], v[i] * dp[i-1][1], v[i]});
            cur_min = min({v[i]*pre_max, v[i]*pre_min, v[i]});
            ans = max(ans, cur_max);
            pre_max = cur_max;
            pre_min = cur_min;
        }
        
        return ans;
    }
}; 