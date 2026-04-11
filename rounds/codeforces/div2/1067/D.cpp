#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void print(vi a){
    for(auto x : a) cerr << x << " ";
    cerr << "\n";
    cerr << "\n";
}

vii zero(vi a){
    vii ret;
    int n = sz(a);
    rep(i, 0, n){
        // print(a);
        if(a[i] == 0) continue;
        int l = i, r = -1;
        int id = i + 1;
        while(id <= n - 1 && a[id]) id++;
        if(id != i + 1){
            ret.emplace_back(l, id - 1);
            rep(j, l, id) a[j] ^= 1; //i xd
            continue;
        } 

        rep(j, i + 1, n) if(a[j] == 1){ r = j; break; }
        if(r != -1){
            ret.emplace_back(l, r);
            rep(j, l, r + 1) a[j] ^= 1;
            continue;
        }

        if(i >= n - 2){
            ret.emplace_back(0, i - 1);
            ret.emplace_back(0, i);
            break;
        }
        ret.emplace_back(i + 1, n - 1);
        ret.emplace_back(i, n - 1);
    }
    return ret;
}

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vi ss, tt;
    rep(i, 0, sz(s)) ss.emplace_back(s[i] == '1');
    rep(i, 0, sz(t)) tt.emplace_back(t[i] == '1');

    auto ops = zero(ss);
    auto extra = zero(tt);
    reverse(all(extra));
    for(auto x : extra) ops.emplace_back(x);

    cout << sz(ops) << "\n";
    for(auto [l, r] : ops) cout << l + 1 << " " << r + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}   