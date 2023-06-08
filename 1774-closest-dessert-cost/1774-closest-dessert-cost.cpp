class Solution {
public:
    void solve(vector<int>&toppingCosts,int target,int cost,int &ans,int &reans,int i){
        int m = toppingCosts.size();
        if(i>=m){
            return;
        }
         if(abs(cost-target)<ans){
                ans = abs(cost-target);
                // reans = min(reans,cost);
                reans = cost;
        }
        else if(abs(cost-target) == ans){
                reans = min(reans,cost);
        }
        solve(toppingCosts,target,cost,ans,reans,i+1);
       
        cost += toppingCosts[i];
         if(abs(cost-target)<ans){
                ans = abs(cost-target);
                // reans = min(reans,cost);
                reans = cost;
        }
        else if(abs(cost-target) == ans){
                reans = min(reans,cost);
        }
        solve(toppingCosts,target,cost,ans,reans,i+1);
        
        cost += toppingCosts[i];
         if(abs(cost-target)<ans){
                ans = abs(cost-target);
                // reans = min(reans,cost);
                reans = cost;
        }
        else if(abs(cost-target) == ans){
                reans = min(reans,cost);
        }
        solve(toppingCosts,target,cost,ans,reans,i+1);
        cost -= 2*toppingCosts[i];
        return;
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        int m = toppingCosts.size();
        
        int ans = INT_MAX;
        int reans = INT_MAX;
        for(int i = 0;i<n;i++){
            
            int cost = baseCosts[i];
            // no topping...
            if(abs(cost-target)<ans){
                ans = abs(cost-target);
                // reans = min(reans,cost);
                reans = cost;
            }
            else if(abs(cost-target) == ans){
                reans = min(reans,cost);
            }
            // one type of topping..
            // unordered_map<int,int>mp;
            if(cost<target){
                solve(toppingCosts,target,cost,ans,reans,0);
            }
            
            // two topping...
            
        }
        return reans;
    }
};