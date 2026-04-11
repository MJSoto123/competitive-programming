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
    ll n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    do{
        int sm = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int mn = n + 1;
                for(int k = i; k <= j; k++) mn = min(a[k], mn);
                sm += mn;
            }
        }
        if(sm != 84)  continue;
        for(auto x : a) cerr << x << " ";
        cerr << " => " << sm << "\n";
    } while (next_permutation(a.begin(), a.end()));
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}