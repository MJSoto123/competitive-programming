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

const int MX = 729;
const int MXVAL = 6561;
int get(const vi &a){
    int val = 0;
    rep(i, 0, 8){
        val *= 3;
        val += ((a[7 - i] + 3000000) % 3);
    }
    return val;
}

vvi trans;
void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;

    vvi frec(n + 1, vi(8));
    rep(i, 0, n){
        frec[i + 1] = frec[i];
        frec[i + 1][a[i]]++;
    }
    // rep(i, 0, n + 1) rep(j, 0, 8) cout << frec[i][j] << " \n"[j == 7];

    ll ans = 0;
    auto apply = [&](const vi &t){
        vi alive(MXVAL);
        int fs = -1;
        rep(i, 0, n){
            while(fs + 1 <= i){
                bool ok = 1;
                rep(j, 0, 8) if(frec[fs + 1][j] + t[j] > frec[i + 1][j]) ok = 0;
                if(!ok) break;

                // act
                int val = get(frec[fs + 1]);
                alive[val]++;
                fs++;
            }
            
            vi contri = frec[i + 1];
            rep(j, 0, 8) contri[j] -= t[j];
            // a veces esta cagada es negativo p mierda xd

            // contrib
            int val = get(contri);
            ans += alive[val];
        }
    };

    for(auto t : trans) apply(t);
    cout << ans << "\n";
}

vi dig(int x){
    vi d;
    rep(i, 0, 6){
        d.emplace_back(x % 3);
        x /= 3;
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    rep(i, 0, MX){
        vi op = dig(i);
        vi t(8, 0);

        rep(i, 0, 6){
            rep(j, 0, op[i]){
                t[i]++; t[i + 1]++; t[i + 2]++;
            }
        }
        trans.emplace_back(t);
    }

    // rep(i, 0, MX) rep(j, 0, 8) cout << trans[i][j] << " \n"[j == 7];

    int tt; cin >> tt;
    while(tt--) solve();
}