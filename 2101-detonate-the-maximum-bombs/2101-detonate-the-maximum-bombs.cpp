class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // detonate the bomb 
        map<int,vector<int>>mp;
        int n = bombs.size();
        for(int i = 0;i<n;i++){
            float xi = bombs[i][0];
            float yi = bombs[i][1];
            float ri = bombs[i][2];
            for(int j = 0;j<n;j++){
                if(i != j){
                    float xj = bombs[j][0];
                    float yj = bombs[j][1];
                    float rj = bombs[j][2];
                    float com = sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
                    if(com <= ri){
                        mp[i].push_back(j);
                        // mp[j].push_back(i);
                    }
                }
                
            }
        }
        // now considering the value of the given tersm
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            // if we go to detonate the one bomb let's see the no of bombs which will be denotede   
            queue<int>q;
            int tempans = 0;
            q.push(i);
            set<int>st;
            st.insert(i);
            while(!q.empty()){
                int f = q.front();
                q.pop();
                tempans++;
                for(auto it: mp[f]){
                    if(!st.count(it)){
                        q.push(it);
                        st.insert(it);
                    }
                }
                
                
            }
            ans = max(tempans,ans);
        }
        return ans;
        
    }
};