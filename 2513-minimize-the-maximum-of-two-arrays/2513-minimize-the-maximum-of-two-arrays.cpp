class Solution {
public:
    #define int2 long long
    int2 lcm(int2 a,int2 b){
        return (a*b)/__gcd(a,b);
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int2 start = 1;
        int2 end = 1e10;
        int2 ans = 1;
        int2 t = lcm(divisor1,divisor2);
        // cout<<t<<endl;
        while(start<=end){
            int2 mid = start+(end-start)/2;
            int2 count = mid-(mid/t);
            int2 count1 = mid-(mid/divisor1);
            int2 count2 = mid-(mid/divisor2);
            if(count1 < uniqueCnt1 or count2 < uniqueCnt2 or count < (uniqueCnt1 + uniqueCnt2)){
                // ans = mid;
                // end = mid-1;
                start = mid+1;
            }
            else{
                // start = mid+1;
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};