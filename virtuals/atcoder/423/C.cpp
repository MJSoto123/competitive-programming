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

    int n, pos; cin >> n >> pos;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int fs = -1, ls = -1;
    rep(i, 0, n){
        if(a[i] == 0){
            if(fs == -1) fs = i;
            ls = i;
        }
    }

    if(fs == -1){ cout << "0\n"; return 0; }
    int ans = 0;
    if(fs < pos) {
        ans += pos - fs;
        for(int i = fs; i < pos; i++) ans += (a[i] == 1);
    }

    if(ls >= pos) {
        ans += ls - pos + 1;
        for(int i = pos; i <= ls; i++) ans += (a[i] == 1);
    }

    cout << ans << "\n";
}