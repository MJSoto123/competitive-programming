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

    int a, b, x, y; cin >> a >> b >> x >> y;
    double ans = 1.0 * a / (1.0 * b);

    double noA = 1.0 * (b - a) / (1.0 * b);
    double noB = 1.0 * (y - x) / (1.0 * y);
    double geo = 1.0 / (1.0 - (noA * noB));

    cout << fixed << setprecision(7);
    cout << ans * geo << "\n";
}