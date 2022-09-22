class Solution {
public:
    string reverseWords(string s) {
        string cur = "";
        string res = "";
        for(int i = 0;s[i] !='\0'; i++){
            if(s[i] == ' '){
                reverse(cur.begin(), cur.end());
                res += cur;
                res += ' ';
                cur = "";
            }
            else{
                cur += s[i];
            }
        }
        reverse(cur.begin(), cur.end());
        res += cur;
        return res;
    }
};