class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int h = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(l >= nums.size()) return {-1, -1};
        if(nums[l] == target && nums[h-1] == target){
            return {l, h-1};
        }
        return {-1, -1};
        
    }
};