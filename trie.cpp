#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5, A = 27;
const int MOD = 1e9 + 7;
#define ll long long
struct Node{
    int terminal = 0;
    int next[A];
    Node(){
        memset(next, -1, sizeof next);
    }
};
 
vector<Node> trie(1);
 
void add(string s){
    int v = 0;
    for(char ch : s){ 
        if(trie[v].next[ch - 'a'] == -1){
            trie[v].next[ch - 'a'] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[ch - 'a'];
    }
    trie[v].terminal++;
}
ll Count(string s){
    int v = 0;
    for(char ch:s){
        if(trie[v].next[ch - 'a'] == -1)return 0;
        v = trie[v].next[ch-'a'];
    }
    return trie[v].terminal;
}
 