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

    int n, q; cin >> n >> q;
    vl a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    vl sm(n + 1), smidx(n + 1), sm2(n + 1);
    rep(i, 1, n + 1){
        sm[i] = sm[i - 1] + a[i];
        smidx[i] = smidx[i - 1] + a[i] * i;
        sm2[i] = sm2[i - 1] + a[i] * i * i;
    }

    rep(qq, 0, q){
        int l, r; cin >> l >> r;
        ll x = sm[r] - sm[l - 1];
        ll y = smidx[r] - smidx[l - 1];
        ll z = sm2[r] - sm2[l - 1];

        cout << x * (r + 1) * (1 - l) + y * (l + r) - z << "\n";
    }
}