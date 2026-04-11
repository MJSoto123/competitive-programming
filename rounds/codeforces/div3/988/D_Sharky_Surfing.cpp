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
    int n, m, d; cin >> n >> m >> d;
    vi l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vi pos(m), power(m);
    for(int i = 0; i < m; i++) cin >> pos[i] >> power[i];

    priority_queue<int> dispo;
    ll step = 1;
    int idx = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int jump = (r[i] - l[i] + 1) + 1;
        while(idx < m && pos[idx] < l[i]) dispo.emplace(power[idx++]);
        if(step >= jump) continue;
        while(step < jump){
            if(dispo.empty()) { cout << "-1\n"; return;}
            step += dispo.top(); 
            cnt++;
            dispo.pop();
        }        
        // cout << step << " saltando " << l[i] << " " << r[i] << "\n";
    }
    cout << cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}