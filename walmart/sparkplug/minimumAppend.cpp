/*Question

Given an two string str1 and str2 find the minimum number of append need to find the subsequence of str2 in newStr if not possible print -1.

append rule : 
newStr = "";
newStr = newStr + str1;

input 1 :

str1 : abcdxyz
str2 : xyz

output : 1

Explanation : at initial we get the subsequence of str2 in str1 so the answer is 1



input 2 : 
str1 : abcdxyz
str2 : axyzb

output : 2

Explanation : append 0 str1 = "abcdxyz" at maximum we have make  "axyz" as subsequence
              append 1 str1 = "abcdxyzabcdxyz" we can get the subsequence of str2 in str1 


so the answer is 2





Constrains :

1<=str1.length,str2.length<=10^5 */


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
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
     fast_cin();
}

void solve(){
   string s1,s2;
   cin>>s1>>s2;

   vector<vector<int>> idx(26);

   int n = s1.size();

   // store the index of charactes for finding the first occurance in log n time because always
    // the index start form 0 th n so the next occurance of same characters will in sorted order

   for(int i=0;i<n;i++){
        idx[s1[i]-'a'].push_back(i);
   }

//    initial we are set a answer into 1 because s1 is consider as 1 append

   int ans = 1;


//    current Index denoted the index of an character in s2

   int curIdx = -1;

//    check if no such character present in string 1

   bool isPosible = true;

   for(int i=0;i<s2.size();){

        if(idx[s2[i]-'a'].size()==0) {
            isPosible = false;
            break;
        }

        // finding the next index of an character which can be an subsequence
        int posIdx = upper_bound(idx[s2[i]-'a'].begin(),idx[s2[i]-'a'].end(),curIdx)-idx[s2[i]-'a'].begin();

        // we find that the curAppend string will have the character to be used for subsequence
        if(posIdx>=0 && posIdx<idx[s2[i]-'a'].size()){
            curIdx = idx[s2[i]-'a'][posIdx];
            i++;
        }
        // the current append string not have the charater to used for an subequence
        else{
            ans+=1;
            curIdx = -1;
        }
   }

   cout<<(isPosible?ans:-1);
}

int main() {
    onlinejudge();
        solve();
    return 0;
}





