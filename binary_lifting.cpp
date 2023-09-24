#include <bits/stdc++.h>

using namespace std;


int n, height;
vector<vector<int>> adj;
vector<vector<int>> up;

// Filling Table
// up[node][j] => 2^j th ancestor of 'node'
// nlogn preprocessing
void dfs(int node, int par)
{
    up[node][0] = par;
    for (int i = 1; i <= height; ++i){
        up[node][i] = up[up[node][i-1]][i-1];
    }
    for (int u : adj[node]) {
        if (u != par)
            dfs(u, node);
    }
}

int main(){

    // define adj list here!
    height = ceil(log2(n));
    up = vector<vector<int>>(n, vector<int>(height + 1));
    int root=0;
    //root is a parent of root
    dfs(root, root);
}
