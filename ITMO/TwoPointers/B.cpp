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

    int n, m; cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    
    vi ans(m);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] >= b[j]){
            ans[j] = i;
            j++;
        }else i++;
    }

    while(j < m) ans[j++] = i;
    for(auto x : ans) cout << x << " "; cout << "\n";
}