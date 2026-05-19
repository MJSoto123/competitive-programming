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
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int dir = a[1] - a[0];
    bool ok = false;
    if(dir > 0){
        rep(i, 2, n){
            if(a[i] - a[i - 1] < 0){
                ok = true;
                rep(j, i + 1, n){
                    if(a[j] - a[j - 1] > 0) ok = false;
                }
                break;
            }
        }
    }else{
        rep(i, 2, n){
            if(a[i] - a[i - 1] > 0){
                ok = true;
                rep(j, i + 1, n){
                    if(a[j] - a[j - 1] < 0) ok = false;
                }
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
}