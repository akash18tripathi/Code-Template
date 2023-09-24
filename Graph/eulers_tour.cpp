#include <bits/stdc++.h>

using namespace std;

vector<int> startTime;
vector<int> endTime;
vector<long long> tour;
int currTime;



void dfs(int node,vector<int> adj[],int parent,vector<long long int>& arr){

    currTime++;
    tour[currTime]=arr[node];
    startTime[node]=currTime

    for(int e: adj[node]){
        if(e!=parent){
            dfs(e,adj,node,arr);
        }
    }
    endTime[node]=currTime;
}


int main(){

    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> adj[n];
    long long int u,v;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    startTime = vector<int>(n);
    endTime = vector<int>(n);
    tour = vector<long long int>(n);
    currTime=-1;
    dfs(0,adj,-1,arr);



}
