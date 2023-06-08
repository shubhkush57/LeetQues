class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        vector<int>vis(n,-1);
        vector<bool>vis2(1003,false);
        queue<int>q;
        q.push(start);
        vis2[start] = true;
        int l =0;
        while(!q.empty()){
            int t = q.size();
            while(t--){
                int f = q.front();q.pop();
                if(f == goal){
                    return l;
                }
                for(int i = 0;i<n;i++){
                    int nx = f+nums[i];
                    if(nx == goal){
                        return l+1;
                    }
                    if(nx<=1000 && nx>=0  && vis2[nx] == false){
                        q.push(nx);
                        vis[i] = 0;
                        
                        vis2[nx] = true;
                    }
                    nx = f-nums[i];
                    if(nx == goal){
                        return l+1;
                    }
                    if(nx<=1000 && nx>=0  && vis2[nx] == false){
                        q.push(nx);
                        vis[i] = 1;
                        vis2[nx] = true;
                    }
                    nx = f ^ nums[i];
                    if(nx == goal){
                        return l+1;
                    }
                    if(nx<=1000 && nx>=0  && vis2[nx] == false){
                        q.push(nx);
                        vis[i] = 2;
                        vis2[nx] = true;
                    }
                }
            }
            l++;
        }
        return -1;
    }
};