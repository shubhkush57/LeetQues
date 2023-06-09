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
            int i = 0;
            for(;i<n;i++){
                if(citations[i]>=h){
                    break;
                }
            }
            int total = (n-i);
            if(total >=h){
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