//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(string &s,int i,int j,unordered_map<string,int>&mp){
        if(mp.count(s.substr(i,j-i+1))){
            return true;
        }
        bool ans = false;
        for(int k = i;k<j;k++){
            if(mp.count(s.substr(i,k-i+1))){
                ans = ans or solve(s,k+1,j,mp);
            }
        }
        return ans;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>mp;
        for(auto it: B){
            mp[it]++;
        }
        int i = 0;
        int n = A.size();
        return solve(A,i,n-1,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends