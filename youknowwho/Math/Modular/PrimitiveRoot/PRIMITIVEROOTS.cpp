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

const int N = 10000 + 5;
vi pi(N), dv(N);
void init(){
    for(int i = 0; i < N; i++) pi[i] = i;
    for(int i = 2; i < N; i++){
        if(pi[i] == i){
            for(int j = i; j < N; j += i){
                if(pi[j] == j) dv[j] = i;
                pi[j] -= pi[j] / i;
            }
        }
    }
}

int n;
int add(ll a, ll b){ return (a + b >= n ? a + b - n : a + b); }
int mul(ll a, ll b){ return (a * b) % n; }
int binpow(ll a, int exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

void solve(){
    vi fa;
    int m = pi[n];
    while(m != 1){
        if(fa.empty() || fa.back() != dv[m]) fa.emplace_back(dv[m]);
        m /= dv[m];
    }
    int ans = 1;
    for(int g = 1; g < n; g++){
        bool ok = true;
        for(auto x : fa){
            if(binpow(g, pi[n] / x) == 1){ ok = false; break; }
        }
        if(ok) ans = mul(ans, g);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++){
        cout << i << ":";
        cin >> n; 
        if(pi[n] != n - 1) cout << "NOTPRIME\n";
        else solve();
    }    
}