class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int ans = 0;
        for(int i = 1;i<=n;i++){
           int s = 0;
            int e = n-1;
            int indx = -1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(citations[mid]>=i){
                    indx = mid;
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            if(indx != -1 && (n-indx)>= i){
                ans = i;
            }
        }
        return ans;
    }
};