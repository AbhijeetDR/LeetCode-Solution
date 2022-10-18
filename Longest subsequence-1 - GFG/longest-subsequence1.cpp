//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
    	//code here
        vector<int> dp(n, 1);
        int mx = 1;
        
        for(int i = 1; i < n;i++){
            for(int j = i-1; j >= 0; j--){
                if(abs(a[i] - a[j]) == 1){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    mx = max(dp[i], mx);
                }
            }
        }
        
        return mx;        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends