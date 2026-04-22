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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(nullptr));

    int n, p; cin >> n >> p;

    cout << 1 << "\n";

    vvi g(n);
    int ed = 0;
    rep(u, 0, n){
        rep(v, 0, n){
            if(u == v) continue;
            if(u > v) continue;

            if(rand() % p) continue;
            g[u].emplace_back(v);
            ed++;
        }
    }

    cout << n << " " << ed << "\n";
    rep(u, 0, n){
        for(auto v : g[u]) cout << u + 1 << " " << v + 1 << "\n";
    }
}