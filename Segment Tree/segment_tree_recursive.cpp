#include <bits/stdc++.h>

using namespace std;

// Template for Min Segment Tree
class SegmentTree{
    // Tree root start at index 1
    long long* tree;
    int n;
    public:
    SegmentTree(vector<long long> arr){
        n = arr.size();
        tree = new long long[4*n];
        buildTree(1,0,n-1,arr);
    }

    long long query(int l,int r){
        return queryUtil(1,0,n-1,l,r);
    }

    void update(int index,long long val){
        updateUtil(1,index,0,n-1,val);
        return;
    }
    
    private:

    long long merge(long long a,long long b){
        return min(a,b);
    }
    
    void buildTree(int index,int l,int r,vector<long long>& arr){
        if(l>r){
            return;
        }
        if(l==r){
            tree[index]=arr[l];
            return;
        }
        int mid = l+ (r-l)/2;
        buildTree(2*index,l,mid,arr);
        buildTree(2*index+1,mid+1,r,arr);
        tree[index] = merge(tree[2*index],tree[2*index+1]);
        return;
    }

    long long queryUtil(int index,int i,int j,int l,int r){
        if(j<l || i>r){
            return INT_MAX;
        }
        if(i>=l && j<=r){
            return tree[index];
        }
        int mid = i+ (j-i)/2;
        long long leftAns = queryUtil(2*index,i,mid,l,r);
        long long rightAns = queryUtil(2*index+1,mid+1,j,l,r);
        return merge(leftAns,rightAns);
    }

    void updateUtil(int index,int updateIndex,int i,int j,long long val){
        if(i==j){
            tree[index]=val;
            return;
        }
        int mid = i+ (j-i)/2;
        if(updateIndex<=mid){
            updateUtil(2*index,updateIndex,i,mid,val);
        }else{
            updateUtil(2*index+1,updateIndex,mid+1,j,val);
        }
        tree[index] = merge(tree[2*index],tree[2*index+1]);
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

//     long long l,r,type;

//     while(q>0){
//         cin >> type >>  l >> r;
        
//         if(type==1){
//             l--;
//             tree.update(l,r);
//         }else{
//             l--;
//             r--; 
//             cout << tree.query(l,r) << endl;
//         }
//         q--;
//     }
    
//     return 0;
// }