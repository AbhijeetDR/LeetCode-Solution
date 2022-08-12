class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;//for s
        int j = 0;//for t
        
        int ss = (int)s.size();
        int st = (int)t.size();
        
        while(i < ss && j < st){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        if(i == ss) return true;
        return false;
    }
};