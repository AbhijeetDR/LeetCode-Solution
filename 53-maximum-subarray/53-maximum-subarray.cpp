class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        bool pos = 0;
        for(int i =0 ; i < n; i++){
            if(nums[i] > 0) pos = 1;
            
        }
        
        if(pos == 0) return *max_element(nums.begin(), nums.end());
        
        int best = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum > 0){
                best = max(best, sum);
            }
            if(sum < 0){
                sum = 0;
            }
        }
        
        return best;
        
    }
};