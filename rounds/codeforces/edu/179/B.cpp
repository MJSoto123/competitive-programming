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

vector<int> fib = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};

void solve(){
    int n, m; cin >> n >> m;

    vector<int> dims = {fib[n], fib[n], fib[n - 1] + fib[n]};

    for(int i = 0; i < m; i++){
        vector<int> now(3); 
        for(int j = 0; j < 3; j++) cin >> now[j];
        sort(now.begin(), now.end());

        bool ok = true;
        for(int j = 0; j < 3; j++) if(now[j] < dims[j]) ok = false;

        if(ok) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}