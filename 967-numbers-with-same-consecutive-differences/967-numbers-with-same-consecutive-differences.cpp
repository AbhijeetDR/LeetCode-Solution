class Solution {
private:
    void f(int last, int diff, int cur, int tofill, set<int>& s){
        if(tofill == 0){
            s.insert(cur);
            return;
        }
        cur*=10;
        if(last + diff <= 9) f(last+diff, diff, cur+last+diff, tofill-1, s);
        if(last - diff >= 0) f(last-diff, diff, cur+last-diff, tofill-1, s);
    }
    
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        set<int> s;
        for(int i = 1; i <= 9; i++){
            f(i, k, i, n-1, s);
        }
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};