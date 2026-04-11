#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
const int N = 1e5 + 10;
int X[N];
int Y[N];
int n;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
    auto get_dist = [&](int i , int j){
        return max(abs(X[i] - X[j]) , abs(Y[i] - Y[j]));
    };
    
    int prev = 0;
    ll low = -1e18, high = 1e18;
    ll sm = 0;
    for(int i = 0; i < n - 1; i++){
        if(i % 2 == 0){
            sm += get_dist(i, i + 1);
            high = min(high, sm);
        }else{
            sm -= get_dist(i, i + 1);
            low = max(low, sm);
        }
    }
    if (high - low < 2 || high - 1 < 1) cout << "-1\n";
    else cout <<  high  - 1 << '\n';
}