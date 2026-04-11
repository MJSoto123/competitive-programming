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

int mod;
int add(ll a, ll b){ return (a + b > mod ? a + b - mod : a + b); }
int mul(ll a, ll b){ return (a * b) % mod; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n >> mod;
    int n1 = n / 2;
    int n2 = n - n1;
    vi m1(n1), m2(n2);
    for(int i = 0; i < n1; i++) cin >> m1[i], m1[i] %= mod;
    for(int i = 0; i < n2; i++) cin >> m2[i], m2[i] %= mod;

    auto f = [&](vi &v, int nn){
        vi sm;
        for(int mask = 0; mask < (1 << nn); mask++){
            int now = 0;
            for(int i = 0; i < nn; i++) if(mask & (1 << i)) now = add(now, v[i]);
            sm.emplace_back(now);
        }
        return sm;
    };

    vi sm1 = f(m1, n1);
    vi sm2 = f(m2, n2);

    sort(all(sm2));
    int ans = 0;

    for(auto val : sm1){
        int need = mod - 1 - val;
        int l = -1, r = sz(sm2);
        while(r - l > 1){
            int mid = l + r >> 1;
            if(sm2[mid] <= need) l = mid;
            else r = mid;
        }
        if(l == -1) continue;
        ans = max(ans, add(val, sm2[l]));
    }

    cout << ans << "\n";
}