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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vi a(n + 1);
    vi ans;

    rep(i, 0, k){
        int x, y; cin >> x >> y;
        a[x]++;
        if(a[x] == m) ans.emplace_back(x);
    }

    rep(i, 0, sz(ans)) cout << ans[i] << " ";
    cout << '\n';
}