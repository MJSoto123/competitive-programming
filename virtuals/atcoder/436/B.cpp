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

    int n; cin >> n;
    vvi a(n, vi(n));

    a[0][(n - 1) / 2] = 1;
    int r = 0, c = (n - 1) / 2;
    rep(i, 1, n * n){
        if(a[(r - 1 + n) % n][(c + 1) % n] == 0){
            r = (r - 1 + n) % n;
            c = (c + 1) % n;
            a[r][c] = i + 1;
        }else{
            r = (r + 1) % n;
            a[r][c] = i + 1;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n) cout << a[i][j] << " ";
        cout << "\n";
    }
}