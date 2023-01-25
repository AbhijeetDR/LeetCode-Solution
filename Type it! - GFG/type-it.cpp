//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

//abababab
class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();
        int ans = n;
        for(int i = 1; i < n; i++){
            int j = 0;
            int i1 = i;
            while( j < i && i1 < n && s[j] == s[i1]){
                i1++;
                j++;
            }
            if(i == j) ans = min(ans, 1 + n - j);
            
        }
        
        return ans;
        

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends