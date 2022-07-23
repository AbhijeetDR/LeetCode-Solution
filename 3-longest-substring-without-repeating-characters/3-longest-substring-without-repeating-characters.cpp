class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int ss = s.length();
        map<char, int> m;
        int c = 0, ans= 0;
        while(j < ss){
            m[s[j]]++;
            c++;
            
            while(m[s[j]] > 1){
                m[s[i]]--;
                i++;
                c--;
            }
            
            ans = max(j-i+1, ans);
            j++;
        }
        return ans;
    }
};