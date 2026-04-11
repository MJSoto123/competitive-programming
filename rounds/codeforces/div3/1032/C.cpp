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

void solve(){
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));

    int mx = 0;
    vii pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] > mx){
                mx = a[i][j];
                pos.clear();
            }
            if(mx == a[i][j]) pos.emplace_back(i, j);
        }
    }
    if(pos.size() == 2){ cout << mx - 1<< "\n"; return; }
        
    map<int, int> row;
    map<int, int> col;
    for(auto [x, y] : pos){
        row[x]++;
        col[y]++;
    }

    vi r, c;
    int cnt = 0;
    for(auto [k, val] : row){
        if(val > cnt){
            cnt = val;
            r.clear();
        }
        if(val == cnt) r.emplace_back(k);
    }
    cnt = 0;
    for(auto [k, val] : col){
        if(val > cnt){
            cnt = val;
            c.clear();
        }
        if(val == cnt) c.emplace_back(k);
    }

    // cout << "r: ";
    // for(auto x : r) cout << x << " ";
    // cout << "\n";

    // cout << "c: ";
    // for(auto y : c) cout << y << " ";
    // cout << "\n";

    if(r.size() > 1 && c.size() > 1){ cout << mx << "\n"; return; }
    if(r.size() <= 1 && c.size() <= 1){
        for(auto ri : r){
            for(auto ci : c){
                int del = 0;
                for(auto [x, y] : pos){
                    if(x == ri || y == ci) del++;
                }
                if(del == pos.size()){ cout << mx - 1 << "\n"; return; } 
            }
        }
        cout << mx << "\n"; return;
    }

    if(r.size() == 1){
        set<int> nc;
        for(auto [x, y] : pos){
            if(x != r[0]) nc.insert(y);
        }

        if(nc.size() > 1) cout << mx << '\n';
        else cout << mx - 1 << "\n";
        return;
    }

    if(c.size() == 1){
        set<int> nr;
        for(auto [x, y] : pos){
            if(y != c[0]) nr.insert(x);
        }

        if(nr.size() > 1) cout << mx << '\n';
        else cout << mx - 1 << "\n";
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}