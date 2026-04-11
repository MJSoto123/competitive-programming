#include <bits/stdc++.h>
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

int add(ll a, ll b){ return ( a + b) % MOD; }
int mul(ll a, ll b){ return ( a * b) % MOD; }


void solve(){
    int n; cin >> n;
    vector<string> s;
    vvi ones(2, vi(n + 1));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            ones[i][j + 1] = ones[i][j] + (s[i][j] == '1');
        }
    }

    vvi a(2, vi(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++) a[i][j] = ones[i][j + 1] * 2 - (j + 1);
    }

    for(int i = 0; i < 2; i++) sort(a[i].begin(), a[i].end());

    ll sm = mul(n, mul(n, n + 1));
    auto b = a[0];
    auto c = a[1];

    for(int i = 0; i < n; i++){
        int l = -1, r = n; 
        while(r - l > 1){
            int mid = l + r >> 1;
            if(c[mid] + b[i] < 0) l = mid;
            else r = mid;
        }
        
    }

    cout << mul(sm, 500000004) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}