class Solution {
public:
    int climbStairs(int n) {
        if(n <=2) return n;
        // vector<int> dp(n+1, 0);
        
        // dp[1] = 1;
        // dp[2] = 2;
        int p1 = 1;
        int p2 = 2;
        int cur = 0;
        for(int i = 3; i < n+1; i++){
            cur = p1 + p2;
            p1 = p2;
            p2 = cur;
        }
        return cur;
    }
};