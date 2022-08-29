class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //left side
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            vector<int> v;
            int i1 = i, j = 0;
            while(i1 < n && j < m){
                v.push_back(mat[i1][j]);
                i1++;
                j++;
            }
            
            sort(v.begin(), v.end());
            
            i1 = i, j = 0;
            int k = 0;
            while(i1 < n && j < m){
                mat[i1][j] = v[k];
                k++;
                i1++;
                j++;
            }
        }
        
        for(int j = 1; j < m; j++){
            vector<int> v;
            int i = 0, j1= j;
            while(i < n && j1 < m){
                v.push_back(mat[i][j1]);
                i++;
                j1++;
            }
            
            sort(v.begin(), v.end());
            
            i = 0, j1 = j;
            int k = 0;
            while(i < n && j1 < m){
                mat[i][j1] = v[k];
                k++;
                i++;
                j1++;
            }
        }
        return mat;
    }
};