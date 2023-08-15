//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int>topo;
	void dfs(vector<int> adj[],vector<bool>& vis,int node){
	    vis[node] = true;
	    for(auto it: adj[node]){
	        if(vis[it] == false){
	            dfs(adj,vis,it);
	        }
	    }
	    topo.push_back(node);
	    return;
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    // using dfs since it is a dag gaph so toposort is always possible.
	   // vector<int>topo;
	    vector<bool>vis(n,false);
	    for(int i = 0;i<n;i++){
	        if(vis[i] == false){
	            dfs(adj,vis,i);
	        }
	    }
	    reverse(topo.begin(),topo.end());
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends