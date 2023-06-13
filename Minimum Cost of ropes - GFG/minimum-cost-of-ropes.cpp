//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    #define int2 long long
    long long minCost(long long arr[], long long n) {
        // Your code here
        int2 ans = 0;
        // minimum headp
        priority_queue<int2,vector<int2>,greater<int2>>pq;
        for(int2 i = 0;i<n;i++){
            pq.push(arr[i]);
        }
       
        while(pq.size()>=2){
            int2 t1 = pq.top();pq.pop();
            int2 t2 = pq.top();pq.pop();
            ans += (t1+t2);
            pq.push(t1+t2);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends