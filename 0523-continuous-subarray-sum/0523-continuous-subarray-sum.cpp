class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n);
        p[0] = nums[0];
        for(int i =1; i < n; i++){
            p[i] = p[i-1] + nums[i];
        }
        
        map<int, int> m;m[0] = 0;
        for(int i =0; i < n; i++){
            if(!m.count(p[i]%k)){
                m[p[i]%k] = i+1;
            }
            else if(m[p[i]%k] < i){
                return 1;
            }
            
        }
        return 0;
    }
    
};