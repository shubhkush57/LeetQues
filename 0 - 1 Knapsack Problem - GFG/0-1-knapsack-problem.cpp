//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W,int wt[],int val[],int n,int i,vector<vector<int>>&dp){
        if(W <= 0 || i>=n){
            return 0;
        }
        if(dp[W][i] != -1){
            return dp[W][i];
        }
        int ans = 0;
        // take it or not..
        ans = max(ans,solve(W,wt,val,n,i+1,dp));
        if(W-wt[i]>=0){
            // we can take it
            ans = max(ans,val[i]+solve(W-wt[i],wt,val,n,i+1,dp));
        }
        return dp[W][i]= ans;
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // pick or not if you are going to pick it mens weigt is going to reduce and val is going to increase...
       int i = 0;
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return solve(W,wt,val,n,i,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends