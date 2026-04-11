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
    int n; cin >> n;
    string s; cin >> s;
    s = '1' + s + '1';
    vi p(n + 1);
    int ini = 1;
    rep(i, 1, n + 1){
        if(s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1'){ cout << "NO\n"; return; }
        if(s[i] == '1'){
            p[i] = i;
            if(ini != i){
                rep(j, ini, i) p[j] = j + 1;
                p[i - 1] = ini;
            }
            ini = i + 1;
        }
    }

    if(ini != n + 1){
        rep(j, ini, n + 1) p[j] = j + 1;
        p[n] = ini;
    }
    cout << "YES\n";
    rep(i, 1, n + 1) cout << p[i] << " \n"[i == n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}