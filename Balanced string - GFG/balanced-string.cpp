//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int n) {
        // code here
        string s = "abcdefghijklmnopqrstuvwxyz";
        string ans= "";
        
        for(int i=0; i < n/26; i++){
            ans += s;
        }
        int rem = n%26;
        
        if(n%2==0){
            for(int i =0; i < rem/2; i++){
                ans += s[i];
                // ans += s[25-i];
            }
            string tmp = "";
            
            for(int i=26-rem/2; i < 26; i++){
                // tmp +=s[25-i];
                ans += s[i];
            }
            // reverse(tmp.begin(), tmp.end());
            
        }
        
        else{
            
            // string ans = "";
            int sum = 0;
            int n1 = n;
            while(n1>0){
                sum += n1%10;
                n1/=10;
            }
            if(sum % 2 == 0){
                for(int i =0; i < (rem+1)/2; i++){
                    ans += s[i];
                }
                string tmp= "";
                for(int i=26-((rem-1)/2); i < 26; i++){
                    // tmp += s[25-i];
                    ans += s[i];
                }
                // reverse(tmp.begin(), tmp.end());
                // ans += tmp;
            }
            else{
                for(int i=0; i < (rem-1)/2; i++){
                    ans += s[i];
                }
                string tmp = "";
                for(int i=26-(rem+1)/2; i < 26; i++){
                    // tmp +=s[25-i];
                    ans += s[i];
                    
                }
                // reverse(tmp.begin(), tmp.end());
                // ans += tmp;
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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends