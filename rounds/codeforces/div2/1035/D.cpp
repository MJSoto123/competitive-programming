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

int mod;
int add(ll a, ll b){ return (a + b) % mod; }
int mul(ll a, ll b){ return (a * b) % mod; }

void solve(){
    int n; cin >> n >> mod;
    vl dp(n + 1);
    // iesimo a remover
    for(int i = 1; i <= n; i++){
        vl ndp = dp;
                
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}