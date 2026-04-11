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
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) { cout << "1\n"; return; }
    
    
    ll ans = 2e18;
    auto get = [&](vl wtf){
        sort(wtf.begin(), wtf.end());
        // cout << "wtf: ";
        // for(auto x : wtf) cout << x << " ";
        // cout << "\n";
        vl d;
        for(int i = 1; i < wtf.size(); i += 2) d.emplace_back(wtf[i] - wtf[i - 1]);
        // cout << "d: ";
        // for(auto x : d) cout << x << " ";
        // cout << "\n";
        sort(d.begin(), d.end());
        ans = min(ans, d.back());
        return;
    };

    if(n % 2 == 0) { 
        get(a);
        cout << ans << "\n"; 
        return; 
    }

    
    for(int i = 0; i < n; i++){
        // * a[i]
        a.emplace_back(a[i] - 1);
        get(a);
        a.pop_back();

        // a[i] *
        a.emplace_back(a[i] + 1);
        get(a);
        a.pop_back();
        // cout << "ans: " << ans << "\n\n"; 
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}