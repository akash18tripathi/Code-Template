#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    unordered_map<int,TrieNode*> child;
    bool isEndOfWord;

    TrieNode(){
        this->isEndOfWord=false;
    }

};

class Trie{

    public:
    TrieNode* root;

    Trie(){
        this->root=new TrieNode();
    }

    void insertWord(string word){
        TrieNode* n = this->root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(n->child.find(index)==n->child.end()){
                n->child[index] = new TrieNode();
            }
            n=n->child[index];
        }
        n->isEndOfWord=true;
    }
    
    bool search(string word){
        TrieNode* n = this->root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(n->child.find(index)==n->child.end()){
                return false;
            }
            n=n->child[index];
        }
        return n->isEndOfWord;
    }
};