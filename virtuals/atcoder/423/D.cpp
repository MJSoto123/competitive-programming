#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define int long long
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vvi a(n, vi(3));
    rep(i, 0, n) rep(j, 0, 3) cin >> a[i][j];

    priority_queue<pii, vii, greater<pii>> q;
    rep(i, 0, n) q.emplace(a[i][0], i);

    priority_queue<pii, vii, greater<pii>> in;
    int cntin = 0;
    int tnow = 0;

    vi ans(n);
    while(sz(q)){
        auto [t, id] = q.top(); q.pop();
        // cerr << "try " << t << " " << a[id][2] << "\n"; 
        while(sz(in)){
            auto [out, id2] = in.top();
            if(out <= tnow){
                cntin -= a[id2][2];
                in.pop();
                // cerr << "time " << out << " " << a[id2][2] << "\n";
            }else break;
        }
        
        int cnt = a[id][2], delay = a[id][1];
        if(!sz(in)){
            // cerr << "vacio puse " << tnow + delay << " " << a[id][2] << "\n";
            tnow = max(tnow, t);
            in.emplace(tnow + delay, id);
            ans[id] = tnow;
        }
        else{
            while(k - cntin < cnt){
                auto [out, id2] = in.top(); in.pop();
                // cerr << "sacando " << out << " " << a[id2][2] << "\n";
                tnow = out;
                cntin -= a[id2][2];
            }
            tnow = max(tnow, t);
            in.emplace(tnow + delay, id);
            // cerr << "puse " << tnow + delay << " " << a[id][2] << "\n";
            ans[id] = tnow;
        }
        cntin += cnt;
        // cerr << "ahora dentro " << cntin << "\n\n";
    }

    rep(i, 0, n) cout << ans[i] << "\n";
}