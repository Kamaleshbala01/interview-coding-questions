// This question was asked in google girls hackathon

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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


void onlinejudge(){
     #ifndef ONLINE_JUDGE
     freopen("../input.txt", "r", stdin);
     freopen("../output.txt", "w", stdout);
     #endif
     fast_cin();
}

int dfs(int node,vector<vector<int>>& adj,vector<int>&passangers,vector<bool>& vist){
    if(adj[node].empty()) return 0;

    int route = 0;
    vist[node] = true;

    for(auto i:adj[node]){
        if(!vist[i]) route += dfs(i,adj,passangers,vist);
    }

    if(route == 0 && passangers[node - 1]) return 1;
    else return route;
}

int minimumBus(int n,vector<pair<int,int>>& edges,vector<int>&passangers){
    vector<vector<int>> adj(n+1);
    for(auto i:edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    vector<bool> vist(n+1,false);

    int ans = dfs(1,adj,passangers,vist);
    return ans;
}

void solve(){
    int n,m;
    cin>>n;
    m = n-1;

    vector<int> passangers(n);
    vector<pair<int,int>> edges(m);

    for(int &i:passangers) cin>>i;

    for(auto &i:edges){
        cin>>i.first>>i.second;
    }

    vector<vector<int>> adj(n+1);

    cout<<minimumBus(n,edges,passangers);

}

int main() {
    onlinejudge();
    solve();
    return 0;
}