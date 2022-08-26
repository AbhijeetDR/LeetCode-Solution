class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v(10, 0);
        while(n > 0){
            v[n%10]++;
            n=  n/10;
        }
        
        int p = 1;
        map<int, vector<int>> m; 
        while(p < 1e9+1){
            int tp = p;
            vector<int> tv(10, 0);
            while(tp > 0){
                tv[tp%10]++;
                tp = tp/10;
            }
            m[p] = tv;
            p*=2;
        }
        
        
        // for(auto i: m){
        //     cout << i.first << "\n";
        // }
        for(auto i: m){
            if(i.second == v){
                return 1;
            }
        }
        return 0;
    }
};