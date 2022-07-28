class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sf(26);
        vector<int> tf(26);
        for(int i =0;i<s.length(); i++){
            sf[s[i]-'a']++;
        }
        for(int i = 0;i<t.length();i++){
            tf[t[i]-'a']++;
        }
        
        for(int i =0 ; i < 26;i++){
            if(sf[i] != tf[i]) return false;
        }
        return true;
        
    }
};