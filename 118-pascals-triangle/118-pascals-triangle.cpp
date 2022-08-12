class Solution {
public:

    vector<vector<int>> f(vector<vector<int>> &t, int n){
        vector<int> tmp;
        if(n == 1){
            tmp.push_back(1);
            t.push_back(tmp);
            return t;
        }

        vector<vector<int>> so = f(t, n-1);

        tmp.push_back(1);
        for(int i = 0; i < n-2; i++){
            int add = so[n-2][i] + so[n-2][i+1];
            tmp.push_back(add);
        }

        tmp.push_back(1);
        t.push_back(tmp);


        return t;

    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tmp;
        int n = numRows;
        vector<vector<int>> ans = f(tmp, n);
        return ans;
    }
    
};