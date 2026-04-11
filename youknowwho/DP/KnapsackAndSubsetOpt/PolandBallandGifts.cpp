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

const int N = 1e6 + 1;
bitset<N> dp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;

    vi cyc;
    vi vis(n);
    rep(i, 0, n){
        if(!vis[i]){
            int len = 1;
            int u = a[i];
            while(u != i){
                vis[u] = 1;
                u = a[u];
                len++;
            }
            cyc.emplace_back(len);
        }
    }
    sort(all(cyc));

    int cnt = 0, sobra = 0;
    for(auto x : cyc){
        if(x % 2) sobra++;
        cnt += (x / 2);
    }
    int mx = 0;
    if(cnt >= k) mx = k * 2;
    else mx = cnt * 2 + min(sobra, (k - cnt));

    int lim = 80;
    vi c(lim + 1, 0);
    dp[0] = 1;
    for(auto x : cyc){
        if(x <= lim) c[x]++;
        else dp |= (dp << x);
    }

    vi dp2(N + 1);
    dp2[0] = 1;
    rep(i, 0, lim + 1){
        int w = i;
        int have = c[w];
        int pot = 1;
        while(pot <= have){
            int wi = w * pot;
            have -= pot;
            for(int j = n - wi; j >= 0; j--) dp2[j + wi] |= dp2[j];
            pot *= 2;
        }
        if(have){
            int wi = have * w;
            for(int j = n - wi; j >= 0; j--) dp2[j + wi] |= dp2[j];
        }
    }

    int mn = k + 1;
    rep(i, 0, k + 1){
        if(dp[i] && dp2[k - i]) mn = k;
    }

    cout << mn << " " << mx << "\n";
}
