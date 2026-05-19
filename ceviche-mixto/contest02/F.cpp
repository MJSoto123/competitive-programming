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


const int N = 500 + 5;
int X[N], Y[N];

ll dist(int i, int j){ 
    ll dx = X[j] - X[i];
    ll dy = Y[j] - Y[i];
    return dx * dx + dy * dy;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n) cin >> X[i] >> Y[i];

    if(n == 2){ cout << 2 << "\n"; return 0; }

    long double ans = 5e10;
    // solo 1
    rep(i, 0, n){
        ll rad = 0;
        rep(j, 0, n) rad = max(rad, dist(i, j));
        ans = min(ans, sqrtl(rad));
    }

    // con 2
    rep(i, 0, n){
        ll rad1 = 0;
        rep(j, 0, n){
            ll rad2 = 0;
            
            if(i == j) continue;
            rep(k, 0, n){
                ll d1 = dist(i, k);
                ll d2 = dist(j, k);
                if()
            }
        }
    }
}