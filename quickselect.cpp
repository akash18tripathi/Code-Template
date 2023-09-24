//Code to find Kth largest element
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int partition(int l,int h){
    int pivot = arr[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            int temp = arr[i+1];
            arr[i+1]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    int temp = arr[i+1];
    arr[i+1]=arr[h];
    arr[h]=temp;
    i++;
    return i;
}

int findKthLargest(int l,int h,int k){
    if(k>0 && k<=h-l+1){
        int pivot_index = partition(l,h);
        int pth_highest = h-pivot_index+1;
        if(pth_highest==k){
            return arr[pivot_index];
        }else if(pth_highest<k){
            return findKthLargest(l,pivot_index-1,k-pth_highest);
        }else{
            return findKthLargest(pivot_index+1,h,k);
        }
    }
    return INT_MAX;
}