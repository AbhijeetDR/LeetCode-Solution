//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:

//   void f(int i, int j , string s, int n, vector<int>& o, vector<int>& z, int& st, int& en, int& mx){
//         if(i == j){
//             if(s[i] == '1'){
//                 return;
//             }
            
//             if(mx < o[n-1] + 1){
//                 mx = o[n-1]+1;
//                 st = i, en = i;
//                 return;
//             }
            
//         }
        
//         int ones = 0;
//         int zeros = 0;
        
//         if(i==0){
//             ones = o[j];
//             zeros = z[j];
//         }
//         else{
//             ones = o[j] - o[i-1];
//             zeros = z[j] - z[i-1];
//         }
        
//         int cur = o[n-1] - ones + zeros;
        
//         if(cur > mx){
//             mx = cur;
//             st = i;
//             en = j;
//         }        
        
//         f(i, j-1, s, n, o, z, st, en, mx);
//         f(i+1, j, s, n, o, z, st, en, mx);
        

//   }
    
    vector<int> findRange(string s, int n) {
        // code here
        int ok = 0;
        for(int i=0; i < n; i++){
            if(s[i] == '0'){
                ok = 1;
            }
        }
        if(!ok){
            return {-1};
        }
        
        int l = -1, r = -1, maxcnt = -1, ltmp = 0, cnt = 0;
        for(int i=0; i < n; i++){
            if(s[i] == '0'){
                cnt++;
            }
            else{
                cnt--;
            }
            
            if(cnt > maxcnt){
                maxcnt = cnt;
                l = ltmp;
                r = i;
            }
            else if(cnt < 0){
                cnt= 0 ;
                ltmp = i + 1;
            }
        }
        
        return {l+1, r+1};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends