#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
    // Tree root start at index 1
    long long* lazy;
    int n;
    public:
    SegmentTree(vector<long long> arr){
        n = arr.size();
        lazy = new long long[4*n];
        buildTree(1,0,n-1,arr);
    }

    long long query(int index){
        return queryUtil(1,index,0,n-1);
    }

    void update(int l,int r,long long val){
        updateUtil(1,l,r,0,n-1,val);
        return;
    }
    
    private:

    void buildTree(int index,int l,int r,vector<long long>& arr){
        if(l>r){
            return;
        }
        if(l==r){
            lazy[index]=arr[l];
            return;
        }
        int mid = l+ (r-l)/2;
        buildTree(2*index,l,mid,arr);
        buildTree(2*index+1,mid+1,r,arr);
        return;
    }
    
    long long queryUtil(int index,int k,int i,int j){
        if(i==j){
            return lazy[index];
        }
        if(lazy[index]!=0){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
            lazy[index]=0;
        }
        
        int mid = i+ (j-i)/2;
        if(k<=mid){
            return queryUtil(2*index,k,i,mid);
        }else{
            return queryUtil(2*index+1,k,mid+1,j);
        }
    }

    void updateUtil(int index,int l,int r,int i,int j,long long val){
        if(j<l || i>r || i>j){
            return;
        }
        
        if(i>=l && j<=r){
            lazy[index]+=val;
            if(i!=j){
                lazy[2*index]+=lazy[index];
                lazy[2*index+1]+=lazy[index];
                lazy[index]=0;
            }
            return;
        }
        int mid = i+ (j-i)/2;
        updateUtil(2*index,l,r,i,mid,val);
        updateUtil(2*index+1,l,r,mid+1,j,val);
        return;
    }

    
    
};

// int main(){
//     int n,q;
//     cin >> n >> q;
//     vector<long long> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     SegmentTree tree(arr);

//     long long l,r,type,val;

//     while(q>0){
//         cin >> type;
        
//         if(type==2){
//             cin >> l;
//             l--;
//             cout << tree.query(l) << endl;
//         }else{
//             cin >> l >> r >> val;
//             l--;
//             r--; 
//             tree.update(l,r,val);
//         }
//         q--;
//     }
    
//     return 0;
// }