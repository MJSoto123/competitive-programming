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

const int N = 1e5 + 5;
int n;
vi g[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(u, 0, n - 1){
        int v; cin >> v;
        g[u + 1].emplace_back(v);
        g[v].emplace_back(u + 1);
    }

    
}