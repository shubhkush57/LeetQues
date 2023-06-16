//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>>ans;
        vector<bool>vis(row,false);
        for(int i =0;i<row;i++){
            if(vis[i] == false){
                vector<int>re;
                for(int k = 0;k<col;k++){
                    re.push_back(M[i][k]);
                }
                ans.push_back(re);
                for(int j = i;j<row;j++){
                    vector<int>re1;
                    for(int k = 0;k<col;k++){
                        re1.push_back(M[j][k]);
                    }
                    if(re == re1){
                        vis[j] = true;
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
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends