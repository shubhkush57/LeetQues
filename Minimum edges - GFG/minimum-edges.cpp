//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        #define pp pair<int,int>
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pp> adj[n];
            for(auto it: edges){
                adj[it[0]-1].push_back({it[1]-1,0});
                adj[it[1]-1].push_back({it[0]-1,1});
            }
            vector<int>dis(n,INT_MAX);
            queue<pp>q;
            dis[src-1] = 0;
            q.push({src-1,0});
            while(!q.empty()){
                int t = q.size();
                while(t--){
                    pp f = q.front();q.pop();
                    int node = f.first;
                    int dist = f.second;
                    for(auto it: adj[node]){
                        int newnode = it.first;
                        int wt = it.second;
                        if(dis[newnode]>dist+wt){
                            dis[newnode] = dist+wt;
                            q.push({newnode,dis[newnode]});
                        }
                    }
                }
            }
            return dis[dst-1] == INT_MAX?-1:dis[dst-1];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends