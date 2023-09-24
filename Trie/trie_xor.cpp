#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    TrieNode* child[2];

    TrieNode(){
        for(int i=0;i<2;i++){
            this->child[i]=NULL;
        }
    }

};

class Trie{

    public:
    TrieNode* root;

    Trie(){
        this->root=new TrieNode();
    }

    void insert(int num){

        TrieNode* n = this->root;
        for(int i=31;i>=0;i--){
            int index = ((1 << i)&num)>0?1:0;
            if(n->child[index]==NULL){
                n->child[index] = new TrieNode();
            }
            n=n->child[index];
        }
        return;
    }

    int findXor(int num){
        TrieNode* n = this->root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int index = ((1 << i)&num)>0?1:0;
            if(n->child[1-index]!=NULL){
                n=n->child[1-index];
                ans |= (1<< i);
            }else{
                n=n->child[index];
            }
        }
        return ans;
    }

};
