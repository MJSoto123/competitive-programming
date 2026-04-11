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

    sort(a.begin(), a.end());
    ll sm = accumulate(a.begin(), a.end(), 0LL);
    ll mx = max_element(a.begin(), a.end()) - a.begin();

    ll l = -1, r = 8e18;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        ll prom = sm + mid;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i == mx) continue;
            if(1LL * a[i] * 2 * n < prom) cnt++;
        }
        if(cnt >= n / 2 + 1) r = mid;
        else l = mid;
    }
    if(r == 8e18) r = -1;
    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}