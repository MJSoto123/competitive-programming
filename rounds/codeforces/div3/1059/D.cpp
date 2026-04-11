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

ll query(int t, int l, int r){
    cout << t << " " << l << " " << r << endl;
    ll sm; cin >> sm;
    return sm;
}

void solve(){
    int n; cin >> n;   
    int tot1 = n * (n + 1)  / 2;
    int tot2 = query(2, 1, n);
    int len = tot2 - tot1;

    int l = 0, r = n + 1;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(query(2, 1, mid) > query(1, 1, mid)) r = mid;
        else l = mid;
    }

    cout << "! " << r << " " << r + len - 1 << endl;
}

int main(){

    int tt; cin >> tt;
    while(tt--) solve();
}