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

int low[20], high[20];
ll best[20][2][2][2];
int choose[20][2][2][2];

void init(){
    memset(best, -1, sizeof(best));
    memset(choose, -1, sizeof(choose));
}

ll dfs(int pos, int positive = 0, int smaller = 0, int bigger = 0){
    if(pos < 0){ return 1; }
    auto &memo = best[pos][positive][smaller][bigger];
    if(memo != -1) return memo;

    int mxd = smaller ? 9 : high[pos];
    int mnd = bigger  ? 0 : low[pos];
    
    ll mxprod = 0;
    rep(d, mnd, mxd + 1){
        int phere = positive || d;
        int shere = smaller || d < high[pos];
        int bhere = bigger || d > low[pos];

        ll anshere = dfs(pos - 1, phere, shere, bhere);
        if(phere) anshere *= d;

        if(mxprod < anshere){
            choose[pos][positive][smaller][bigger] = d;
            mxprod = anshere;
        }
    }
    return memo = mxprod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    string a, b; cin >> a >> b;
    int n = sz(b);
    while(sz(a) < n) a = "0" + a;

    rep(i, 0, n) low[i] = a[i] - '0';
    rep(i, 0, n) high[i] = b[i] - '0';

    reverse(low, low + n);
    reverse(high, high + n);
    ll ans = dfs(n - 1, 0, 0, 0);
    // cerr << ans << "\n";
    if(ans == 0){ cout << a << "\n"; return 0; }

    ll num = 0;
    {
        int id = n - 1, x = 0, y = 0, z = 0;
        while(id >= 0){
            int d = choose[id][x][y][z];
            num *= 10;
            num += d;
            x = x || d;
            y = y || d < high[id];
            z = z || d > low[id];
            id--;
            // cerr << "next " << id << " " << x << " " << y << " " << z << "\n";
        }
    }

    cout << num << "\n";
}