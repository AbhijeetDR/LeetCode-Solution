//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool ok(long long mid,  vector<int> &stalls, int n, int k){
        int i = 0;
        k--;
        while(k>0){
            int ind = lower_bound(stalls.begin(), stalls.end(),stalls[i] + mid) - stalls.begin();
            if(ind == n){
                return 0;
            }
            i = ind;
            k--;
        }
        return 1;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        
        long long st = 0, en = stalls[n-1] - stalls[0];
        long long ans;
        while(st <= en){
        
            long long mid = st + (en - st)/2;
            
            if(ok(mid, stalls, n, k)){
                ans = mid;
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends