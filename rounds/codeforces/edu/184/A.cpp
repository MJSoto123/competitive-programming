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
    int n, a; cin >> n >> a;
    vi v(n);
    rep(i, 0, n) cin >> v[i];

    int a1 = 0, a2 = 0;
    rep(i, 0, n){
        if(v[i] < a) a1++;
        if(v[i] > a) a2++;
    }

    if(a1 > a2) cout << a - 1 << "\n";
    else cout << a + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}