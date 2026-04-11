#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define int long long
using namespace ::std;
using ll = long long;
typedef vector<int>  vi;
typedef vector<ll>   vll;
typedef pair<int,int> pii;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int add(ll a, ll b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}
int res(ll a, ll b){
    a -= b;
    if(a < 0) a += MOD;
    return a;
}
int mult(ll a, ll b){
    return (a * b) % MOD;
}
ll binpow(int b , int e){
    ll res = 1;
    while(e){
        if(e & 1) res = mult(res , b);
        e >>= 1;
        b = mult(b , b);
    }
    return res;
}
int inverse(int a){
    return binpow(a , MOD - 2);
}

vector<pii> G[N];
int f[N];
int invF[N];
int D[N];
int n,m,k;
void prebuild(){
    f[1] = 1;
    for(int i = 2; i < N; i++) f[i] = mult(f[i - 1] , i);
    invF[N - 1] = inverse(f[N - 1]);
    invF[1] = 1;
    for(int i = N - 2; i >= 2; i--) invF[i] = mult(invF[i + 1] , i + 1);
}

int comb(int n, int k){
    if(k > n || k < 0)  return 0;
    if(k == n) return 1;
    if(k == 0) return 1;
    return mult(f[n] , mult(invF[n - k] , invF[k]));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prebuild();
    cin >> n >> m >> k;
    // for(int i = 0 ; i < 30 ; i++) cout << f[i] << ' '; cout << '\n';
    for(int i = 0; i < m ; i++){
        int a,b; cin >> a >> b;
        int w; cin >> w;
        // --a;--b;
        G[a].emplace_back(w,b);
        G[b].emplace_back(w,a);
    }

    for(int i = 0; i < n; i++) D[i] = -1;
    D[0] = 0;
    priority_queue<pii , vector<pii> , greater<pii>> Q;
    Q.emplace(0 , 0);
    while(Q.size()){
        auto [w , u] = Q.top(); Q.pop();
        if(w != D[u]) continue;
        for(auto e : G[u]){
            auto [dst , i] = e;
            if(D[i] == -1 || D[i] > D[u] + dst){
                D[i] = D[u] + dst;
                Q.emplace(D[i] , i);
            }
        }
    }

    vi dst;
    unordered_map<int , int> cnts;
    unordered_map<int , int> vis;
    for(int i = 1; i < n; i++){
        dst.emplace_back(D[i]);
        cnts[D[i]]++;
    }

    sort(dst.begin(), dst.end());
    ll acc = 0;
    for(auto [dd, cant] : cnts){
        int mays = dst.end() - upper_bound(all(dst) , dd);
        ll times = 0;
        for(int i = 1; i <= min(cant , k); i++)
            times = add(times , mult(comb(cant , i) , comb(mays , k - i)));
        acc = add(acc , mult(times , dd));
        vis[dd] = 1;
    }
    cout << mult(acc , inverse(comb(n - 1, k))) << '\n'; 
}