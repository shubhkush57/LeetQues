class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        // monotonic stack...
        stack<char>stk;
        int ans =0;
        for(int i = 0;i<n;i++){
            char t= directions[i];
            if(t == 'R'){
                stk.push('R');
            }
            else if(t == 'L'){
                if(!stk.empty() && stk.top() == 'S'){
                    ans++;
                }
                else if(stk.empty() || stk.top() == 'L'){
                    stk.push('L');
                }
                else{
                    int count = 0;
                     while(!stk.empty() && stk.top() == 'R'){
                        count++;
                         stk.pop();
                    }
                    stk.push('S');
                    ans += count+1;
                }
            }
            else{
                while(!stk.empty() && stk.top() == 'R'){
                    ans++;
                    stk.pop();
                }
                stk.push('S');
            }
        }
        return ans;
    }
};