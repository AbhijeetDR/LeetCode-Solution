class Solution {
public:
    
    bool find(char c , string s){
        for(int i=0; i< 10; i++){
            if(s[i] == c){
                return 1;
            }
        }
        return 0;
    }
    
    bool halvesAreAlike(string s) {
        int n = (int)s.size();
        string vowels = "aeiouAEIOU";
        
        int a = 0, b = 0;
        
        for(int i =0; i < n; i++){
            if(find(s[i], vowels)){
                 if(i < n/2){
                    a++;
                }
                else{
                    b++;
                }               
            }
            
        }
        return a == b;
        
    }
};