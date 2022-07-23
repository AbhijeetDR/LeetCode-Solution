class Solution {
public:
    bool isPalindrome(int x){
        long int num = 0;
        int y = x;
        while(x > 0){
            num*=10;
            num += x%10;
            x/=10;
        }
        return y == num;

    }
};