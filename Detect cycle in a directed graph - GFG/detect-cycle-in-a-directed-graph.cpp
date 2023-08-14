//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<bool>&vis,vector<bool>&inStack,int node){
        if(inStack[node]){
            return true;
        }
        if(vis[node]){
            return false;
        }
        vis[node] = true;
        inStack[node] =true;
        for(auto it: adj[node]){
            if(dfs(adj,vis,inStack,it)){
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        // there is way we can say... using toposeor.... and salso there 
        vector<bool>vis(n,false);
        vector<bool>inStack(n,false);
        for(int i = 0;i<n;i++){
            if(vis[i] == false){
                if(dfs(adj,vis,inStack,i)){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends