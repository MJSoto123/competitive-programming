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

    ll n, k; cin >> n >> k;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    multiset<ll> mx, mn;
    int l = 0;
    ll ans = 0;
    rep(r, 0, n){
        mx.emplace(a[r]);
        mn.emplace(a[r]);
        while(true){
            if(!sz(mx) || !sz(mn)) break;
            ll d = *prev(mx.end()) - *(mx.begin());
            if(d > k){
                mx.erase(mx.find(a[l]));
                mn.erase(mn.find(a[l]));
                l++;
            }else break;
        }
        ans += (r - l + 1);
    }

    cout << ans << '\n';
}   