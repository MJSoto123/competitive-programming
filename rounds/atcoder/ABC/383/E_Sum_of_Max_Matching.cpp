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
#define int long long
using namespace std;



const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges(m);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[i] = {w, u, v};
    }

    vi a(k), b(k);
    for(int i = 0; i < k; i++) { cin >> a[i]; a[i]--; }
    for(int i = 0; i < k; i++) { cin >> b[i]; b[i]--; }

    sort(edges.begin(), edges.end());
    vi order(n, -1), mn;
    int curr = 0, cnt = -1;
    for(int i = 0; i < m; i++){
        int u, v, w; tie(w, u, v) = edges[i];
        // cout << "w, u, v: " << w << " " << u << " " << v << "\n";
        if(order[u] == -1 || order[v] == -1) {
            curr = max(curr, w);
            mn.emplace_back(curr);
            cnt++;
        }
        if(order[u] == -1) order[u] = cnt;
        if(order[v] == -1) order[v] = cnt;
    }

    sort(b.begin(), b.end(), [&](int i, int j){
        return order[i] < order[j];
    });

    sort(a.begin(), a.end(), [&](int i, int j){
        return order[i] < order[j];
    });

    ll sm = 0;
    for(int i = 0; i < k; i++){
        // cout << order[a[i]] << " " << order[b[i]] << " ";
        // cout << mn[max(order[a[i]], order[b[i]])] << "\n";
        sm += mn[max(order[a[i]], order[b[i]])];
        
    }
    cout << sm << "\n";
}