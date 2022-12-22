//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void bfs(int i, int j, vector<vector<int>>& vis, int n, int m, vector<vector<char>>& mat){
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int> front = q.front();
            int x = front.first;
            int y = front.second;
            vis[x][y] = 1;
            if(x-1>=0){
                if(vis[x-1][y] == 0 && mat[x-1][y] == 'O') q.push({x-1, y});
            }
            if(x+1 < n){
                if(vis[x+1][y] == 0 && mat[x+1][y] == 'O') q.push({x+1, y});
            }
            if(y-1 >=0){
                if(vis[x][y-1] == 0 && mat[x][y-1] == 'O') q.push({x, y-1});
            }
            if(y+1 < m){
                if(vis[x][y+1] == 0 && mat[x][y+1] == 'O') q.push({x, y+1});
            }
            q.pop();
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int> (m ,0));
        
        for(int j = 0; j < m; j++){
            if(mat[0][j] == 'O' && vis[0][j] == 0){
                bfs(0, j, vis, n, m, mat);
            }
            if(mat[n-1][j] == 'O' && vis[n-1][j] == 0){
                bfs(n-1, j, vis, n, m , mat);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 'O' && vis[i][0] == 0){
                bfs(i, 0, vis, n, m, mat);
            }
            if(mat[i][m-1] == 'O' && vis[i][m-1] == 0){
                bfs(i, m-1, vis, n, m, mat);
            }
        }
        
        for(int i = 0; i <n ;i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends