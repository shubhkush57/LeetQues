class Solution {
public:
    bool isSqr(int n){
        int s = sqrt(n);
        return s* s == n;
    }
    int numSquares(int n) {
        if(isSqr(n)){
            return 1;
        }
        
        // 4 square problem
        // 4^k [8m+7] 
        // then the answer will be 4
        while(n%4 == 0){
            n = n>>2;
        }
        if(n%8 == 7){
            return 4;
        }
        int s = sqrt(n);
        for(int i = 1;i<=s;i++){
            if(isSqr(n-i*i)){
                return 2;
            }
        }
        return 3;
    }
};