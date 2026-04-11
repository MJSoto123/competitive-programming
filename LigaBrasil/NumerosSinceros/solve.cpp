#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = unsigned long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    ll pos; cin >> pos;
    vi dig;
    while(pos){
        dig.emplace_back(pos % 9);
        pos /= 9;
    }

    rep(i, 0, sz(dig)){
        if(dig[i] <= 0 && i + 1 < sz(dig)){
          dig[i + 1]--;
          dig[i] += 10;
          dig[i]--;
        }
    }

    for(int i = sz(dig) - 1; i >= 0; i--){
        if(dig[i] > 0) cout << dig[i];
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}