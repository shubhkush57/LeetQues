//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int arr[],int n,int i,int j,vector<vector<int>>&dp){
	    if(j>=n){
	        return 0;
	    }
	    if(dp[i][j]  != -1){
	        return dp[i][j];
	    }
	    int ans = 0;
	    if(arr[i]<arr[j]){
	        ans = max(ans,arr[j]+solve(arr,n,j,j+1,dp));
	    }
	    ans = max(ans,solve(arr,n,i,j+1,dp));
	   // ans= max(ans,arr[j]+solve(arr,n,j,j+1));
	    return dp[i][j] = ans;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int ans = 0;
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    for(int i = 0;i<n;i++){
	        ans  = max(ans,arr[i]+solve(arr,n,i,i+1,dp));
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends