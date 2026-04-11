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

ll solve(ll n){
    cout << n << "\n";
    ll ans = 0;
    for(int b = 1; b <= n; b++){
        for(int a = 1; a <= n; a++){
            if(a == b) continue;
            for(int c = 1; c <= n; c++){
                if(c == a) continue;
                if(c == b) continue;
                if(a % b == c) {
                    cout << a << " " << b << " " << c << "\n";
                    ans++;
                }
            }
        }
    }
    cout << "\n";
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    vl a(n + 1);
    for(ll i = 1; i <= n; i++) a[i] = solve(i);

    for(int i = 1; i < n; i++) cout << a[i + 1] - a[i] << " ";
}