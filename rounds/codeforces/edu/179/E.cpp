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
    string s; cin >> s;

    vector<vector<set<int>>> g(3, vector<set<int>>(3));
    for(int i = 0; i < m; i++){
        char u, v; cin >> u >> v;
        g[u - 'a'][v - 'a'].insert(i);
    }

    for(int i = 0; i < n; i++){
        if(s[i] == 'a') continue;
        if(s[i] == 'b'){
            if(g[1][0].size()){
                g[1][0].erase(g[1][0].begin());
                s[i] = 'a';
            }
            else if(g[1][2].size()){
                auto p = g[2][0].upper_bound(*g[1][2].begin());
                if(p != g[2][0].end()){
                    g[1][2].erase(g[1][2].begin());
                    g[2][0].erase(p);
                    s[i] = 'a';
                }
            }
        }

        if(s[i] == 'c'){
            if(g[2][0].size()){
                g[2][0].erase(g[2][0].begin());
                s[i] = 'a';
            }
            else if(g[2][1].size()){
                auto p = g[1][0].upper_bound(*g[2][1].begin());
                if(p != g[1][0].end()){
                    g[2][1].erase(g[2][1].begin());
                    g[1][0].erase(p); //xd
                    s[i] = 'a';
                }else{
                    g[2][1].erase(g[2][1].begin());
                    s[i] = 'b';
                }
            }
        }
    }
    cout << s << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}