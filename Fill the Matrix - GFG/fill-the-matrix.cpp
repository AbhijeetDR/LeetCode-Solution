//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        x--;
        y--;
        queue<pair< int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        q.push({x, y});
        vis[x][y] = 1;
        int maxdis = 1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            int dis = vis[i][j];
            q.pop();
            if(i+1 < n && vis[i+1][j] == 0){
                q.push({i+1, j});
                vis[i+1][j] = 1 + dis;
                maxdis = max(dis+1, maxdis);
            }
            if(i-1>=0 && vis[i-1][j] == 0){
                q.push({i-1, j});
                vis[i-1][j] =1 + dis;
                maxdis = max(dis+1, maxdis);
            }
            if(j+1 < m && vis[i][j+1]==0){
                q.push({i, j+1});
                vis[i][j+1] = 1+dis;
                maxdis = max(dis+1, maxdis);
            }
            if(j-1 >=0 && vis[i][j-1] == 0){
                q.push({i,j-1});
                maxdis = max(dis+1, maxdis);
                vis[i][j-1] = 1+dis;
            }
        }
        
        return maxdis - 1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends