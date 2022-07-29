class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int sw = (int)words.size();
        int n = (int)pattern.length();
        int c = 0;

        vector<string> ans;

        for(int i = 0; i < sw; i++){
            string s = words[i];

            vector<bool>vis(26,false);

            map<char, char> m;

            bool ok = 1;
            for(int j = 0; j < n; j++){
                char pc = pattern[j];
                char sc = s[j];


                if(m[pc] == 0){
                    if(vis[sc - 'a'] == 1){
                        ok = false;
                    }
                    else{
                        m[pc] = sc;
                        vis[sc - 'a'] = 1;
                    }

                }

                else if(m[pc] != sc){
                    ok = 0;
                }
            }

            if(ok) ans.push_back(s);


        }
        return ans;


    }
};