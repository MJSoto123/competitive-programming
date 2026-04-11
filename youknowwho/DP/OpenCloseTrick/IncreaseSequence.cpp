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

const int MOD = 1e9 + 7;
void add(int &a, int b){ a += b; if(a >= MOD) a -= MOD; }
int mul(ll a, ll b){ return (a * b) % MOD; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h; cin >> n >> h;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    int open = 0;
    int ways = 1;
    rep(it, 0, n){
        int need = (h - a[it]);
        if(need < 0 || abs(need - open) > 1){ cout << "0\n"; return 0; }
        need -= open;

        if(need == 1) open++;

        if(need == 0){
            ways = mul(ways, open + 1);
        }

        if(need == -1){
            ways = mul(ways, open);
            open --;
        }
    }

    if(open > 1) ways = 0;
    cout << ways << "\n";
}