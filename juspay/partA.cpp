#include <complex> 
#include <queue> 
#include <set> 
#include <unordered_set> 
#include <list> 
#include <chrono> 
#include <climits>
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
#define forn(s,e) for(ll i = s; i < e; i++) 
#define rforn(s,e) for(ll i = s; i >= e; i--) 
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


// --------------------debug-----------------------------------


template <typename T>
void print(const T &val) {
    cout << val << endl;
}

template <typename T>
void print(T arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

template <typename T>
void print(const vector<T> &vec) {
    cout << "[ ";
    for (const auto &el : vec) {
        cout << el << " ";
    }
    cout << "]" << endl;
}

template <typename T>
void print(const vector<vector<T>> &vec) {
    cout << "[\n";
    for (const auto &row : vec) {
        cout << "  [ ";
        for (const auto &el : row) {
            cout << el << " ";
        }
        cout << "]\n";
    }
    cout << "]" << endl;
}

template <typename T>
void print(stack<T> s) {
    cout << "Stack (top -> bottom): [ ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "]" << endl;
}


template <typename T>
void print(queue<T> q) {
    cout << "Queue (front -> back): [ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "]" << endl;
}

template <typename T>
void print(priority_queue<T> pq) {
    cout << "Priority Queue (max heap): [ ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "]" << endl;
}

template <typename T>
void print(priority_queue<T, vector<T>, greater<T>> pq) {
    cout << "Priority Queue (min heap): [ ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "]" << endl;
}

//----------------------------debug end--------------------------------------


int powm(int a,int b, int mod){
    if(b==0) return 1;
    long long res = powm(a,b/2,mod);
    res = (res*res)%mod;
    if(b%2) res = (res*a)%mod;
    return res;
}

void onlinejudge(){
     #ifndef ONLINE_JUDGE 
     freopen("../input.txt", "r", stdin);
     freopen("../output.txt", "w", stdout);
     #endif
     fast_cin();
}

class Tree{
    public:
        string name;
        string par;
        set<Tree*> decentNode;
        int lockId;

        Tree(string name,string par){
            this->par = par;
            this->name = name;
            lockId = -1;
        }
};

bool lock(string node,int id,unordered_map<string,Tree*>& adj){
    if(adj[node]->lockId!=-1 || !adj[node]->decentNode.empty()) return false;

    auto curNode = adj[node];

    while(curNode->par!="-1"){
        Tree* par = adj[curNode->par];
        if(par->lockId!=-1) return false;
        curNode = par;
    }

    curNode = adj[node];
    while(curNode->par!="-1"){
        Tree* par = adj[curNode->par];
        par->decentNode.insert(adj[node]);
        curNode = par;
    }

    adj[node]->lockId = id;
    return true;
}


bool unlock(string node,int id,unordered_map<string,Tree*>& adj){
    if(adj[node]->lockId==-1 || adj[node]->lockId!=id) return false;

    auto curNode = adj[node];
    while(curNode->par!="-1"){
        Tree* par = adj[curNode->par];
        par->decentNode.erase(adj[node]);
        curNode = par;
    }

    adj[node]->lockId = -1;
    return true;

}

bool upgrade(string node,int id,unordered_map<string,Tree*>& adj){
    if(adj[node]->lockId!=-1 || adj[node]->decentNode.empty()) return false;

    for(auto i:adj[node]->decentNode){
        if(i->lockId!=id) return false;
    }
    for(auto i:adj[node]->decentNode){
        unlock(i->name,i->lockId,adj);
    }
    return lock(node,id,adj);
}

void solve(){
    int n,m,t;
    cin>>n>>m>>t;

    unordered_map<string,Tree*> adj;
    vector<string> node(n);

    for(int i=0;i<n;i++){
        cin>>node[i];
    }

    Tree * root = new Tree(node[0],"-1");
    adj[node[0]] = root;
    queue<string> q;
    q.push(node[0]);

    int idx = 1;

    while(idx<n){
        auto cur = q.front();
        q.pop();

        int i = 0;
        while(i<m){
            adj[node[idx]] = new Tree(node[idx],cur);
            q.push(node[idx]);
            idx++;
            if(idx>=n) break;
            i++;
        }
    }


    while(t--){
        int type,id;
        string curNode;

        cin>>type>>curNode>>id;
        

        if(type==1){
            cout<<(lock(curNode,id,adj)?"true":"false");
        }else if(type==2){
            cout<<(unlock(curNode,id,adj)?"true":"false");
        }else{
            cout<<(upgrade(curNode,id,adj)?"true":"false");
        }
        cout<<endl;
    }
        
}
int main() {
    onlinejudge();
    solve();
    return 0;   
}



