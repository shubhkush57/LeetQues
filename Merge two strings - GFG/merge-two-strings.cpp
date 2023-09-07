//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string s1, string s2)
{
    // your code here
    string ans = "";
    int n1 = s1.size();
    int n2 = s2.size();
    int i= 0,j = 0;
    int count = 0;
    while(i<n1 && j<n2){
        if(count%2 == 0){
            ans.push_back(s1[i]);
            i++;
        }
        else{
            ans.push_back(s2[j]);
            j++;
        }
        count++;
        
    }
    while(i<n1){
        ans.push_back(s1[i]);
        i++;
    }
    while(j<n2){
        ans.push_back(s2[j]);
        j++;
    }
    return ans;
}