/*
You are given two strings S and R, each of size N, containing lowercase English letters.

You can do the following operations any number of times:
· Type 0: Select any two indices i and j from 0 to n - 1 and swap
S[i] with S[j]. This operation is free of cost.

· Type 1: Select any index i from 0 to n - 1 and swap S[i] with any
lowercase English letter. This operation costs 1 coin.

Task
Determine the minimum cost to make string S equal to R.
Note: 0-based indexing is followed.


Example : 

N = 5
S = abdfd
R = abcde

Output : 2


Explanation :

The required operations are:
· Type 0: Select two indices 2 and 3 and swap them. The string
S becomes "abfdd".
. Type 1: Select index 2 and replace it with the character 'c' The
string S becomes "abcdd". This operation costs 1 coin.
· Type 1: Select index 4 and replace it with the character 'e'. The
string S becomes "abcde". This operation also costs 1 coin.
Hence, the minimum cost is 2.


*/

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


#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


void onlinejudge(){
     #ifndef ONLINE_JUDGE
     freopen("../input.txt", "r", stdin);
     freopen("../output.txt", "w", stdout);
     #endif
     fast_cin();
}

void solve(){
    string s,r;
    cin>>s>>r;

    vector<int> sf(26,0), rf(26,0);

    for(char c:s) sf[c-'a']++;
    for(char c:r) rf[c-'a']++;


    for(int i=0;i<26;i++){
        int mini = min(sf[i],rf[i]);
        sf[i]-=mini;
        rf[i]-=mini;
    }

    int ans = 0;

    for(int i:sf) ans+=i;

    cout<<ans;
}

int main() {
    onlinejudge();
        solve();
    return 0;
}