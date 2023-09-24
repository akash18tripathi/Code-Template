class Solution{
  public:
    
    long long int merge(long long arr[],int n,int l,int mid,int r){
        int leftLen = mid-l+1;
        int rightLen=r-mid;
        long long temp[leftLen+rightLen];
        int i=l,j=mid+1,k=0;
        long long  invCount=0;
        while(i<=mid && j<=r){
            if(arr[i]>arr[j]){
                invCount+= mid-i+1;
                temp[k]=arr[j];
                j++;
                k++;
            }else if(arr[i]<=arr[j]){
                temp[k]=arr[i];
                i++;
                k++;
            }
        }
        
        while(i<=mid){
            temp[k]=arr[i];
            k++;
            i++;
        }
        while(j<=r){
            temp[k]=arr[j];
            k++;
            j++;
        }
        for(i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
        return invCount;
    }
    
    long long  mergeSort(long long arr[],int n,int left,int right){
        if(left==right){
            return 0;
        }
        long long invCount=0;
        if(left<right){
            int mid=left+(right-left)/2;
            long long  leftCount=mergeSort(arr,n,left,mid);
            long long  rightCount=mergeSort(arr,n,mid+1,right);
            long long  mergedCount=merge(arr,n,left,mid,right);
            invCount=leftCount+rightCount+mergedCount;
        }
        return invCount;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
         int n = N;
         return mergeSort(arr,n,0,n-1);
    }

};
