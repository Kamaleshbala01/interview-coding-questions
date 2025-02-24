// Given an array of string return number of good pairs.
// Good pairs : consider a two string from an array i,j
// the pair is consider as good pairs if the suffix of i is j or j is i

// Example: 
// arr = ["abc","bc","d"]
// the good pairs are : ["abc","bc"]
// return 1;

#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update> index_set;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define MSB(x) (32-__builtin_clz(x))
#define pb push_back
#define fi first
#define se second
#define INF 100000007
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void onlinejudge(){
     #ifndef ONLINE_JUDGE
     freopen("../input.txt", "r", stdin);
     freopen("../output.txt", "w", stdout);
     #endif
     fast_cin();
}


struct Trie{
    Trie *child[26];
    int cnt;

    Trie(){
        for(auto &i:child) i = nullptr;
        cnt = 0;
    }
};

void insert(string &s,Trie*root){
    for(char c:s){
        if(!root->child[c-'a']) root->child[c-'a'] = new Trie;
        root->child[c-'a']->cnt++;
        root = root->child[c-'a'];
    }
}

int find(string &s,Trie* root){
    for(char c:s){
        if(!root->child[c-'a']) return 0;
        root = root->child[c-'a'];
    }

    return root->cnt-1;
}

void solve(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(string &i:arr) cin>>i;

    Trie *root = new Trie();

    for(string &s:arr){
        reverse(s.begin(),s.end());
        insert(s,root);
    }
    
    unordered_map<string,int> mp;
    ll ans = 0;
    for(string &s:arr){
        ans+=find(s,root);
        ans-=mp[s];
        mp[s]++;
    }

    cout<<ans;
}


int main() {
    onlinejudge();
        solve();
    return 0;
}