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
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vi mx(n, a[0]);
    vi mn(n, a.back());
    for(int i = 1; i < n; i++) mx[i] = max(a[i], mx[i - 1]);
    for(int i = n - 2; i >= 0; i--) mn[i] = min(a[i], mn[i + 1]);

    vi ans(n, 0);
    ans[n - 1] = mx[n - 1]; 
    for(int i = n - 2; i >= 0; i--){
        if(mx[i] > mn[i + 1]) ans[i] = max(mx[i], ans[i + 1]);
        else ans[i] = mx[i];
    }
    for(auto x : ans) cout << x << " ";
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