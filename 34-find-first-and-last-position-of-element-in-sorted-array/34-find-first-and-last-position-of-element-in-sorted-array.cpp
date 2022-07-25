class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int s = nums.size();
        if(l==s || nums[l] != target)return {-1, -1};
        int h = upper_bound(nums.begin(),nums.end(), target) - nums.begin();
        return {l, h-1};
    }
};