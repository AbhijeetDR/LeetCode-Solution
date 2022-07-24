class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int row = matrix.size();
        int col = matrix[0].size();

        if(matrix[row-1][col-1] < target){
            return false;
        }

        for(int i = 0; i < row; i++){
            int left = 0, right = col-1;
            if(matrix[i][col-1] < target) continue;
            while(left <= right){
                int mid = left + (right - left)/2;
                // cout << i << " " << mid << "\n";
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] < target){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};