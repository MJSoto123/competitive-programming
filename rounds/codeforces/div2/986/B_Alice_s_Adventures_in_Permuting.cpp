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
#define pii pair<int, int>
#define vl vector<long long>
#define vii vector<pair<int, int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) {while (b != 0) swap(b, a %= b); return a;}

void solve(){
    ll n, b, c;
    cin >> n >> b >> c;
    if (c >= n) { cout << n << "\n"; return; }
    if(b == 0 && c < n - 2) {cout << "-1\n"; return; }
    
    ll k = 1;
    if(b != 0) k = (n - c - 1) / b + 1;
    k = max(0LL, k);
    cout << n - k << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}