#include <bits/stdc++.h>

using namespace std;

// SCC: In a SCC, each node is reachable to evry other node,i.e CYCLE
// Kosaraju's Algo: put Nodes in stack in order of their finish time.
// Reverse the graph edges and apply below dfs
// SCC1->SCC2->SCC3->SCC4 (SCC4 node will be on top of stack, apply dfs, then SCC3 node will be,etc..)
// Pop fron stack, if not visited apply dfs.


// Pushes node when it's done
void dfs1(int node,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& endTime){
    if(vis[node]){
        return;
    }
    vis[node]=true;
    for(int e: adj[node]){
        if(!vis[e]){
            dfs1(e,adj,vis,endTime);
        }
    }
    endTime.push(node);
}

//Basic DFS
void dfs2(int node,vector<vector<int>>& adj,vector<bool>& vis){
    if(vis[node]){
        return;
    }
    vis[node]=true;
    for(int e: adj[node]){
        if(!vis[e]){
            dfs2(e,adj,vis);
        }
    }
}

//Num of SCC. We can also find max length of Cycle.
int numOfSCC_kosaraju(int V, vector<vector<int>>& adj)
{
    //code here
    int n = V;
    stack<int> endTime;
    vector<bool> vis(n,false);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs1(i,adj,vis,endTime);
        }
    }
    vector<vector<int>> revGraph(n);
    for(int i=0;i<n;i++){
        for(int e: adj[i]){
            revGraph[e].push_back(i);
        }
    }
    
    fill(vis.begin(),vis.end(),false);
    int ans=0;
    while(!endTime.empty()){
        int node = endTime.top();
        endTime.pop();
        if(!vis[node]){
            // cout << node << " ";
            ans++;
            dfs2(node,revGraph,vis);
        }

    }
    return ans;

}