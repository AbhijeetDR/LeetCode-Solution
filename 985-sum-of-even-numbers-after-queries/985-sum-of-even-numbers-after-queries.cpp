class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& queries) {
        int sum = 0;
        int n = v.size();
        int m = queries.size();
        
        for(int i =0 ; i < n; i++){
            if(v[i]%2==0)sum += v[i];
        }
        vector<int> ans;
        
        for(int i =0 ;i < m; i++){
//             sum -= v[queries[i][1]];
//             v[queries[i][1]] += queries[i][0];
//             sum += v[queries[i][1]];
//             ans.push_back(sum);
            int ind = queries[i][1];
            int val = queries[i][0];
            if(v[ind] % 2 == 0){
                if((v[ind] + val)%2 == 0){
                    sum -= v[ind];
                    v[ind]+=val;
                    sum+=v[ind];
                }
                else{
                    sum-=v[ind];
                    v[ind]+=val;
                }
            }
            else{
                if((v[ind] + val)%2 == 0){
                    v[ind] += val;
                    sum += v[ind];
                }
                else{
                    v[ind]+=val;
                }
            }
            ans.push_back(sum);
          
            
        }
        return ans;
    }
};