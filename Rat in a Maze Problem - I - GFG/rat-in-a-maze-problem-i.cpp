//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4]={-1,1,0,0};
    int dy[4] ={0,0,-1,1};
    string path = "UDLR";
    void solve(vector<vector<int>>&grid,vector<string>&ans,string &temp,int i,int j,vector<vector<bool>>&vis){
        int n = grid.size();
        if(i == n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        for(int k = 0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx >=0 && nx<n && ny>=0 && ny<n && (vis[nx][ny] == false) && grid[nx][ny] == 1){
                vis[nx][ny] = true;
                temp.push_back(path[k]);
                solve(grid,ans,temp,nx,ny,vis);
                temp.pop_back();
                vis[nx][ny] = false;
            }
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        // Your code goes here
        // 0 block..
        // I have to return the path....
        vector<string>ans;
        string temp = "";
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if(grid[0][0] == 0 || grid[n-1][n-1] == 0){
            return ans;
        }
        vis[0][0] = true;
        solve(grid,ans,temp,0,0,vis);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends