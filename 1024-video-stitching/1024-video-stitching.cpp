class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int n = clips.size();
        // greedy way.....
        // we r going to remove the reduandatn.
        // for(auto it: clips){
        //     cout<<it[0]<<' '<<it[1]<<endl;
        // }
        if(clips[0][0] != 0){
            return -1;
        }
        int ans =0,e = 0,i = 0;
        while(i<n){
            int temp = e;
                 while(i<n && e == 0 && clips[i][1]>e && clips[i][0] <= e){
                    temp = clips[i][1];
                    i++;
                }
                while(i<n && e != 0 && ((clips[i][1]>e && clips[i][0] <= e) || clips[i][1] <= e)){
                    temp = max(temp,clips[i][1]);
                    i++;
                }
            if(temp > e){
                cout<<temp<<endl;
                e = temp;
                ans++;
                i--;
            }
            if(e>= time){
                return ans;
            }
            i++;
        }
        return -1;
        
    }
};