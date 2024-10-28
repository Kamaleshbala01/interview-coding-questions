// Complementary Pairs
// A pair of strings form a complementary pair if there is same permutation of their concatenation that is a palindrome.
//  For example, the strings "abac" and "cab" form a complementary pair since their concatenation is "abaccab" which can be rearranged to form a palindrome, i.e "bcaaacb"

// Given an array of n strings, find the number of complementary pairs that can be formed
// Note: Pairs of strings formed by indices (i,j) and (j,i) are considered the same

// Example
// Consider StringData = ["abc", "abcd","bc","adc"].

// The following complementary pairs can be formed

// {"abc","abcd"} concatenated string = "abcabcd" - arranged as palindrome -> "abcdcba"
// {"abc","bc"}  concatenated string = "abcbc" -> "bcacb"
// {"abcd", "adc"} concatenated string = "abcdadc" -> "acdbdca"

// return 3, the number of complementary pairs


// constrains 

// 1<= n <= 10^5
// 1<= str.length*n<=3*10^5

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

// this function helps to convert the string into integer because we only need to rack the odd characters we have 26 characters which can fit in 32 bit integer 
// so we use each bit as unique representation of an character like 
// a = 1 st bit
// b = 2 nd bit ans so on 

int hashString(string &str){
    int val = 0;

    for(char c:str){
        int bit = c-'a';
    // basic toogle bit aproach which manage the odd count 
    // if the charcter has odd count then the respective bit is set
    // otherwise the respective bit is unset
        val = val^(1<<bit);
    }
    return val;
}

void solve(){
   int n;
   cin>>n;

   vector<string> strs(n);
   for(auto &i:strs) cin>>i;

// a basic two sum approach to find the compliment pairs 
// Here for palindrome we can have either or have one odd character count    

   unordered_map<int,int> mp;

   int ans = 0;

   for(string s:strs){
        int curHash = hashString(s);
        if(mp.find(curHash)!=mp.end()) ans+=mp[curHash];

    // To handle the odd charcter count we toggle each 26 bits and find the answer
        for(int i=0;i<26;i++){
            int modifyHash = curHash^(1<<i);
            if(mp.find(modifyHash)!=mp.end()) ans+=mp[modifyHash];
        }

    // store the current string to the map
        mp[curHash]++;
   }

   cout<<ans;


}

int main() {
    onlinejudge();
        solve();
    return 0;
}