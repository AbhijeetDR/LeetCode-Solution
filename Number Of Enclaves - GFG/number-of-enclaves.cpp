//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// class Solution {
//   public:
//     int numberOfEnclaves(vector<vector<int>> &grid) {
//         // Code here
//     }
// };

class Solution {
private:
    void bfs(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& vis,int n, int m ){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int len = 1;
        while(len){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            len--;

            if(x-1>=0 && grid[x-1][y] == 1 && vis[x-1][y] == 0){
                q.push({x-1, y});
                vis[x-1][y] = 1;
                len++;
            }
            if(x+1<n && grid[x+1][y] == 1 && vis[x+1][y] == 0){
                q.push({x+1, y});
                vis[x+1][y] = 1;
                len++;
            }
            if(y-1>=0 && grid[x][y-1] == 1 && vis[x][y-1] == 0){
                q.push({x, y-1});
                vis[x][y-1] = 1;
                len++;
            }
            if(y+1<m && grid[x][y+1] == 1 && vis[x][y+1] == 0){
                q.push({x, y+1});
                vis[x][y+1] = 1;
                len++;
            }
        }
    }

public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            if(vis[i][0] == 0 && grid[i][0] == 1){
                bfs(i, 0, grid, vis, n, m);
            }
            if(vis[i][m-1] == 0 && grid[i][m-1] == 1){
                bfs(i, m-1, grid, vis, n, m);
            }
        }

        for(int j = 0; j< m; j++){
            if(vis[0][j] == 0 && grid[0][j] == 1){
                bfs(0,j,grid, vis, n, m);
            }
            if(vis[n-1][j] == 0 && grid[n-1][j] == 1){
                bfs(n-1, j, grid, vis, n, m);
            }
        }

        int ans =0 ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends