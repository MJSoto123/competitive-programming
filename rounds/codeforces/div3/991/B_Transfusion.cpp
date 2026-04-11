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

    auto can = [&](vi &b){
        ll sm = accumulate(b.begin(), b.end(), 0LL);
        if(sm % b.size() != 0) return -1LL;

        ll x = sm / b.size();
        return x;
    };

    vi odd, even;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) even.emplace_back(a[i]);
        else odd.emplace_back(a[i]);
    }
    ll ok1 = can(even);
    ll ok2 = can(odd);
    if(ok1 == -1 || ok2 == -1 || ok1 != ok2) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}