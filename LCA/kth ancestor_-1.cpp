#include <bits/stdc++.h>

using namespace std;


//-1 is the ancestor of root (i.e no node) -> this case is handled here

int height;
vector<vector<int>> up;
vector<int> *adj;


void dfs(int node,int par,vector<int>& parent){
    up[node][0]=par;
    for(int i=1;i<height;i++){
        if(up[node][i-1]!=-1){
            up[node][i] = up[ up[node][i-1] ][i-1];
        }else{
            up[node][i]=-1;
        }
    }
    for(int e: adj[node]){
        if(e!=par){
            dfs(e,node,parent);
        }
    }
}

int getKthAncestor(int node, int k) {
    if(node==-1 || k==0){
        return node;
    }
    for(int i=height-1;i>=0;i--){
        if(k&(1 << i)){
            return getKthAncestor(up[node][i],k-(1 << i));
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> parent(n);
    height = ceil(log(n)/log(2));
    up = vector<vector<int>>(n+1,vector<int>(height));
    adj = new vector<int>[n];
    for(int i=1;i<n;i++){
        adj[parent[i]].push_back(i);
        // adj[i].push_back(parent[i]);
    }

    dfs(0,-1,parent);

}