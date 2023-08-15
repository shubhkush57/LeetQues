//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool comp(vector<int>&v1,vector<int>&v2){
	    return v1[2]<v2[2];
	}
	void makeSet(vector<int>&parent){
	    int n = parent.size();
	    for(int i = 0;i<n;i++){
	        parent[i] = i;
	    }
	}
	int findParent(int node,vector<int>&parent){
	    if(node == parent[node]){
	        return node;
	    }
	    return parent[node] = findParent(parent[node],parent);
	}
	bool isDisjoint(int u,int v,vector<int>& parent){
	    u = findParent(u,parent);
	    v = findParent(v,parent);
	    return u != v;
	}
	void unionF(int u,int v,vector<int>&parent,vector<int>&rank){
	    u = findParent(u,parent);
	    v = findParent(v,parent);
	    if(rank[u]<rank[v]){
	        parent[u] = v;
	    }
	    else if(rank[u]>rank[v]){
	        parent[v] = u;
	    }
	    else {
	        parent[u] = v;
	        rank[v]++;
	    }
	    return;
	}
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        // we have to find the sum of the weight gaph.
        // sort(adj,adj+n,comp);
        vector<vector<int>>edges;
        for(int i = 0;i<n;i++){
            for(auto it: adj[i]){
                edges.push_back({i,it[0],it[1]});
            }
        }
        sort(edges.begin(),edges.end(),comp);
        int ans = 0;
        vector<int>parent(n);
        vector<int>rank(n,0);
        makeSet(parent);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if(isDisjoint(u,v,parent)){
                ans += wt;
                unionF(u,v,parent,rank);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends