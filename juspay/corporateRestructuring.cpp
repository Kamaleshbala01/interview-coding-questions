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

using namespace std;

bool findSubordinate(int node,vector<vector<int>>& adj,vector<bool>& sub,vector<int>& infected){
    if(adj[node].empty()) {
        return infected[node]==0;
    }

    bool pos = false;

    for(auto i:adj[node]){
        pos |= findSubordinate(i,adj,sub,infected);
    }

    sub[node] = pos;
    return (pos && infected[node]==0);
}

void solve(){
    int n;
    cin>>n;
    
    vector<vector<int>> adj(n+1);
    vector<int> infected(n+1);

    int par = -1;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a==-1) par = i+1;
        else{
            adj[a].push_back(i+1);
        }
        infected[i+1] = b;
    }

    vector<bool> sub(n+1,false);

    findSubordinate(par,adj,sub,infected);

    queue<int> q;
    q.push(par);

    while(!q.empty()){
        int node = q.front();q.pop();

        if(infected[node]==1 && sub[node]==0) cout<<node<<" ";

        for(int i:adj[node]){
            q.push(i);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}