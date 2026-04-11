#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<int> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);
    vi scnt(26), tcnt(26);
    rep(i, 0, n) scnt[s[i] - 'a']++;
    rep(i, 0, m) tcnt[t[i] - 'a']++;

    vi have(26);
    rep(i, 0, 26){
        have[i] = tcnt[i] - scnt[i];
        if(have[i] < 0){ cout << "Impossible\n"; return; }
    }
    
    auto get = [&](char c){ return c - 'a'; };

    int id = 0;
    string ans = "";
    rep(i, 0, 26){
        while(id < n && get(s[id]) < i + 1) ans += s[id++];
        rep(j, 0, have[i]) ans += char('a' + i);
    }
    while(id < n) ans += s[id++];
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}