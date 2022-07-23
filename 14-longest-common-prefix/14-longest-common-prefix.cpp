class Solution {
public:
    static bool cmp(const string &a, const string& b){
        return a.size() < b.size();
    }

    string longestCommonPrefix(vector<string>& strs){
        int ss= strs.size();
        string ans = "";

        // int minlen = INT_MAX;
        sort(strs.begin(), strs.end(), cmp);

        int minlen = strs[0].length();
        for(int i = 0;i < minlen; i++){
            char c = strs[0][i];
            for(int j = 1; j < ss; j++){
                if(c != strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(c);
        }
        return ans;

    }
};