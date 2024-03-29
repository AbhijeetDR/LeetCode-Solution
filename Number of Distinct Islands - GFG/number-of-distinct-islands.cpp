//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
/*
follow same traversal



*/
class Solution {
  private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int pari,
        int parj, vector<pair<int, int>> &v, int n, int m){
        vis[i][j] = 1;
        v.push_back({i-pari, j-parj});

        //down
        if(i+1 < n && grid[i+1][j] == 1 && vis[i+1][j] == 0){
            dfs(i+1, j, grid, vis, pari, parj, v, n, m);
        }
        //left
        if(j-1 >= 0 && grid[i][j-1] == 1 && vis[i][j-1] == 0){
            dfs(i, j-1, grid, vis, pari, parj, v, n, m);
        }
        //up
        if(i-1 >= 0 && grid[i-1][j] == 1 && vis[i-1][j] == 0){
            dfs(i-1, j, grid, vis, pari, parj, v, n, m);
        }
        //right
        if(j+1<m && grid[i][j+1] == 1 && vis[i][j+1] == 0){
            dfs(i, j+1, grid, vis, pari, parj, v, n, m);
        }         

    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<pair<int, int>> v;
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    dfs(i, j, grid, vis, i, j, v, n, m);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends