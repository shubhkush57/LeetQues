class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum = m+n;
        if(sum%2 == 0){
            return 1.0*(solve(nums1,nums2,0,m-1,0,n-1,sum/2)+solve(nums1,nums2,0,m-1,0,n-1,sum/2-1))/2;
        }
        return solve(nums1,nums2,0,m-1,0,n-1,sum/2);
    }
    
    int solve(vector<int>&nums1,vector<int>&nums2,int n1s,int n1e,int n2s,int n2e,int k){
        if(n1e<n1s){
            return nums2[k-n1s];
        }
        if(n2e<n2s){
            return nums1[k-n2s];
        }
        // now we will be getting middle indexss.
        int a = (n1s+n1e)/2;
        int b = (n2s+n2e)/2;
        int ele1 = nums1[a];
        int ele2 = nums2[b];
        if((a+b)<k){
            // right..
            
            if(ele1>ele2){
                return solve(nums1,nums2,n1s,n1e,b+1,n2e,k);
            }
            else{
                return solve(nums1,nums2,a+1,n1e,n2s,n2e,k);
            }
        }
        else{
            
            if(ele1>ele2){
                return solve(nums1,nums2,n1s,a-1,n2s,n2e,k);
            }
            else{
                return solve(nums1,nums2,n1s,n1e,n2s,b-1,k);
            }
        }
        
        return -1;
    }
};