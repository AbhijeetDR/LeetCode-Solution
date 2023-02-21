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
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        q.push({{x, y}, 0});
        vis[x][y] = 1;
        int maxdis = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis =q.front().second;
            q.pop();
            if(i+1 < n && vis[i+1][j] == 0){
                q.push({{i+1, j}, dis+1});
                vis[i+1][j] = 1;
                maxdis = max(dis+1, maxdis);
            }
            if(i-1>=0 && vis[i-1][j] == 0){
                q.push({{i-1, j}, dis+1});
                vis[i-1][j] =1;
                maxdis = max(dis+1, maxdis);
            }
            if(j+1 < m && vis[i][j+1]==0){
                q.push({{i, j+1}, dis+1});
                vis[i][j+1] = 1;
                maxdis = max(dis+1, maxdis);
            }
            if(j-1 >=0 && vis[i][j-1] == 0){
                q.push({{i,j-1}, dis+1});
                maxdis = max(dis+1, maxdis);
                vis[i][j-1] = 1;
            }
        }
        
        return maxdis;
        
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