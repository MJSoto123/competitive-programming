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
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    
    rep(i, 0, n){
        ll ch = -1;
        rep(j, 0, n - i){
            ll inf = a[j];
            bool can = true;
            ll lcm = 1;
            rep(k, 0, n - i){
                if(j == k) continue;
                ll g = gcd(a[j], a[k]);
                ll g2 = gcd(lcm, g);
                if(inf / g < lcm / g2){
                    can = false;
                    break;
                }
                lcm = lcm / g2 * g;
            }
            if(can && lcm < a[j]){
                ch = j;
                break;
            }
        }
        if(ch == -1){ cout << "No\n"; return 0; }
        swap(a[ch], a[n - 1 - i]);
    }

    cout << "Yes\n";
    rep(i, 0, n) cout << a[i] << " "; cout << "\n";
}