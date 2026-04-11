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

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 0;
    rep(i, 0, n){
        if(a[i] == 1) break;
        l++;
    }

    int r = n;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == 1) break;
        r--;
    }

    cout << max(r - l - 1, 0) << "\n";
}