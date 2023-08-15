//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here  
            vector<int>ans(n,0);
            vector<int> adj[n];
            vector<int>indegree(n,0);
            for(int i = 0;i<m;i++){
                adj[edges[i][0]-1].push_back(edges[i][1]-1);
                indegree[edges[i][1]-1]++;
            }
            // if it's not zero it's means it has been visited.
            queue<int>q;
            for(int i = 0;i<n;i++){
                if(indegree[i] == 0){
                    ans[i] = 1;
                    q.push(i);
                }
            }
            while(!q.empty()){
                int t = q.size();
                while(t--){
                    int f = q.front();q.pop();
                    for(auto it: adj[f]){
                        if(ans[it] == 0){
                            indegree[it]--;
                            if(indegree[it] == 0){
                                ans[it] = ans[f]+1;
                                q.push(it);
                            }
                        }
                    }
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends