//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         // here in the arr data from l - mid is sorted
         // and data from mid+1 to r is sorted.
         // you have to just reorder them in the correct sorted sorted like 
         // merging the two sorted array's
         int lsiz = mid-l+1;
         int left[lsiz];
         int z = 0;
         for(int i = l;i<=mid;i++){
             left[z] = (arr[i]);
             z++;
         }
         int rsiz = r-mid;
         int right[rsiz];
         z = 0;
         for(int i = mid+1;i<=r;i++){
             right[z] = (arr[i]);
             z++;
         }
         int j = l;
         int p1 = 0;
         int p2 = 0;
         while(p1 < lsiz && p2<rsiz){
             if(left[p1] <= right[p2]){
                 arr[j] = left[p1];
                 p1++;
             }
             else{
                 arr[j] = right[p2];
                 p2++;
             }
             j++;
         }
         while(p2 < rsiz){
             arr[j]  = right[p2];
             p2++;
             j++;
         }
         while(p1< lsiz){
             arr[j] = left[p1];
             p1++;
             j++;
         }
         return;
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            // keep dividing the arr
            int mid = l +(r-l)/2;
            mergeSort(arr,l,mid);
            // this will sort the data form l to mid
            mergeSort(arr,mid+1,r);
            // tis will sort the data from mid+1 to r
            // this will merge the two sorted list.
            merge(arr,l,mid,r);
        }
        return;
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends