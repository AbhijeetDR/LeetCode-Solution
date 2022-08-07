class Solution {
public:
    
    bool f(int m, vector<int>& nums,int threshold){
        int s = 0;
        for(int i =0; i < nums.size(); i++){
            s += (nums[i] + m-1)/m;
        }
        if(s <= threshold) return true;
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = r;
        
        while(l <= r){
            int m = l + (r - l)/2;
            if(f(m, nums, threshold)){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};