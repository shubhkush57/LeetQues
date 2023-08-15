//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool>& vis,vector<bool>&inStack,int node){
        if(inStack[node]){
            return true;
        }
        if(vis[node]){
            return false;
        }
        vis[node]= true;
        inStack[node] = true;
        for(auto it: adj[node]){
            if(dfs(adj,vis,inStack,it)){
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
	bool isPossible(int n,int p, vector<pair<int, int> >& pre) {
	    // Code here
	    // we have to tell whether it is possible to fins all the tasks or not.
	    vector<int> adj[n];
	    for(auto it: pre){
	        adj[it.first].push_back(it.second);
	    }
	    vector<bool>vis(n,false);
	    vector<bool>inStack(n,false);
	    for(int i = 0;i<n;i++){
	        if(dfs(adj,vis,inStack,i)){
	            return false;
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends