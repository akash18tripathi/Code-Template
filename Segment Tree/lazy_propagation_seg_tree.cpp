#include <bits/stdc++.h>

using namespace std;


int* tree;
int n;
int* lazy;


void updateRange(int left,int right, int val) {
    updateRangeUtil(1,0,n-1,left,right,val);
    return;
}

int sumRange(int left,int right){
    return sumQuery(1,0,n-1,left,right);
}
//Build Tree Recursive. Root at 1
void buildTree(vector<int>& nums, int curr_index, int l, int r) {
    if (l == r) {
        tree[curr_index] = nums[l];
    }else{
        int mid = (l + r) / 2;
        buildTree(nums, 2*curr_index, l, mid);
        buildTree(nums, 2*curr_index+1, mid+1, r);
        tree[curr_index] = tree[2*curr_index] + tree[2*curr_index+1];
    }
}

//Update list- Add new_val in range
void updateRangeUtil(int curr_index, int i, int j, int left,int right, int new_val) {
    if(lazy[curr_index]!=0){
        //Do pending lazy update first
        tree[curr_index] += (j-i+1)*lazy[curr_index];

        //Propagate lazy updates to children(if not leaf)
        if(i!=j){
            lazy[2*curr_index]+= lazy[curr_index];
            lazy[2*curr_index+1]+= lazy[curr_index];
        }
        //No pending updates for curr node.
        lazy[curr_index]=0;
    }

    //completely out of range
    if(j<left || i>right || i>j){
        return;
    }
    //completely inside range
    if(left<=i && j<=right){

        tree[curr_index] += (j-i+1)*new_val;
        //Propagate lazy/pending updates to children
        if(i!=j){
            lazy[2*curr_index]+=new_val;
            lazy[2*curr_index+1]+=new_val;
        }
        return;
    }

    //Overlapping, so go in both directions
    int mid = (i + j) / 2;
    updateRangeUtil(curr_index*2, i, mid, left,min(right,mid), new_val);
    updateRangeUtil(curr_index*2+1, mid+1, j, max(mid+1,left),right, new_val);
        
    tree[curr_index] = tree[curr_index*2] + tree[curr_index*2+1];
    
}



//i and j are our tree bounds. left and right are queries
int sumQuery(int curr_index, int i, int j, int left, int right) {
    //Invalid or completely outside range
    if (left > right || i>j || i>right || j<left){
        return 0;
    }

    //Do pending updates of current node.
    if(lazy[curr_index]!=0){
        tree[curr_index] += (j-i+1)*lazy[curr_index];

        //Propagate lazy updates to children(if not leaf)
        if(i!=j){
            lazy[2*curr_index]+= lazy[curr_index];
            lazy[2*curr_index+1]+= lazy[curr_index];
        }
        //No pending updates for curr node.
        lazy[curr_index]=0;
    }
    //Found the node
    if (left==i && right == j) {
        return tree[curr_index];
    }

    //Overlaps, go in both direction.
    int mid = (i + j) / 2;
    return sumQuery(2*curr_index, i, mid, left, min(right, mid))
    + sumQuery(2*curr_index+1, mid+1, j, max(left, mid+1), right);
}