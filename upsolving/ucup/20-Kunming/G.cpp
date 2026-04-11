#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) begin(x),end(x)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , ll> pii;
typedef vector<pii> vii;
typedef tuple<int , int, int> iii;
typedef vector<vi> vvi;
const ll INF = 1e18 + 10;
ll ans = INF;
void get_min(ll a, ll b, ll steps){
    if(steps >= ans) return;
    if(a == 0 && b == 0){
        ans = min(steps, ans);
        return;
    }
    if(a == 0 || b == 0){
        ans = min(steps + 1 , ans);
        return ;
    }
    ll gg = __gcd(a , b);
    get_min(a - gg , b , steps + 1);
    get_min(a, b - gg , steps + 1);
} 

void solve(){
    int a; cin >> a;
    ll b; cin >> b;
    ans = INF;
    get_min(a , b , 0);
    cout << ans << '\n';
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--)
        solve();
}
