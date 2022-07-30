class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = (int)words1.size();
        int n2 = (int)words2.size();

        vector<string> ans;

        vector<int> v(26, 0);

        for(int i =0 ; i < n2; i++){
            vector<int> eachword(26, 0);
            for(int j = 0; j < words2[i].length(); j++){
                char c = words2[i][j];
                eachword[c - 'a']++;
            }

            for(int k = 0; k < 26; k++){
                v[k] = max(eachword[k], v[k]);
            }
        }

        for(int i =0 ; i < n1; i++){
            vector<int> w2(26,0);
            for(int j = 0; j < words1[i].length();j++){
                char c = words1[i][j];
                w2[c-'a']++;
            }


            bool ok = 1;
            for(int k = 0; k < 26; k++){
                if(w2[k] < v[k]){
                    ok = false;
                    break;
                }
            }
            if(ok) ans.push_back(words1[i]);
        }

        return ans;

    }
};