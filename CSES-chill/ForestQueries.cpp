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

    int n, q; cin >> n >> q;
    vvi a(n, vi(n));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, n) a[i][j] = (s[j] == '*');
    }

    vvi pre(n + 1, vi(n + 1));
    rep(i, 0, n) rep(j, 0, n) pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + a[i][j];

    rep(i, 0, q){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << pre[r2][c2] - pre[r1 - 1][c2] - pre[r2][c1 - 1] + pre[r1 - 1][c1 - 1] << "\n";
    }
}