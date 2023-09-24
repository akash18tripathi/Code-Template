#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    TrieNode* child[26];
    bool isEndOfWord;

    TrieNode(){
        this->isEndOfWord=false;
        for(int i=0;i<26;i++){
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

    void insertWord(string word){
        TrieNode* n = this->root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(n->child[index]==NULL){
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
            if(n->child[index]==NULL){
                return false;
            }
            n=n->child[index];
        }
        return n->isEndOfWord;
    }

};