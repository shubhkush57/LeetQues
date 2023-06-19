class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // we have to find the 
        int q = queries.size();
        int ele = pow(2,n)-1;
        vector<int>ans(q);
        for(int i = 0;i<q;i++){
            int ai = queries[i][0];
            int bi = queries[i][1];
            // i will first start the ai and 
             // -1 is it as infiite distance.
            unordered_map<int,int>dis;
            dis[ai] = 0;
            while(ai>0){
                int temp = dis[ai];
                ai = ai/2; // parent ke pass ja raha hoon.
                dis[ai] = 1+temp;
            }
            int distance = 0;
            if(dis.count(bi)){
                ans[i] = dis[bi]+1;
            }
            else{
                while(bi>0){
                    if(dis.count(bi)){
                        ans[i] = dis[bi]+distance+1;
                        break;
                    }
                    bi = bi/2;
                    distance++;
                }
            }
            // dis.clear();
        }
        return ans;
    }
};