#include <bits/stdc++.h>

using namespace std;


int find(int u,vector<int>& parent){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=find(parent[u],parent);
}

void unionAll(int a,int b,vector<int>& parent,vector<int>& size){
    int pa = find(a,parent);
    int pb = find(b,parent);

    if(pb==pa){
        return;
    }
    if(size[pa]>size[pb]){
        parent[pb]=pa;
        size[pa]+=size[pb];
    }else{
        parent[pa]=pb;
        size[pb]+=size[pa];
    }
    
    return;
}