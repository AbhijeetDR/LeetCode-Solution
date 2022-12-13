//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int ok(int mid, int arr[], int n){
        int c = 0;
        int csum =0;
        for(int i = 0; i < n; i++){
            csum += arr[i];
            if(csum >= mid){
                c++;
                if(csum == mid){
                    csum = 0;
                }
                else{
                    csum = arr[i];
                }
            }
        }
        if(csum){
            c++;
        }
        return c;
        
    }
  
  
    int splitArray(int arr[] ,int N, int K) {
        // code here
        
        //1 2 3 4
        //123 4 = 6 
        //1 234 = 7
        int st = INT_MIN;// st = *max_element(arr, arr+n)
        int en = 0;
        for(int i = 0 ; i < N; i++){
            st = max(st, arr[i]);
            en += arr[i];
        }
        
        while(en > st){
            int mid = st + (en - st)/2;
            // cout << st << " " << mid << " " << en << endl;
            if(ok(mid, arr, N) <= K){
                en = mid;
            }
            else if(ok(mid, arr,N) > K){
                st = mid+1;
            }
            // cout << st << " " << mid << " " << en << endl;
            
        }
        return en;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends