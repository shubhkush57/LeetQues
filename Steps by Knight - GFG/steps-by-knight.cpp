//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    #define pp pair<int,int>
    int dx[8] = {-2,-2,2,2,-1,-1,1,1};
    int dy[8] = {1,-1,1,-1,-2,2,-2,2};
	int minStepToReachTarget(vector<int>&pos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    // we have given knight position in the grid..
	    vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
	    queue<pp>q;
	    dp[pos[0]][pos[1]] = 0;
	    q.push({pos[0],pos[1]});
	    int level = 0;
	    while(!q.empty()){
	        int t = q.size();
	        while(t--){
	            pp f = q.front();q.pop();
	            if(f.first == TargetPos[0] && f.second == TargetPos[1]){
	                return dp[f.first][f.second];
	            }
	            int x= f.first;
	            int y = f.second;
	            for(int k = 0;k<8;k++){
	                int nx = x+dx[k];
	                int ny = y+dy[k];
	                if(nx>0 && nx<=n && ny>0 && ny<=n && dp[nx][ny]>level+1){
	                    dp[nx][ny] = level+1;
	                    q.push({nx,ny});
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends