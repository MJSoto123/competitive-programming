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

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = 0;
    int lst = -1;

    rep(i, 0, n){
        if(s[i] == '0') continue;
        if(lst == -1 || i > lst + k - 1) ans++;
        lst = i;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}