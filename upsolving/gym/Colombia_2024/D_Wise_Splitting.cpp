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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    vl a(n);
    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        a[u - 1] += w;
        a[v - 1] -= w;
    }

    vi order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j){
        return a[i] < a[j];
    });

    vector<tuple<int,int,ll>> ans;
    ll curr = -a[order[0]] + 100;
    int u = order[0];

    for(int v = 1; v < n; v++){
        ans.emplace_back(u + 1, order[v] + 1, curr);
        curr -= a[order[v]];
        u = order[v];
    }
    ans.emplace_back(order.back() + 1, order[0] + 1, 100);

    cout << ans.size() << "\n";
    for(auto [u, v, w] : ans) cout << u << " " << v << " " << w << "\n";

}