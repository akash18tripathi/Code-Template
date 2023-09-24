#include <bits/stdc++.h>

using namespace std;

//Simple Binary Search
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l=0,r=n-1,mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(target < nums[mid]){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return -1;
}

int lowerBound(int arr[],int n,int x){
    int i=0,j=n-1,mid;
    int ans=n;
    while(i<=j){
        mid = i+(j-i)/2;
        if(arr[mid]>=x){
            ans=mid;
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    return ans;
}
int upperBound(int arr[],int n,int x){
    int i=0,j=n-1,mid;
    int ans=n;
    while(i<=j){
        mid = i+(j-i)/2;
        if(arr[mid]>x){
            ans=mid;
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    return ans;
}


