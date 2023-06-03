//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str){
    
    int n = str.size();
    int i = 0;
    int j = n-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;j--;
    }
    return str;
  //Your code here
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends