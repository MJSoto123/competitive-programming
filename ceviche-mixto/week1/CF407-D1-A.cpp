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

    int a, b; cin >> a >> b;
    int g = __gcd(a, b);

    pii nil(-1, -1);
    vector<vii> ans(1000 + 10);
    rep(i, 1, 1010){
        rep(j, 1, 1010){
            int sm = i * i + j * j;
            int sq = sqrt(sm);
            while((sq + 1) * (sq + 1) <= sm) sq++;
            if(sq * sq == sm && sq < 1010){
                ans[sq].emplace_back(i, j);
            }
        }
    }

    rep(dv, 1, g + 1){
        if(g % dv || ans[dv].empty()) continue;

        for(auto [x, y] : ans[dv]){
            if((b / dv) * y == (a / dv) * x) continue;
            cout << "YES\n";
            cout << "0 0\n";
            cout << (b / dv) * x << " " << (b / dv) * y << "\n";
            cout << - (a / dv) * y << " " << (a / dv) * x << "\n";
            return 0;
        }
    }

    cout << "NO\n";
}