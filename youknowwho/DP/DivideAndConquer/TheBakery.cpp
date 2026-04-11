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

const int N = 35000 + 5;
const int K = 50 + 5;
const int inf = 1e9;

int a[N];
int dp[K][N];
int frec[N];
int cost = 0, lnow = 0, rnow = 0;
void fix(int lneed, int rneed){
    // cerr << "fixing " << lneed << " " << rneed << "\n";
    while(rnow < rneed){
        rnow++;
        frec[a[rnow]]++;
        if(frec[a[rnow]] == 1) cost++;
    }

    while(lnow < lneed){
        if(frec[a[lnow]] == 1) cost--;
        frec[a[lnow]]--;
        lnow++;
    }

    while(lnow > lneed){
        lnow--;
        frec[a[lnow]]++;
        if(frec[a[lnow]] == 1) cost++;
    }

    while(rnow > rneed){
        if(frec[a[rnow]] == 1) cost--;
        frec[a[rnow]]--;
        rnow--;
    }
    // cerr << cost << "\n";
}

void go(int k, int l, int r, int optl, int optr){
    if(l > r) return;
    int mid = l + r >> 1;
    int best = 0;
    int opt = -1;

    for(int i = optl; i <= min(mid, optr); i++){
        fix(i, mid);
        int here = dp[k - 1][i - 1] + cost;
        if(here > best){
            best = here;
            opt = i;
        }
    }

    dp[k][mid] = best;
    go(k, l, mid - 1, optl, opt);
    go(k, mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k; 
    rep(i, 1, n + 1) cin >> a[i];
    
    k = min(n, k);
    rep(i, 1, k + 1) go(i, 1, n, 1, n);
    cout << dp[k][n] << "\n";
}