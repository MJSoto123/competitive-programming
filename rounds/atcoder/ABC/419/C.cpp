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
    vvi a(2, vi(n));
    
    for(int i = 0; i < n; i++) cin >> a[0][i] >> a[1][i];

    vi ch(2);
    for(int i = 0; i < 2; i++){
        int mn = *min_element(all(a[i]));
        int mx = *max_element(all(a[i]));
        ch[i] = (mx + mn)/ 2;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int now = 0;
        for(int j = 0; j < 2; j++) now = max(now, abs(a[j][i] - ch[j]));
        ans = max(ans, now);
    }

    cout << ans << "\n";
}