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

vi a;
int n;
void go(){
    set<int> st;
    rep(i, 0, n) st.insert(i);
    rep(i, 1, n + 1) if(a[i] != -1) st.erase(a[i]);

    rep(i, 1, n + 1) if(a[i] != -1){
        int fs = *st.begin();
        a[i] = fs;
        st.erase(fs);
    }

    rep(i, 1, n + 1) cout << a[i] << " "; cout << "\n";
}

void solve(){
    int m; cin >> n >> m;
    vi l(m), r(m);
    rep(i, 0, m) cin >> l[i] >> r[i];
    
    a.assign(n + 1, -1);
    // mex 0
    {
        int lans = 1, rans = n;
        rep(i, 0, m){
            lans = max(lans, l[i]);
            rans = min(rans, r[i]);
        }
        if(lans <= rans){
            a[lans] = 0;
            go();
            return; 
        }
    }

    // mex 1
    {
        a.assign(n + 1, -1);
        vi cnt(n + 1);
        rep(i, 0, m){
            rep(j, l[i], r[i] + 1) cnt[j]++;
        }
        rep(i, 1, n + 1) if(cnt[i] == 0){
            a[i] = 0;
            go();
            return;
        }

        a.assign(n + 1, 0);
        rep(i, 1, n + 1){
            int lasn = 1, rans = n;
            rep(j, 0, m){
                if(l[j] <= i && r[j] >= i){
                    lans = max(lans, l[j]);
                    rans = min(rans, r[j]);
                }
            }
            if(rans - lans >= 2){
                a[lans] = 0;
                a[lans + 1] = 1;
                go();
                return;
            }
        }
    }

    // mex 2
    {
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}