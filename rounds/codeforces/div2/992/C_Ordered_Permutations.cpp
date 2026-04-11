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
    int n;
    ll k; cin >> n >> k;
    if(n <= 40 && k > (1 << (n - 1))) { cout << "-1\n"; return;}
    vi a;
    ll k2 = k;
    while(k2){
        a.emplace_back(k2 % 2);
        k2 /= 2;
    }
    while(a.size() < n) a.emplace_back(0);
    reverse(a.begin(), a.end());

    for(auto x : a) cout << x << " ";
    cout << "\n";

    vi p;
    for(int i = 0; i < n; i++) p.emplace_back(i + 1);

    vi rev;
    for(int i = min(39, n - 1); i >= 1; i--){
        ll x = (1LL << (i - 1));
        cout << "check: " << i << " " << x << " ";
        if(k > x) {
            cout << "mayor ";
            k -= x;
            rev.emplace_back(i);
        }
        cout << "\n";
    }

    reverse(rev.begin(), rev.end());

    for(auto x : rev){
        reverse(p.begin() + n - x - 1, p.end());
        cout << "rev: " << x << "\n";
        for(auto x : p) cout << x << " ";
        cout << "\n";
    }

    for(auto x : p) cout << x << " ";
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