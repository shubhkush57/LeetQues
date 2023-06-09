class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        int start = 0;
        int end = INT_MAX;
        while(start<=end){
            int h = start+(end-start)/2;
            // this is the ciation.. // if there are h reach papter with atlest h cittios..
            int i = -1;
            int s = 0;
            int e = n-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(citations[mid]>=h){
                    e= mid-1;
                    i = mid;
                }
                else{
                    s = mid+1;
                }
            }
            // for(;i<n;i++){
            //     if(citations[i]>=h){
            //         break;
            //     }
            // }
            // int total = (n-i);
            if(i != -1 && (n-i)>=h){
                ans = h;
                start = h+1;
            }
            else{
                end = h-1;
            }
        }
        return ans;
    }
};