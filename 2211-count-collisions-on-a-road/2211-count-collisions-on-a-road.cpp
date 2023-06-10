class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        int left = 0, right = n-1;
        while(left<n && directions[left] == 'L'){
            left++;
        }
        while(right>=0 && directions[right] == 'R' ){
            right--;
        }
        // every car inbetween them is going to collinde expec the staying one..
        for(int i = left;i<=right && i<n;i++){
            if(directions[i] != 'S'){
                ans++;
            }
        }
        return ans;
    }
};