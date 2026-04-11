#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


void solve(){
    int n; cin >> n;
    vvi graph(n + 1); 
    for(int v = 2; v <= n; v++) {
        int u; cin >> u;
        graph[u].emplace_back(v);
    }

    vi d(n + 1, 0);

    auto get = [&](int x){
        int exp = 0;
        int pot = 1;
        while(pot < x) {exp++; pot *= 2;} 
        return exp;
    };
    
    function<void(int)> dfs = [&](int u){
        int childens = 0;
        vi curr;
        for(auto v : graph[u]){
            childens++;
            if(d[v] == 0) dfs(v);
            curr.emplace_back(d[v]);
        }
        sort(curr.begin(), curr.end());
        if(!curr.size()) d[u] = 1;
        else if(curr.size() == 1) d[u] = curr.back() + 1;
        else{
            d[u] = curr.back() + 1;
            curr.pop_back();
            if(curr.size()){
                d[u] = max(d[u], get(childens - 1) + curr.back() + 1);
            }
        }
    };
    
    dfs(1);
    // for(int i = 1; i <= n; i++) cout << d[i] << " ";
    // cout << "\n";
    cout << d[1] - 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}