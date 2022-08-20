class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int p2 = nums[0], p1 =max(p2, nums[1]);
        int cur = max(p1, p2);
        for(int i = 2; i < n; i++){
            cur = max(p1, p2 + nums[i]);
            p2 = p1;
            p1 = cur;
        }
        return cur;
        
    }
};