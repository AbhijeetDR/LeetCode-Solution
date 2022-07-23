class Solution {
public:
    int reverse(int x){

        if(x == 0) return 0;
        bool neg  = (x < 0);
        x = abs(x);
        

        int limit = INT_MAX;
        int pow = 1;
        int res = 0;
        while(x > 0){
            if(res > limit/10){
                return 0;
            }
            res*=10;
            res += x%10;
            x = x/10;
        }
        if(neg){
            return -res;
        }
        return res;

    }


};