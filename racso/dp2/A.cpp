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

const int MOD = 1e9 + 7;
void add(int &a, int b){ a += b; if(a >= MOD) a -= MOD; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    int h = 1;
    rep(i, 0, 1000){
        if((h + 1) * (h + 2) / 2 > a + b) break;
        h++;
    }

    vi dp(a + 1); dp[0] = 1;
    rep(i, 1, h + 1){
        for(int j = a; j >= 0; j--){
            if(j + i > a) continue;
            add(dp[j + i], dp[j]);
        }
    }

    int low = max(0, h * (h + 1) / 2 - b);
    int high = min(a, h * (h + 1) / 2);
    int ans = 0;
    rep(i, low, high + 1) add(ans, dp[i]);

    cout << ans << '\n';
}