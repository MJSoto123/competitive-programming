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

int query(const vi &a){
    cout << "? " << sz(a) << " ";
    for(auto x : a) cout << x << " ";
    cout << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    int m = 2 * n;
    vi a(m + 1);
    vi pos;
    rep(i, 1, m + 1){
        pos.emplace_back(i);
        int ans =query(pos);
        if(ans != 0){
            a[i] = ans;
            pos.pop_back();
        }
    }


    pos.clear();
    rep(i, 1, m + 1) if(a[i] != 0) pos.emplace_back(i);
    for(int i = m; i >= 1; i--){
        if(a[i] != 0) continue;
        pos.emplace_back(i);
        int ans =query(pos);
        if(ans != 0){
            a[i] = ans;
            pos.pop_back();
        }
    }

    cout << "! ";
    rep(i, 1, m + 1) cout << a[i] << " ";
    cout << endl;   
}

int main(){

    int tt; cin >> tt;
    while(tt--) solve();
}