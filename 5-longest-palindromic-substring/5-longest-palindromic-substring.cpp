class Solution {
public:
    string longestPalindrome(string s){
        /*
        babad
        abba
        babab

        babbab
        1 0 0 0 0 0
        0 1 0 0 0 0
        0 0 1 1 0 0
        0 0 0 1 0 0
        0 0 0 0 1 0
        0 0 0 0 0 1
        */

        int ss = s.length();
        int arr[ss][ss];

        for(int i = 0; i < ss; i++){
            for(int j = 0; j < ss; j++){
                if(i == j){
                    arr[i][j] = 1;
                }
                else if(abs(i - j) == 1 && s[i] == s[j]){
                    arr[i][j] = 1;

                }
                else{
                    arr[i][j] = 0;

                }
                arr[j][i] = arr[i][j];
            }
        }


        for(int j = 0; j < ss; j++){
            for(int i = 0; i < j; i++){
                if(arr[i+1][j-1] == 1 && s[i] == s[j]){
                    arr[i][j] = 1;
                    arr[j][i] = 1;
                }
            }
        }
        
        int st = 0, en = 0;
        for(int j = 0; j < ss; j++){
            for(int i = 0; i <= j; i++){
                if(arr[i][j] == 1 && en - st < j - i){
                    en = j, st = i;
                }
            }
        }

        string res = s.substr(st, en - st + 1);
        return res;
    }
};