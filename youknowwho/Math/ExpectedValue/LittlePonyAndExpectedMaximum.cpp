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

double binpow(double a, int exp){
    double res = 1.0;
    while(exp){
        if(exp & 1) res *= a;
        a *= a;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(5);

    int n, m; cin >> m >> n;

    double ans = 0;
    double lst = 0;

    rep(i, 1, m + 1){
        double p = binpow(double(i) / double(m), n);
        ans += ((p - lst) * double(i));
        lst = p;
    }

    cout << ans << "\n";
}