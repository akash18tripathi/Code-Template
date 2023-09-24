#include <bits/stdc++.h>

using namespace std;

// TEMPLATE FOR MERGE SORT TREE, NUMBER OF DISTINCT ELEMENTS IN RANGE, >VAL
class SegmentTree{
    // Tree root start at index 1
    vector<int>* tree;
    int n;
    public:
    SegmentTree(vector<long long> arr){
        n = arr.size();
        tree = new vector<int>[4*n];
        buildTree(1,0,n-1,arr);
    }

    long long query(int l,int r,int val){
        return queryUtil(1,0,n-1,l,r,val);
    }
    
    private:

    vector<int> merge(vector<int>& a,vector<int>& b){
        
        int i=0,j=0,n=a.size(),m=b.size();
        vector<int> ans(n+m);
        int k=0;
        while(i<n && j<m){
            if(a[i]<=b[j]){
                ans[k]=a[i];
                i++;
                k++;
            }else{
                ans[k]=b[j];
                j++;
                k++;
            }
        }
        while(i<n){
            ans[k]=a[i];
            i++;
            k++;
        }
        while(j<m){
            ans[k]=b[j];
            j++;
            k++;
        }
        return ans;
    }
    
    void buildTree(int index,int l,int r,vector<long long>& arr){
        if(l>r){
            return;
        }
        if(l==r){
            tree[index].push_back(arr[l]);
            return;
        }
        int mid = l+ (r-l)/2;
        buildTree(2*index,l,mid,arr);
        buildTree(2*index+1,mid+1,r,arr);
        tree[index]= merge(tree[2*index],tree[2*index+1]);
        return;
    }

    // Num of elements in range >val
    long long queryUtil(int index,int i,int j,int l,int r,int val){
        if(j<l || i>r){
            return 0;
        }
        if(i>=l && j<=r){
            int ans =  tree[index].end() - upper_bound(tree[index].begin(),tree[index].end(),val);
            return ans;
        }
        int mid = i+ (j-i)/2;
        long long leftAns = queryUtil(2*index,i,mid,l,r,val);
        long long rightAns = queryUtil(2*index+1,mid+1,j,l,r,val);
        return leftAns+rightAns;
    }
    
};

int main(){
    int n,q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    SegmentTree tree(arr);
    int a,b;
    while(q>0){
        cin >> a >> b;
        a--;
        b--;
        cout << tree.query(a,b,b) << endl;

        q--;
    }

}