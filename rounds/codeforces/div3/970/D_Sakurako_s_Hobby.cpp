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
    vi p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) p[i] = p[i] - 1;
    string s; cin >> s;

    map<int, int> group;
    vi ans;
    int idx = 0;
    vi vis(n, 0);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        group[i] = idx;
        int black = 0;
        vis[i] = 1;
        if(s[i] == '0') black++;
        
        int u = p[i];
        while(u != i){
            group[u] = idx;
            vis[u] = 1;
            if(s[u] == '0') black++;
            u = p[u];
        }
        ans.emplace_back(black);
        idx++;
    }

    // for(auto [u, g] : group) cout << u << " " << g << "\n";

    for(int i = 0; i < n; i++){
        cout << ans[group[i]] << " ";
    }
    cout << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}