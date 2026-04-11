#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, fro, sam; cin >> n >> fro >> sam;
    vi a(n, -1), b(n, -1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vi pos(n + 1);
    for(int i = 0; i < n; i++) pos[b[i]] = i;


    ll ans = 5e18;
    for(int i = 0; i < n; i++){
        ll cost = 1LL * i * fro + 1LL * pos[a[i]] * fro;
        int pnow = pos[a[i]];
        // cout << "from " << i << "[" << a[i] << "]";
        while(i + 1 < n){
            if(pos[a[i + 1]] != pnow + 1) break;
            i++;
            pnow++;
        }
        cost = max(cost, 1LL * (n - i - 1) * sam + 1LL * (n - pnow - 1) * sam);
        // cout << " to " << i <<"[" << a[i] << "] => " << cost << "\n";
        ans = min(ans, cost);
    }

    cout << ans << "\n";
}