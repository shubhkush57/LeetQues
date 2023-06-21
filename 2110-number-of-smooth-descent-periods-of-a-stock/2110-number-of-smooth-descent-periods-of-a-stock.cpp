class Solution {
public:
    #define int2 long long
    long long getDescentPeriods(vector<int>& prices) {
        /*
        3
        3 2
        3 2 1
        2 
        2 1
        1
        3 2 1 0
        2 1 0
        1 0
        0
        
        
        1 ->1
        2 ->3
        3 ->6
        4->10
        5->15
        6->21
        7->28
        */
        int n = prices.size();
        int2 ans = 0;
        int2 count = 1;
        ans += count;
        for(int i = 1;i<n;i++){
            if(prices[i] == prices[i-1]-1){
                count++;
                ans += count;
            }
            else{
                count = 1;
                ans += count;
            }
        }
        return ans;
    }
};