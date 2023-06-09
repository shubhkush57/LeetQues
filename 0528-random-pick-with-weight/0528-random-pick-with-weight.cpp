class Solution {
public:
    vector<int>wt;
    vector<int>cum_sum;
    Solution(vector<int>& w) {
        wt = w;
        int n = wt.size();
        cum_sum.push_back(wt[0]);
        for(int i = 1;i<n;i++){
            cum_sum.push_back(cum_sum.back()+wt[i]);
        }
    }
    
    int pickIndex() {
        return getindex(cum_sum);
    }
    int getindex(vector<int>&cumsum){
        int n = cumsum.size();
        int sum = cumsum[n-1];
        int val = rand()%sum;
        // find the upperbound and return ti's index..
        int indx = upper_bound(cumsum.begin(),cumsum.end(),val)-cumsum.begin();
        // int start = 0;
        // int end = n-1;
        // int indx = -1;
        // while(start<=end){
        //     int mid = start+(end-start)/2;
        //     if(cumsum[mid]>=mid){
        //         indx = mid;
        //         end = mid-1;
        //     }
        //     else{
        //         start=  mid+1;
        //     }
        // }
        return indx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */