#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll p = 153, MOD = 1e9+7;
const int mx = 2e6+5;
vector<ll> base(mx);
//Chamar precalc no iníco do código
void precalc(){
    base[0] = 1;
    for(int i=1;i<mx;i++){
        base[i] = (base[i-1]*p)%MOD;
    }
}
struct Hash {
    vector<ll> prefix;
    Hash(string &s){
        prefix.resize(s.size()+1, 0);
        for(int i=1;i<=s.size();i++){
            prefix[i] = ((prefix[i-1]*p)%MOD + s[i-1])%MOD;
        }
    }
    //gethash - 1 indexado
    ll getHash(int l, int r){
        ll val = (MOD + prefix[r] - (prefix[l-1]*base[r-l+1])%MOD)%MOD;
        return val;
    }

};
