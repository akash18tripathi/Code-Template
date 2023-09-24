#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<vector<int>> up;
int height;
vector<int> depth;

// fill up table and depth
void dfs(int node,int par,vector<int> adj[]){
    up[node][0]=par;
    for(int i=1;i<=height;i++){
        up[node][i]=up[ up[node][i-1] ][i-1];
    }

    for(int e: adj[node]){
        
        if(e!=par){
            depth[e] = 1+ depth[node];
            dfs(e,node,adj);
        }
    }
    
} 

int lca(int a,int b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    // bring a and b to same level
    int k = depth[a]-depth[b];
    for(int i=height;i>=0;i--){
        if(k&(1 << i)){
            a = up[a][i];
        }
    }
    // if one was ancestor of second
    if(a==b){
        return a;
    }
    // Go up in logn
    for(int i=height;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    // ans is parent of a/b
    return up[a][0];
}


int main() {
	// your code goes here
	int n;
    cin >> n;
    vector<int> adj[n];
    int m,v;
    for(int i=0;i<n;i++){
        cin >> m;;
        for(int j=0;j<m;j++){
            cin >> v;
            adj[i].push_back(v);
        }        
    }
    height=ceil(log2(n));
    up = vector<vector<int>>(n,vector<int>(height+1));
    depth = vector<int>(n,0);

    dfs(0,0,adj);
    int q;
    cin >> q;
    int u;
    while(q>0){
        cin >> u >> v;
        cout << lca(u,v) << endl;
        q--;
    }
    

	return 0;
}