class Solution {
public:
    int maxArea(vector<int>& height){
        int sh = height.size();

        int i = 0, j = sh-1;
        int ans = 0;
        while(j > i){
            int curarea = min(height[i], height[j]) * (j-i);
            ans = max(ans, curarea);
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }

        }

        return ans;
    }
};