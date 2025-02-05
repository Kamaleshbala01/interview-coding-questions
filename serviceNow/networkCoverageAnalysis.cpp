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


class SegmentTree{
    public:
    vector<int> seg;

    SegmentTree(int n){
        seg.resize(4 * n + 1);
    }

    void build(int idx,int low,int high,vector<int>&arr){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        build(2 * idx + 1,low, mid,arr);
        build(2 * idx + 2,mid+1, high,arr);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }


    int findMax(int idx,int low,int high,int l,int r){
        // no overLap low high l r || l r low high
        if(high<l || r<low) return INT_MIN;

        // complete overlap l low high r
        if(low>=l && r>=high) return seg[idx];

        // partial overlap

        int mid = low + (high - low)/2;

        int left = findMax(2 * idx + 1,low,mid,l,r);
        int right = findMax(2 * idx + 2, mid + 1,high, l, r);

        return max(left, right); 
    }

    void update(int idx, int low, int high, int i,int val){
        if(low==high){
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low)/2;;

        if(i<=mid) update(2 * idx + 1, low, mid, i,val);
        else update(2 * idx + 2, mid + 1,high, i,val);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

};

void solve(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> arr(n);
    for(auto &i:arr) cin>>i.first>>i.second;

    vector<pair<int,int>> query(m);
    for(auto &i:query) cin>>i.first>>i.second;

    
    // using line sweep to find the coverage count in O(NlogN).
    vector<pair<int, int>> events; 

   
    for (auto &[start, end] : arr) {
        events.push_back({start, +1});  
        events.push_back({end + 1, -1});
    }

    
    sort(events.begin(), events.end());

   vector<int> coverageCount(n+1); 
    int activeRanges = 0, prevX = -1;

    for (auto &[x, type] : events) {
        if (prevX != -1 && activeRanges > 0 && activeRanges<=n) {
            coverageCount[activeRanges] += (x - prevX);
        }
        activeRanges += type; 
        prevX = x;
    }

    // using segment tree to process all query in aproximatly O(logN)
    SegmentTree seg(n+1);
    seg.build(0,0,n,coverageCount);

    // processing each query 
    for(auto i:query){
        cout<<seg.findMax(0,0,n,i.first,i.second)<<" ";
    }

    // overAll time Complixity is O(NlogN + MlogN);
    // space Complixity O(6N) = O(N).
    
}

int main() {
    onlinejudge();
        solve();
    return 0;
}