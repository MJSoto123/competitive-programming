#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    string s; cin >> s;
    int n = sz(s);
    
    vvi g(n + 2);
    vi in(n + 2);

    rep(i, 0, n){
        if(s[i] == '*'){
            g[i + 1].emplace_back(i);
            g[i + 1].emplace_back(i + 2);

            in[i]++; in[i + 2]++;
        }
        
        if(s[i] == '>'){
            g[i + 1].emplace_back(i + 2);
            in[i + 2]++;
        }
        if(s[i] == '<'){
            g[i + 1].emplace_back(i);
            in[i]++;
        }
    }

    // rep(i, 0, n + 2){
    //     for(auto v : g[i]) cerr << i << " " << v << "\n";
    // }

    queue<int> q;
    rep(i, 0, n + 2) if(in[i] == 0) q.emplace(i);

    vi ord;
    while(sz(q)){
        auto u = q.front(); q.pop();
        ord.emplace_back(u);
        for(auto v : g[u]){
            in[v]--;
            if(in[v] == 0) q.emplace(v);
        }
    }

    if(sz(ord) != n + 2){ cout << "-1\n"; return; }
    vi dp(n + 2);
    for(auto u : ord){
        for(auto v : g[u]){
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    cout << *max_element(all(dp)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}