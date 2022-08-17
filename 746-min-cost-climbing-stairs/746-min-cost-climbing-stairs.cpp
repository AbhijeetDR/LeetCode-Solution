class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        // n++;
        if(n == 2) return min(cost[0], cost[1]);
        
        // vector<int> dp(n+1, 0);
        // dp[0] = dp[1] = 0;
        
        int p1 = 0, p2 = 0, cur = 0;
        for(int i = 2; i <= n; i++){
            cur = min(p1 + cost[i-1], p2 + cost[i-2]);
            p2 = p1;
            p1 = cur;
        }
        
        
        return cur;
    }
};