//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int sum = 0;
	    int best = 0;
	    int j = 0;
	    int i = 0;
	    
	    int l = 0, r = -1;
	    for(;j < n; j++){
	        if(a[j]>=0){
	            sum += a[j];
	        }
	        else{
	            if(best < sum){
	                best = sum;
	                l = i;
	                r = j-1;
	            }
	            sum = 0;
	            i = j+1;
	        }
	    }
	    if(best < sum){
	        best = sum;
	        l = i;
	        r = j-1;
	    }
	    
	    vector<int>ans;
	    
	    for(int k = l; k <= r; k++){
	        ans.push_back(a[k]);
	    }
	    if(ans.size() == 0){
	        ans.push_back(-1);
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends