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

    int n, len, c; cin >> n >> len >> c;
    vi step(c), cnt(c);
    rep(i, 0, c) cin >> step[i] >> cnt[i];

    rep(i, 0, n){
        bool ok = true;
        rep(k, 0, c){
            int ans = 0;
            rep(j, 0, len) if((1 + i + j) % step[k] == 0) ans++;
            if(ans != cnt[k]){ ok = false; break; }
        }
        if(ok){
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}