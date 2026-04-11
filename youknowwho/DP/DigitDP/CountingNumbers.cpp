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

int high[20];
ll dp[20][11][2][2];

void init(){
    memset(dp, -1, sizeof(dp));
}

ll dfs(int pos, int last = 10, int positive = 0, int smaller = 0){
    if(pos < 0){ return 1; }
    if(dp[pos][last][positive][smaller] != -1) return dp[pos][last][positive][smaller];

    int mxd = 9;
    if(!smaller) mxd = high[pos];

    ll ret = 0;
    rep(d, 0, mxd + 1){
        if(d == last) continue;
        int positivehere = positive || d;
        int smallerhere = smaller || d < high[pos];

        if(!positivehere) ret += dfs(pos - 1, 10, positivehere, smallerhere);
        else ret += dfs(pos - 1, d, positivehere, smallerhere);
    }
    return dp[pos][last][positive][smaller] = ret;
}

ll get(ll a){
    int cnt = 0;
    while(a){
        high[cnt++] = a % 10;
        a /= 10;
    }
    init();
    return dfs(cnt - 1, 10, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b; cin >> a >> b;
    cout << get(b) - get(a - 1) << "\n";
}