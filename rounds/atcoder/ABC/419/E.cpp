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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, l; cin >> n >> m >> l;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi pre(n + 1);
    for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    
    ll bst = 1e18;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < m; j++){
            int now = 0;
            for(int k = 0; k < m; k++){
                
            }
        }
    }
}