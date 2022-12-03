class Solution {
public:
    
    static bool cmp(const pair<char, int> &a, const pair<char, int>&b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        // vector<int> v(26, 0);
        map<char, int> m;
        int n = (int)s.length();
        for(int i=0; i < n; i++){
            m[s[i]]++;
        }
        
        vector<pair<int, char>> v;
        for(auto i: m){
            v.push_back({i.second, i.first});
        }
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        // for(auto i: v){
        //     cout << i.first << " " << i.second << "\n";
        // }
        string res = "";
        for(auto i: v){
            for(int j = 0; j < i.first; j++){
                // cout << i.second;
                res += i.second;
            }
        }
        // cout << m['a'] << " " << m['t'];
        return res;
    }
};