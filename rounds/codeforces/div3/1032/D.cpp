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

void print(vi a, string s){
    cout << s << ": ";
    for(auto x : a) cout << x << " ";
    cout << "\n";
}

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vii ops;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j >= 1 && a[j - 1] > a[j]){
            ops.emplace_back(1, j - 1);
            swap(a[j - 1], a[j]);
            j--;
        }
    }

    for(int i = 0; i < n; i++){
        int j = i;
        while(j >= 1 && b[j - 1] > b[j]){
            ops.emplace_back(2, j - 1);
            swap(b[j - 1], b[j]);
            j--;
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            ops.emplace_back(3, i);
            swap(a[i], b[i]);
        }
    }

    // print(a, "a");
    // print(b, "b");
    
    cout << ops.size() << "\n";
    for(auto [x, y] : ops) cout << x << " " << y + 1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}