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

void solve(){
    int n, k; cin >> n >> k;
    set<int> a;
    rep(i, 0, n){
        int x; cin >> x;
        a.insert(x);
    }

    vi b;
    set<int> vis;
    set<int> ori = a;
    while(sz(a)){
        int now = *a.begin();
        int mul = k / now;
        b.emplace_back(now);

        for(int i = now; i <= k; i += now){
            if(!ori.count(i)){ cout << "-1\n"; return; }
            if(a.count(i)) a.erase(i);
        }
    }

    cout << sz(b) << "\n";
    for(auto x : b) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}