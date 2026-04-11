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

vi get(ll x){
    vi d;
    while(x){
        d.emplace_back(x % 2);
        x /= 2;
    }
    return d;
}

ll go(vi d, int k){
    vi blo;
    int n = sz(d);
    int one = true;
    int cnt = 0;
    rep(i, 0, n){
        if(one){
            if(d[i]) cnt++;
            else{
                blo.emplace_back(cnt); 
                cnt = 1;
                one = false;    
            }
        }else{
            if(d[i]){
                blo.emplace_back(cnt); 
                cnt = 1;
                one = true;
            }else cnt++;
        }
    }
    blo.emplace_back(cnt);

    int best = 0;
    int m = sz(blo) / 2;
    for(int mask = 0; mask < (1 << m); mask++){
        int used = 0;

        int ans = 0;
        vi cur;
        int sm = 0;
        for(int i = 0; i < sz(blo); i++){
            if(i % 2 == 0) sm += blo[i];
            else{
                if(mask & (1 << (i / 2))){
                    sm += blo[i];
                    used += blo[i];
                }
                else{
                    cur.emplace_back(sm);
                    sm = 0;
                }
            }
        }
        if(sm) cur.emplace_back(sm);

        sort(all(cur));
        int sobra = k - used;
        while(sz(cur)){
            if(sobra <= 0) break;
            ans += cur.back();
            cur.pop_back();
            sobra--;
        }
        ans += sobra;
        best = max(best, ans);
    }
    return best;
}


void solve(){
    int n, k; cin >> n >> k;
    auto d = get(n);
    reverse(all(d));

    int ze = count(all(d), 0);
    if(k > ze) cout << sz(d) - ze + k - 1 << "\n";
    else cout << go(d, k)  << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}