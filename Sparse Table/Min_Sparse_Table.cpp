#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> table;
int logN;

void buildSparseTable(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        table[i][0]=arr[i];
    }
    for(int j=1;j<=logN;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            table[i][j] = min(table[i][j-1],table[ i+ (1<<(j-1))][j-1] );
        }
    }
    return;
}

int query(int l,int r){
    int width = r-l+1;
    int j = 0;
    //Gets log of width
    while((1 << (j+1)) <=width){
        j++;
    }
    return min(table[l][j],table[r-(1<<j)+1][j]);
}

int main(){
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    logN = floor(log2(n));
    table = vector<vector<int>>(n,vector<int>(logN+1));
    int q;
    cin >> q;
    buildSparseTable(arr);
    
    
    int l,r;
    while(q>0){
        cin >> l >> r;
        cout << query(l,r) << endl;;


        q--;
    }

    return 0;
}