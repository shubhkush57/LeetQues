//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    #define pp pair<int,int>
    void solve(vector<pp> adj[],vector<bool>&vis,int k,int node,bool &ans){
        if(k<=0){
            ans = true;
            return;
        }
        for(auto it: adj[node]){
            if(vis[it.first] == false){
                vis[it.first] = true;
                solve(adj,vis,k-it.second,it.first,ans);
                vis[it.first] = false;
            }
        }
        return;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
       // idea here will be backtracking.
       // how edges are formred.
       int len = 3*E;
       vector<pp> adj[V];
       for(int i = 0;i<len;i+=3){
           adj[a[i]].push_back({a[i+1],a[i+2]});
           adj[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<bool>vis(V,false);
       // we ill backtrack.
       bool ans = false;
       vis[0] = true;
       solve(adj,vis,k,0,ans);
       return ans;
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends