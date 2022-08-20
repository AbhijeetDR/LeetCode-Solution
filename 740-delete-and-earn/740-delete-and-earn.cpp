class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(1e4+1, 0);
        vector<int> dp(1e4+1, 0);
        for(int i =0; i < n; i++){
            freq[nums[i]]++;
        }
        
        //2 2 3 3 3 4 5
        //0 1 2 3 4 5 6
        //0 0 4 9 8 16
        
        //8 1 4 9 1 3 5 9 4 10
        
        //1 1 3 4 4 5 8 9 9 10
        //0 1 2 3 4 5 6 7 8 9 10
        //0 2 2 5 10
        
        // int maxi = INT_MIN;
        
        
        // dp[0] = 0, dp[1] = freq[1];
        int p2 = 0, p1 = freq[1], cur = max(p1, p2);
        for(int i = 2 ; i < 1e4+1; i++){
            // dp[i] = max(i*freq[i] + dp[i-2], dp[i-1]);
            cur = max(i*freq[i] + p2, p1);
            p2 = p1;
            p1 = cur;
            // maxi = max(maxi, dp[i]);
        }
        
        return cur;
    }
};