//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    long long f(long long n){
        long long lcm = n*(n-1);
        
        int cnt=0;
        for(long long i = n-2; i>=1; i--){
            if(__gcd(i, lcm) == 1){
                lcm *=i;
                cnt++;
            }
            if(cnt==2){
                break;
            }
        }
        
        return lcm;
    }
  
  
    long long maxGcd(long long n) {
        // cout << f(n) << " " << f(n-1) << "\n";
        return max(f(n), f(n-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends