#include <bits/stdc++.h>

using namespace std;

// Difference arrays are used for offline range updates.
// the updated array is the prefix sum of difference arrays
// Ex:   1,2,3,4,5 -> add from index 1 to 3 val=5
// diff: 0,5,0,0,-5,0 -> of size n+1
// When we do prefix sum of it: 0,5,5,5,0,0
// Add to original array: 0,7,8,9,5 => Done.

// update l,r(0 based indexing) => diff[l]+=val,diff[r+1]-=val; 

int main(){

    int n,q;
    vector<int> diff(n+1,0);
    while(q>0){
        //l and r are 0 based indexing
        int l,r,val;
        cin >> l >> r >> val;

        diff[l]+=val;
        diff[r+1]-=val;

        q--;
    }

    for(int i=1;i<=n;i++){
        diff[i]+=diff[i-1];
    }

    return 0;
}
