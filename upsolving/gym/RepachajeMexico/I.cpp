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

string pat = "ULDR";
vi dx = {-1, -1, +1, +1};
vi dy = {+1, -1, -1, +1};

void solve(){
    ll n; cin >> n;

    ll sm = 0;
    ll add = 4;
    while(sm + add < n){
        sm += add;
        add += 4;
    }

    ll x = (add / 4), y = 0;
    ll mv = (add / 4);

    cout << mv << " " << x << " " << y << "\n";

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < mv; j++){
            if(sm == n){ cout << 4 * (x * x + y * y) << "\n"; return; }
            x += dx[i];
            y += dy[i];
            cout << x << ' ' << y << "\n";
            sm ++;
        }
    }
    cout << 4 * (x * x + y * y) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}