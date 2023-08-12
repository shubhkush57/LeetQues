//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array
    #define pp pair<int,int> 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pp>v;
	    for(int i = 0;i<n;i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    vector<bool>vis(n,false);
	    int ans = 0;
	    for(int i = 0;i<n;i++){
	        if(v[i].second == i || vis[i] == true){
	            vis[i] = true; 
	            continue;
	        }
	        else{
	            int cyl =0;
	            int j = v[i].second;
	            while(vis[j] == false){
	                vis[j] = true;
	                cyl++;
	                j = v[j].second;
	            }
	            ans += cyl-1;
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends