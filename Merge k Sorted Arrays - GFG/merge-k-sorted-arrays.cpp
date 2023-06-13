//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    #define pp pair<int,int>
    #define ppp pair<int,pp>
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        // 1 2 3 4 5
        // 1 3 5 7 8/
        vector<int>ans;
        priority_queue<ppp,vector<ppp>,greater<ppp>>pq;
        for(int i = 0;i<k;i++){
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty()){
            ppp t = pq.top();pq.pop();
            ans.push_back(t.first);
            if(t.second.second+1<k){
                int ele = arr[t.second.first][t.second.second+1];
                pq.push({ele,{t.second.first,t.second.second+1}});
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
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends