class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(int i =0 ; i < n; i++) sum += v[i];
        int mn = v[0];
        int sc = 0;
        for(int i =1 ; i < n; i++){
            if(s[i] == s[i-1]){
                mn = max(mn, v[i]);
            }
            else{
                sc += mn;
                mn = v[i];
            }
        }
        sc += mn;
        
        return sum - sc;
    }
};