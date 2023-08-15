//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    #define pp pair<int,int>
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int source)
    {
        // Code here
        // first we will write and then we will optimize dijkistra's...
        // works
        vector<int>dis(n,INT_MAX);
        dis[source] = 0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        // les't make it fast.
        vector<int>proceed(n,false);
        pq.push({0,source});
        while(!pq.empty()){
            pp f= pq.top();pq.pop();
            int node = f.second;
            if(proceed[node])continue;
            proceed[node] = true;
            int distance = f.first;
            for(auto it: adj[node]){
                int newnode = it[0];
                if(dis[newnode]>distance+it[1]){
                    dis[newnode] = distance+it[1];
                    pq.push({dis[newnode],newnode});
                }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends