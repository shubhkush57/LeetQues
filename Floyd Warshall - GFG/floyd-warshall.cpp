//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    // we have to find the shoretest distance from every node to another node.
	    // we have to update this.
	    int n = matrix.size();
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            if(matrix[i][j]== -1){
	                matrix[i][j] = INT_MAX;
	            }
	        }
	    }
	    // now we have to implement floyad warshed alog.
	    for(int k =0;k<n;k++){
	        for(int i = 0;i<n;i++){
	            for(int j =0 ;j<n;j++){
	                if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX){
	                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                }
	            }
	        }
	    }
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            if(matrix[i][j]== INT_MAX){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	    return;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends