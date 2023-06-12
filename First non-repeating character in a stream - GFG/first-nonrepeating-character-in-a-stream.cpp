//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	#define pp pair<char,int>
		string FirstNonRepeating(string A){
		    // Code here
		    // well we have to use the concept of zero.
		    int n = A.size();
		    vector<pp>time;
		    for(int i = 0;i<n;i++){
		        bool found = false;
		        for(auto &it: time){
		            if(it.first == A[i]){
		                it.second = it.second+1;
		                found = true;
		                break;
		            }
		        }
		        if(found == false){
		            time.push_back({A[i],1});
		        }
		        bool once = false;
		        for(auto it: time){
		            if(it.second == 1){
		                A[i] = it.first;
		                once= true;
		                break;
		            }
		            
		        }
		        if(once == false){
		            A[i] = '#';
		        }
		        
		        
		    }
		    return A;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends