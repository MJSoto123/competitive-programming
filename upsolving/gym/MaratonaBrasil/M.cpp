#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define int long long
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b; cin >> n >> a >> b;
    vi psum(n + 1);
    for(int i  = 0 ;i < n; i++){
        int x; cin >> x;
        psum[i + 1] = psum[i] + x;
    }
    int pos; cin >> pos;
    for(int i = 1; i <= n; i++){
        if(i == pos) continue;
        if(psum[i] + a >= psum[pos] + b){
            cout << "SIM\n";
            cout << i << '\n';
            return 0;
        }
    }
    cout << "NAO\n";
}