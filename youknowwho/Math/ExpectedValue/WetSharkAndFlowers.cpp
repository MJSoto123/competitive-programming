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
    int n, p; cin >> n >> p;
    vi L(n + 1), R(n + 1);
    rep(i, 0, n) cin >> L[i] >> R[i];

    vector<double> P(n + 1);
    rep(i, 0, n){
        int low = (L[i] + p - 1) / p;
        int high = R[i] / p;
        if(low > high) P[i] = 0;
        int have = high - low + 1;
        P[i] = double(have) / double(R[i] - L[i] + 1);
    }
    P[n] = P[0];
    
    double ans = 0;
    rep(i, 0, n){
        double here = 1.0 - (1.0 - P[i]) * (1.0 - P[i + 1]);
        ans += 2000 * here;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(7);

    solve();   
}