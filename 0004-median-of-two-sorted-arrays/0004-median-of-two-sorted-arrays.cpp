class Solution {
public:
    // medain of two sorted arrays...
    int p1 = 0;
    int p2 = 0;
    int getmin(vector<int>&nums1,vector<int>&nums2){
        int m = nums1.size();
        int n = nums2.size();
        if(p1<m && p2<n){
            return nums1[p1]<nums2[p2]?nums1[p1++]:nums2[p2++];
        }
        else if(p1<m){
            return nums1[p1++];
        }
        else if(p2<n){
            return nums2[p2++];
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n = nums2.size();
        int sum = m+n;
        if(sum%2 == 0){
            for(int i = 0;i<sum/2-1;i++){
                int t = getmin(nums1,nums2);
            }
            return (getmin(nums1,nums2)+getmin(nums1,nums2))/2.0;
        }
        else{
            for(int i = 0;i<sum/2;i++){
                getmin(nums1,nums2);
            }
            return getmin(nums1,nums2);
        }
        return -1;
    }
};