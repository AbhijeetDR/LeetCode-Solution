class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k){
        int i = 0;
        int t = 0;
        int n = (int)tickets.size();
        while(tickets[k] > 0){
            if(tickets[i] == 0){ 
                //do something
            }
            else{
                tickets[i]--;
                t++;
            }
            i++;
            i = i%n;
        }

        return t;

    }
};