class Solution {
public:
    #define int2 long long
    int maxValue(int n, int i, int maxSum) {
        int2 start = 1;
        int2 end = 1e9;
        int2 ans = 1;
        while(start<=end){
            int2 a = start+(end-start)/2;
            int2 sum = 0;
            if(n-i >a){
                sum += (n-i-a) + ((a*(a+1))/2);
            }
            else{
                sum += ((n-i)*(2*a - (n-i-1)))/2;
            }
            if(i+1 > a){
                sum += (i+1-a)+((a*(a+1))/2);
            }
            else{
                sum += ((i+1)*(2*a-i))/2;
            }
            sum -= a;
            if(sum <= maxSum){
                ans = a;
                start= a+1;
            }
            else{
                end = a-1;
            }
        }
        return ans;
    }
};